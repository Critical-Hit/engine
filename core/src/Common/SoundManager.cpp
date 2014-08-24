#include "SoundManager.h"
#include <assert.h>

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    this->nextId = 0;
}

SoundManager* SoundManager::GetInstance()
{
    if(SoundManager::instance == nullptr)
    {
        SoundManager::instance = new SoundManager();
    }
    return SoundManager::instance;
}

void SoundManager::SetView(SoundView* soundView)
{
    this->soundView = soundView;
}

bool SoundManager::IsViewSet()
{
    return this->soundView != nullptr;
}

long SoundManager::LoadSound(std::string filename)
{
    assert(this->soundView != nullptr && "Loaded Sound before view set");
    
    long id = nextId++;
    if(!this->soundView->LoadSound(id, filename))
    {
        return -1;
    }
    return id;
}

long SoundManager::LoadMusic(std::string filename)
{
    assert(this->soundView != nullptr && "Loaded Music before view set");
    
    long id = nextId++;
    if(!this->soundView->LoadMusic(id, filename))
    {
        return -1;
    }
    return id;
}

void SoundManager::UnloadSound(long id)
{
    assert(this->soundView != nullptr && "Unload Sound before view set");
    
    this->soundView->UnloadSound(id);
}

void SoundManager::UnloadMusic(long id)
{
    assert(this->soundView != nullptr && "Unload Music before view set");
    
    this->soundView->UnloadMusic(id);
}

void SoundManager::PlaySound(long id)
{
    assert(this->soundView != nullptr && "Played Sound before view set");
    
    this->soundView->PlaySound(id);
}

void SoundManager::PlayMusic(long id)
{
    assert(this->soundView != nullptr && "Played Music before view set");
    
    this->soundView->PlayMusic(id);
}

void SoundManager::PauseMusic(long id)
{
    assert(this->soundView != nullptr && "Paused Music before view set");
    
    this->soundView->PauseMusic(id);
}

void SoundManager::ResumeMusic(long id)
{
    assert(this->soundView != nullptr && "Resumed Music before view set");
    
    this->soundView->ResumeMusic(id);
}