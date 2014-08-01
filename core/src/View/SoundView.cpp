#include "SoundView.h"

SoundView::SoundView()
{
    
}

void SoundView::Initialize()
{
    SoundManager::SetView(this);
}

bool SoundView::LoadSound(KEY_TYPE id, std::string filename)
{
    sf::SoundBuffer* buff = new sf::SoundBuffer();
    if(!buff->loadFromFile(filename))
        return false;
    sf::Sound* sound = new sf::Sound();
    sound->setBuffer(*buff);
    this->soundMap[id] = sound;
    return true;
}

bool SoundView::LoadMusic(KEY_TYPE id, std::string filename)
{
    sf::Music* music = new sf::Music();
    if(!music->openFromFile(filename))
        return false;
    this->musicMap[id] = music;
    return true;
}

void SoundView::PlaySound(KEY_TYPE id)
{
    this->soundMap[id]->play();
}

void SoundView::PlayMusic(KEY_TYPE id)
{
    this->musicMap[id]->play();
}

void SoundView::PauseMusic(KEY_TYPE id)
{
    this->musicMap[id]->pause();
}