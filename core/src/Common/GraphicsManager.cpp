#include <stdexcept>
#include <thread>
#include <chrono>
#include <memory>
#include <set>
#include <mutex>
#include "Color.h"
#include "Sprite.h"
#include "IGraphicsManagerView.h"
#include "IGraphicsManager.h"
#include "ManagerConverters.h"

class GraphicsManager: public View::IGraphicsManager, public Model::IGraphicsManager
{
public:
    /**
    * Default constructor that creates a new instance of a GraphicsManager.
    */
    GraphicsManager();

    /**
    * Destructor
    */
    ~GraphicsManager();

    /**
    * Gets the clear color
    */
    Color GetClearColor();

    /**
    * Sets the clear color
    */
    void SetClearColor(Color clearColor);

    /**
    * Sets the clear color
    */
    void SetClearColor(float red, float blue, float green, float alpha);

    /**
    * Registers a sprite to be drawn
    *
    * Throws an invalid_argument if the sprite was already registered.
    */
    void RegisterSprite(std::shared_ptr<Sprite> sprite);

    /**
    * Unregisters a sprite so it will no longer be drawn
    *
    * Throws an invalid_argument if the sprite wasn't registered.
    */
    void UnregisterSprite(std::shared_ptr<Sprite> sprite);

    /**
    * Obtains the number of registered sprite.
    */
    int GetSpriteCount();

    /**
    * Obtains a pointer to the camera.
    */
    std::shared_ptr<Camera> GetCamera();

    /**
    * Prepares to add all sprites with the AddSpriteToVCIBuffer method
    */
    void PrepareToAddSprites();

    /**
    * Adds the next sprite's vertex, color, and index information to the
    * given vertex buffer.
    *
    * Returns true if the sprite's data was successfully added; false if
    * there are no more sprites to be added or PrepareToAddSprites hasn't
    * been called.
    *
    * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 16 values for
    * each sprite (16 * GetSpriteCount()).
    */
    bool AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex);

private:
    // Private constructors to disallow access.
    GraphicsManager(GraphicsManager const &other);
    GraphicsManager operator=(GraphicsManager other);

    Color clearColor;
    std::shared_ptr<Camera> camera;
    std::set<std::shared_ptr<Sprite>> registeredSprites;
    std::mutex registeredSpritesMutex;
    std::set<std::shared_ptr<Sprite>>::iterator spriteIterator;
};

// GraphicsManager Implementation

GraphicsManager::GraphicsManager() : clearColor(0.0f, 0.0f, 0.0f, 1.0f)
{
    this->camera = std::make_shared<Camera>();
}

GraphicsManager::~GraphicsManager()
{
    
}

Color GraphicsManager::GetClearColor()
{
    return this->clearColor;
}

void GraphicsManager::SetClearColor(Color clearColor)
{
    this->clearColor = clearColor;
}

void GraphicsManager::SetClearColor(float red, float green, float blue, float alpha)
{
    this->clearColor = Color(red, green, blue, alpha);
}

void GraphicsManager::RegisterSprite(std::shared_ptr<Sprite> sprite)
{
    this->registeredSpritesMutex.lock();
    int registeredCountBeforeAdd = (int)this->registeredSprites.size();
    this->registeredSprites.insert(sprite);
    if ((registeredCountBeforeAdd + 1) != (int)this->registeredSprites.size())
    {
        throw new std::invalid_argument("A sprite was registered that was already registered.");
    }
    this->registeredSpritesMutex.unlock();
}

void GraphicsManager::UnregisterSprite(std::shared_ptr<Sprite> sprite)
{
    this->registeredSpritesMutex.lock();
    int registeredCountBeforeAdd = (int)this->registeredSprites.size();
    this->registeredSprites.erase(sprite);
    if ((registeredCountBeforeAdd - 1) != (int)this->registeredSprites.size())
    {
        throw new std::invalid_argument("A sprite was unregistered that wasn't registered.");
    }
    this->registeredSpritesMutex.unlock();
}

int GraphicsManager::GetSpriteCount()
{
    return (int)this->registeredSprites.size();
}

std::shared_ptr<Camera> GraphicsManager::GetCamera()
{
    return this->camera;
}

void GraphicsManager::PrepareToAddSprites()
{
    this->registeredSpritesMutex.lock();
    this->spriteIterator = this->registeredSprites.begin();
}

bool GraphicsManager::AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex)
{
    if (this->spriteIterator == this->registeredSprites.end())
    {
        this->registeredSpritesMutex.unlock();
        return false;
    }
    std::shared_ptr<Sprite> sprite = *(this->spriteIterator);
    sprite->PutGLVertexInfo(vertexBuffer); // 16 = 4 vertices * 4 coordinates
    sprite->PutGLColorInfo(colorBuffer); // 16 = 4 vertices * 4 channels
    sprite->PutGLIndexInfo(indexBuffer, dataStartIndex); // 6 = 2 triangles * 3 coordinates
    this->spriteIterator++;
    return true;
}

// IGraphicsManager Methods

std::shared_ptr<View::IGraphicsManager> View::CreateIGraphicsManager()
{
    return std::dynamic_pointer_cast<View::IGraphicsManager, GraphicsManager>(std::make_shared<GraphicsManager>());
}

std::shared_ptr<Model::IGraphicsManager> Model::CreateIGraphicsManager()
{
    return std::dynamic_pointer_cast<Model::IGraphicsManager, GraphicsManager>(std::make_shared<GraphicsManager>());
}

std::shared_ptr<View::IGraphicsManager> Rawr::ConvertGraphicsManagerForView(std::shared_ptr<Model::IGraphicsManager> manager)
{
    return std::dynamic_pointer_cast<View::IGraphicsManager, Model::IGraphicsManager>(manager);
}