#ifndef Common_EventHandlers_IKeyReleaseEventHandler_H
#define Common_EventHandlers_IKeyReleaseEventHandler_H

#include "IKeyEventHandler.h"
class KeyReleaseEvent;
class IKeyReleaseEventHandler : IKeyEventHandler
{
    public:
        virtual void OnKeyReleaseEvent(KeyReleaseEvent* event) = 0;
};

#endif
