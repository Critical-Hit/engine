import os

assets_path = "game/assets"
texture_id_path = "core/src/Common/TextureId.h"
texture_id_utils_path = "core/src/View/TextureIdUtils.h"

# Returns all the names of the png files in assets
def get_texture_names(returnFullPath):
    to_return = []
    fileList = []
    for root, subFolders, files in os.walk(assets_path):
        for file in files:
            if returnFullPath:
                fileList.append(os.path.join(root,file))
            else:
                fileList.append(file)

    for file in fileList:
        # Exclude any non-png files
        pieces = os.path.splitext(file)
        if pieces[1] == ".png":
            if returnFullPath:
                to_return.append(file)
            else:
                to_return.append(pieces[0])
    return to_return

# Returns the inner section of texture_id_contents
def get_id_inner_code():
    to_return = ""
    for name in get_texture_names(False):
        to_return += "        " + name + ",\n"
    return to_return

#returns the inner section of texture_id_utils_contents
def get_utils_inner_code():
    to_return = ""
    names = get_texture_names(False)
    paths = get_texture_names(True)
    for i in range(0, len(names)):
        to_return += ("                case TextureId::" + names[i] + ":" +
                      "\n                    return \"" + paths[i].replace('\\', '/') + "\";\n")
    return to_return

# Template for the TextureId class
texture_id_contents = """#ifndef Core_TextureId_h
#define Core_TextureId_h

namespace Common
{
    enum class TextureId
    {
""" + get_id_inner_code() + """    };
}

#endif"""

# Template for the TextureIdUtils class
texture_id_utils_contents = """#ifndef Core_TextureIdUtils_h
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
""" + get_utils_inner_code() + """
                default:
                    assert(false && "Unknown texture id");
            }
        }
    }
}

#endif"""

def main():
    # Write the contents of both files
    texture_id_file = open(texture_id_path, 'w')
    texture_id_file.write(texture_id_contents)

    texture_id_utils_file = open(texture_id_utils_path, 'w')
    texture_id_utils_file.write(texture_id_utils_contents)
    print("Done")

if __name__ == "__main__":
    main()
