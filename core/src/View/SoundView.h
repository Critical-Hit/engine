#ifndef Core_SoundView_h
#define Core_SoundView_h

#include "ControllerPackage.h"

/**
 * Provides a full set of logic for achieving sound effects.
 * 
 * Currently does nothing.
 */
class SoundView
{
public:
    /**
     * Constructs a SoundView given a controller package.
     */
    SoundView();
    
    /**
     * Initializes the SoundView.
     */
    void Initialize();
    
    /**
     * Updates the SoundView.
     */
    void Update(SoundManager* soundManager);
    
private:
    // Private constructors to disallow access.
    SoundView(SoundView const &other);
    SoundView operator=(SoundView other);
};

#endif
