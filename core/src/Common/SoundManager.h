#ifndef Core_SoundManager_h
#define Core_SoundManager_h

#include <string>
#include <memory>
#include "SoundView.h"

class SoundView;

class SoundManager
{
public:
    /**
     * Should NEVER be used. Only public because make_shared requires it.
     */
    SoundManager();

    /**
     * Returns the instance of the Singleton
     */
    static std::shared_ptr<SoundManager> GetInstance();
    
    /**
     * Sets the view for this manager to use
     */
    void SetView(std::shared_ptr<SoundView> soundView);
    
    /**
     * Returns whether or not this manager has a view set
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
    SoundManager(SoundManager const& other);
    SoundManager operator=(SoundManager other);
    
    /**
     * The ID to use for the next sound/music
     */
    long nextId;
    
    /**
     * The SoundView to use to play sounds/music
     */
    std::shared_ptr<SoundView> soundView;
    
    /**
     * Static instance for Singleton
     */
    static std::shared_ptr<SoundManager> instance;
};

#endif
