#include "SoundView.h"

SoundView::SoundView()
{
    
}

void SoundView::Initialize()
{
    
}

void SoundView::Update(SoundManager* soundManager)
{
    if(!soundManager->IsViewSet())
    {
        soundManager->SetView(this);
    }
}

bool SoundView::LoadSound(long id, std::string filename)
{
    sf::SoundBuffer* buff = new sf::SoundBuffer();
    if(!buff->loadFromFile(filename))
        return false;
    sf::Sound* sound = new sf::Sound();
    sound->setBuffer(*buff);
    this->soundMap[id] = sound;
    return true;
}

bool SoundView::LoadMusic(long id, std::string filename)
{
    sf::Music* music = new sf::Music();
    if(!music->openFromFile(filename))
        return false;
    this->musicMap[id] = music;
    return true;
}

void SoundView::UnloadSound(long id)
{
    sf::Sound* sound = this->soundMap[id];
    this->soundMap.erase(id);
    delete sound->getBuffer();
    delete sound;
}

void SoundView::UnloadMusic(long id)
{
    sf::Music* music = this->musicMap[id];
    this->musicMap.erase(id);
    delete music;
}

void SoundView::PlaySound(long id)
{
    this->soundMap[id]->play();
}

void SoundView::PlayMusic(long id)
{
    this->musicMap[id]->play();
}

void SoundView::PauseMusic(long id)
{
    this->musicMap[id]->pause();
}

void SoundView::ResumeMusic(long id)
{
    this->musicMap[id]->play();
}