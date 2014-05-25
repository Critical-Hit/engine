#include "IKeyEventHandler.h"
#include "KeyReleaseEvent.h"
class IKeyReleaseEventHandler : IKeyEventHandler
{
    public:
        void OnKeyReleaseEvent(KeyReleaseEvent event);
};
