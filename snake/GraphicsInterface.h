#include "GraphicsManager.h"

class GraphicsInterface
{
public:
    GraphicsInterface()
    { }

    void Initialize(GraphicsManager* graphicsManager)
    {
        this->graphicsManager = graphicsManager;
    }

    void SetBackgroundColor(float backgroundColor)
    {
        this->graphicsManager->SetClearColor(backgroundColor);
    }

private:
    GraphicsManager* graphicsManager;
};