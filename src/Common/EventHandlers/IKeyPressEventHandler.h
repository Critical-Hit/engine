#include "IKeyEventHandler.h"
#include "KeyPressEvent.h"
class IKeyPressEventHandler : IKeyEventHandler
{
    public:
        void OnKeyPressEvent(KeyPressEvent event);
};
