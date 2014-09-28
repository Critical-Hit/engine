#ifndef Core_ManagerConverters_h
#define Core_ManagerConverters_h

#include <memory>
#include "IGraphicsManagerView.h"
#include "IGraphicsManager.h"

namespace Rawr
{
    std::shared_ptr<View::IGraphicsManager> ConvertGraphicsManagerForView(std::shared_ptr<Model::IGraphicsManager> manager);
}

#endif