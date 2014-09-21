#include "SoundManager.h"
#include <assert.h>

std::shared_ptr<SoundManager> SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    this->nextId = 0;
}

std::shared_ptr<SoundManager> SoundManager::GetInstance()
{
    if(SoundManager::instance == nullptr)
    {
        SoundManager::instance = std::make_shared<SoundManager>();
    }
    return SoundManager::instance;
}

void SoundManager::SetView(std::shared_ptr<SoundView> soundView)
{
    this->soundView = soundView;
}

bool SoundManager::IsViewSet()
{
    return this->soundView != nullptr;
}

long SoundManager::LoadSound(std::string filename)
{
    this->assertSoundView();
    
    long id = nextId++;
    if(!this->soundView->LoadSound(id, filename))
    {
        return -1;
    }
    return id;
}

long SoundManager::LoadMusic(std::string filename)
{
    this->assertSoundView();
    
    long id = nextId++;
    if(!this->soundView->LoadMusic(id, filename))
    {
        return -1;
    }
    return id;
}

void SoundManager::UnloadSound(long id)
{
    this->assertSoundView();
    
    this->soundView->UnloadSound(id);
}

void SoundManager::UnloadMusic(long id)
{
    this->assertSoundView();
    
    this->soundView->UnloadMusic(id);
}

void SoundManager::PlaySound(long id)
{
    this->assertSoundView();
    
    this->soundView->PlaySound(id);
}

void SoundManager::PlayMusic(long id)
{
    this->assertSoundView();
    
    this->soundView->PlayMusic(id);
}

void SoundManager::PauseMusic(long id)
{
    this->assertSoundView();
    
    this->soundView->PauseMusic(id);
}

void SoundManager::ResumeMusic(long id)
{
    this->assertSoundView();
    
    this->soundView->ResumeMusic(id);
}

void SoundManager::assertSoundView()
{
    assert(this->soundView != nullptr && "SoundManager method called before it's SoundView was set.");
}
