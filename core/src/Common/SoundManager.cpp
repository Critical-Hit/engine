#include "SoundManager.h"
#include <assert.h>

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    this->soundLoaded = new std::unordered_map<KEY_TYPE, bool>();
    this->musicLoaded = new std::unordered_map<KEY_TYPE, bool>();
}

void SoundManager::SetView(SoundView* soundView)
{
    SoundManager::getInstance()->soundView = soundView;
}

SoundManager* SoundManager::getInstance()
{
    if(SoundManager::instance == nullptr)
    {
        SoundManager::instance = new SoundManager();
    }
    return SoundManager::instance;
}

KEY_TYPE SoundManager::LoadSound(std::string filename)
{
    if(SoundManager::getInstance()->soundView == nullptr)
        assert(false && "Loaded Sound before view set");
    SoundManager::getInstance()->soundView->LoadSound(0, filename);
    return 0;
}

KEY_TYPE SoundManager::LoadMusic(std::string filename)
{
    if(SoundManager::getInstance()->soundView == nullptr)
        assert(false && "Loaded Sound before view set");
    SoundManager::getInstance()->soundView->LoadMusic(0, filename);
    return 0;
}

void SoundManager::PlaySound(KEY_TYPE id)
{
    if(SoundManager::getInstance()->soundView == nullptr)
        assert(false && "Loaded Sound before view set");
        SoundManager::getInstance()->soundView->PlaySound(id);
}

void SoundManager::PlayMusic(KEY_TYPE id)
{
    if(SoundManager::getInstance()->soundView == nullptr)
        assert(false && "Loaded Sound before view set");
    SoundManager::getInstance()->soundView->PlayMusic(id);
}

void SoundManager::PauseMusic(KEY_TYPE id)
{
    if(SoundManager::getInstance()->soundView == nullptr)
        assert(false && "Loaded Sound before view set");
    SoundManager::getInstance()->soundView->PauseMusic(id);
}