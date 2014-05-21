#ifndef Core_InitialState_h
#define Core_InitialState_h

#include "GameState.h"

class InitialState : public GameState
{
public:
    InitialState();
    virtual void Initialize(GameStateManager* manager);
    virtual float Update();
    virtual void Pause();
    virtual void Resume();
    virtual void Destroy();
    
private:
    int sign;
    float increment;
    float colorValue;
};

#endif
