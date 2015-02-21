#ifndef Core_TextureIdUtils_h
#define Core_TextureIdUtils_h

#include <string>
#include <assert.h>
#include "TextureId.h"

using namespace Common;

namespace View
{
    namespace TextureIdUtils
    {
        std::string GetTexturePath(TextureId texture)
        {
            switch (texture)
            {
                case TextureId::Test:
                    return "game/assets/textures/Test.png";

                default:
                    assert(false && "Unknown texture id");
            }
        }
    }
}

#endif