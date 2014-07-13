#include "Controller.h"
#include "StartState.h"

int main()
{
    Controller controller;
    controller.Start(new StartState());
    return 0;
}