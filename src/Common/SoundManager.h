#ifndef Core_SoundManager_h
#define Core_SoundManager_h

class SoundManager
{
public:
    /**
     * Default constructor that creates a new instance of a SoundManager.
     */
    SoundManager();

private:
    // Private constructors to disallow access.
    SoundManager(SoundManager const& other);
    SoundManager operator=(SoundManager other);
};

#endif
