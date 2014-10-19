#ifndef Core_ManagerCasts_h
#define Core_ManagerCasts_h

#include <memory>
#include "IInputManagerView.h"
#include "IInputManager.h"

namespace ManagerCast
{
    std::shared_ptr<View::IInputManager> CastInputManagerToInputManagerView(std::shared_ptr<Model::IInputManager> manager);
}

#endif
