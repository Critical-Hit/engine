#ifndef Core_SoundManager_h
#define Core_SoundManager_h

#include <string>
#include <unordered_map>
#include "SoundView.h"

class SoundView;

#define KEY_TYPE long

class SoundManager
{
public:
    static void SetView(SoundView* soundView);
    static KEY_TYPE LoadSound(std::string filename);
    static KEY_TYPE LoadMusic(std::string filename);
    static void PlaySound(KEY_TYPE id);
    static void PlayMusic(KEY_TYPE id);
    static void PauseMusic(KEY_TYPE id);
    
    
private:
    // Private constructors to disallow access.
    SoundManager();
    SoundManager(SoundManager const& other);
    SoundManager operator=(SoundManager other);
    
    SoundView* soundView;
    static SoundManager* instance;
    static SoundManager* getInstance();
    std::unordered_map<KEY_TYPE, bool>* soundLoaded;
    std::unordered_map<KEY_TYPE, bool>* musicLoaded;
};

#endif
