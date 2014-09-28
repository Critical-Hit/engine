#ifndef Core_IGraphicsManagerView_h
#define Core_IGraphicsManagerView_h

#include <memory>
#include "Color.h"
#include "Camera.h"

namespace View
{
    class IGraphicsManager
    {
    public:
        virtual Color GetClearColor() = 0;
        virtual int GetSpriteCount() = 0;
        virtual std::shared_ptr<Camera> GetCamera() = 0;
        virtual void PrepareToAddSprites() = 0;
        virtual bool AddSpriteToVCIBuffer(float* vertexBuffer, float* colorbuffer, unsigned short* indexBuffer, unsigned short dataStartIndex) = 0;
        virtual ~IGraphicsManager() {};
    };

    std::shared_ptr<View::IGraphicsManager> CreateIGraphicsManager();
}

#endif