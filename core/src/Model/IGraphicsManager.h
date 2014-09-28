#ifndef Core_IGraphicsManager_h
#define Core_IGraphicsManager_h

#include <memory>
#include "Color.h"
#include "Sprite.h"
#include "Camera.h"

namespace Model
{
    /**
    * Interface for the manager whic provides access to the graphical capabilities
    * of the engine.  Current functionality:
    *
    * Clear color: You may set a clear color via the engine's color class, or by
    * providing a float value for each channel.  These values must not be
    * zero.
    *
    * Sprite list: You may register and unregister sprites from the GraphicsManager.
    * Registered sprites are drawn according to their internal variables and can be
    * moved, resized, and recolored while they're registered, and this change will
    * be reflected in the view.
    */
    class IGraphicsManager
    {
    public:
        virtual void SetClearColor(Color clearColor) = 0;
        virtual void SetClearColor(float red, float blue, float green, float alpha) = 0;
        virtual void RegisterSprite(std::shared_ptr<Sprite> sprite) = 0;
        virtual void UnregisterSprite(std::shared_ptr<Sprite> sprite) = 0;
        virtual std::shared_ptr<Camera> GetCamera() = 0;
        virtual ~IGraphicsManager() {}
    };

    std::shared_ptr<IGraphicsManager> CreateIGraphicsManager();
}

#endif