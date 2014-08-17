#ifndef Core_SoundManager_h
#define Core_SoundManager_h

#include <string>
#include "SoundView.h"

class SoundView;

/**
 * Manages all sound effects and music for the engine.
 *
 * Use: Load a sound or music file in the manager calling the load methods, then you can call play on it
 * using the returned ID. When the sound effect or music will not be used again call the corresponding unload method.
 */
class SoundManager
{
public:
    /**
     * Returns the instance of the SoundManager Singleton
     */
    static SoundManager* GetInstance();
    
    /**
     * Sets the view for this manager to use
     */
    void SetView(SoundView* soundView);
    
    /**
     * Returns whether or not this manager has a SoundView set
     */
    bool IsViewSet();
    
    /**
     * Loads the sound resource, returning the ID to use to manipulate it, or -1 if the load failed.
     */
    long LoadSound(std::string filename);
    
    /**
     * Loads the music resource, returning the ID to use to manipulate it, or -1 if the load failed.
     */
    long LoadMusic(std::string filename);
    
    /**
     * Unloads the sound mapped to the given id
     */
    void UnloadSound(long id);
    
    /**
     * Unloads the music mapped to the given id
     */
    void UnloadMusic(long id);
    
    /**
     * Plays the sound that the given ID is mapped to
     */
    void PlaySound(long id);
    
    /**
     * Plays the music the given ID is mapped to
     */
    void PlayMusic(long id);
    
    /**
     * Resumes the music the given ID is mapped to
     */
    void ResumeMusic(long id);
    
    /**
     * Pauses the music the given ID is mapped to
     */
    void PauseMusic(long id);
    
    
private:
    // Private constructors to disallow access.
    SoundManager();
    SoundManager(SoundManager const& other);
    SoundManager operator=(SoundManager other);
    
    /**
     * The ID to use for the next sound/music
     */
    long nextId;
    
    /**
     * The SoundView to use to play sounds/music
     */
    SoundView* soundView;
    
    /**
     * Static instance for Singleton
     */
    static SoundManager* instance;
    
    /**
     * Asserts that the SoundView has been set
     */
    void assertSoundView();
};

#endif
