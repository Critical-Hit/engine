#ifndef Core_SoundView_h
#define Core_SoundView_h

#include "ControllerPackage.h"
#include "SoundManager.h"
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <string>

#define KEY_TYPE long

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
    
    bool LoadSound(KEY_TYPE id, std::string filename);
    bool LoadMusic(KEY_TYPE id, std::string filename);
    void PlaySound(KEY_TYPE id);
    void PlayMusic(KEY_TYPE id);
    void PauseMusic(KEY_TYPE id);
    
private:
    // Private constructors to disallow access.
    SoundView(SoundView const &other);
    SoundView operator=(SoundView other);
    
    std::unordered_map<KEY_TYPE, sf::Music*> musicMap;
    std::unordered_map<KEY_TYPE, sf::Sound*> soundMap;
};

#endif
