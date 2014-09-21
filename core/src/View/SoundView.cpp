#include "SoundView.h"

SoundView::SoundView()
{
    
}

void SoundView::Initialize()
{
    
}

void SoundView::Update(std::shared_ptr<SoundManager> soundManager)
{
    if(!soundManager->IsViewSet())
    {
        soundManager->SetView(this->shared_from_this());
    }
}

bool SoundView::LoadSound(long id, std::string filename)
{
    std::shared_ptr<sf::SoundBuffer> buff = make_shared<sf::SoundBuffer>();
    if(!buff->loadFromFile(filename))
    {
        return false;
    }
    std::shared_ptr<sf::Sound> sound = make_shared<sf::Sound>();
    sound->setBuffer(*buff);
    this->soundMap[id] = sound;
    this->soundBuffers[id] = buff;
    return true;
}

bool SoundView::LoadMusic(long id, std::string filename)
{
    std::shared_ptr<sf::Music> music = make_shared<sf::Music>();
    if(!music->openFromFile(filename))
    {
        return false;
    }
    this->musicMap[id] = music;
    return true;
}

void SoundView::UnloadSound(long id)
{
    this->soundMap.erase(id);
    this->soundBuffers.erase(id);
}

void SoundView::UnloadMusic(long id)
{
    this->musicMap.erase(id);
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
