#ifndef Core_SoundView_h
#define Core_SoundView_h

#include "ControllerPackage.h"
#include "SoundManager.h"
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>

class SoundManager;

/**
 * Provides a full set of logic for achieving sound effects.
 */
class SoundView : public std::enable_shared_from_this<SoundView>
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
     * Updates this SoundView with the given SoundManager
     */
    void Update(std::shared_ptr<SoundManager> soundManager);
    
    /**
     * Loads and stores a sound from the given filename and the given ID
     */
    bool LoadSound(long id, std::string filename);
    
    /**
     * Loads and stores a music from the given filename and the given ID
     */
    bool LoadMusic(long id, std::string filename);
    
    /**
     * Unloads the sound mapped to the given id
     */
    void UnloadSound(long id);
    
    /**
     * Unloads the music mapped to the given id
     */
    void UnloadMusic(long id);
    
    /**
     * Plays the sound mapped to the given ID
     */
    void PlaySound(long id);
    
    /**
     * Plays the music mapped to the given ID
     */
    void PlayMusic(long id);
    
    /**
     * Pauses the music mapped to the given ID
     */
    void PauseMusic(long id);
    
    /**
     * Resumes the music mapped to the given ID
     */
    void ResumeMusic(long id);
    
private:
    // Private constructors to disallow access.
    SoundView(SoundView const &other);
    SoundView operator=(SoundView other);
    
    /**
     * The map from ID to Music objects
     */
    std::unordered_map<long, std::shared_ptr<sf::Music>> musicMap;
    
    /**
     * The map from ID to Sound objects
     */
    std::unordered_map<long, std::shared_ptr<sf::Sound>> soundMap;
};

#endif
