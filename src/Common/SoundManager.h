#ifndef Core_SoundManager_h
#define Core_SoundManager_h

class SoundManager
{
public:
    /**
     * Default constructor that creates a new instance of a SoundManager.
     */
    SoundManager();
    
	/**
	* Sets all variables of this instance to match the other instance.
	*/
	void CopyFrom(SoundManager* other);

private:
    // Private constructors to disallow access.
    SoundManager(SoundManager const& other);
    SoundManager operator=(SoundManager other);
};

#endif
