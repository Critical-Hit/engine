#include "Controller.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "IGraphicsManagerView.h"
#include "IGraphicsManager.h"
#include "ManagerConverters.h"

Controller::Controller()
{
    this->shouldExit = false;
    this->viewsCreated = false;
}

void Controller::Start()
{
    // Start the main game loop on a different thread.
    std::thread gameThread(&Controller::gameLoop, this);
    this->viewLoop();
    gameThread.join();
}

static long long getTimeInMilliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
}

void Controller::gameLoop()
{
    std::shared_ptr<GameStateManager> manager = std::make_shared<GameStateManager>();

    // Wait for views to be created
    while(!this->viewsCreated)
    { }

    manager->Initialize(std::make_shared<InitialState>());

    while(!this->shouldExit)
    {
        long long startTime = getTimeInMilliseconds();

        manager->Update();

        while((getTimeInMilliseconds() - startTime) <= Controller::UPDATE_RATE)
        { }
    }
}

void Controller::viewLoop()
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(640, 480), "Game Engine");
    window->setFramerateLimit(1 / this->FRAMERATE);

    GraphicsView graphicsView(window);
    graphicsView.Initialize();
    InputView inputView(window);
    inputView.Initialize();
    std::shared_ptr<SoundView> soundView = std::make_shared<SoundView>();
    soundView->Initialize();

    // Actual loop
    while(!this->shouldExit)
    {
        long long startTime = getTimeInMilliseconds();

        this->updateViews(&graphicsView, &inputView, &soundView);
        this->handleEvents(window, &inputView);

        if(!this->viewsCreated)
        {
            this->viewsCreated = true;
        }

        while((getTimeInMilliseconds() - startTime) <= Controller::FRAMERATE)
        { }
    }
}

void Controller::updateViews(GraphicsView* graphicsView, InputView* inputView, std::shared_ptr<SoundView>* soundView)
{
    std::weak_ptr<ControllerPackage> weakControllerPackage = ControllerPackage::GetActiveControllerPackage();
    std::shared_ptr<ControllerPackage> controllerPackage = weakControllerPackage.lock();
    
    if (weakControllerPackage.expired()) 
    {
        return;
    }

    graphicsView->Update(Rawr::ConvertGraphicsManagerForView(controllerPackage->GetGraphicsManager()));
    inputView->Update(controllerPackage->GetInputManager());
    (*soundView)->Update(controllerPackage->GetSoundManager());
}

void Controller::handleEvents(std::shared_ptr<sf::RenderWindow> window, InputView* inputView) {
    sf::Event event;
    while (window->pollEvent(event))
    {
        // Close program on Closed event
        if (event.type == sf::Event::Closed)
        {
            this->shouldExit = true;
            window->close();
        }

        // TODO: handle LostFocus, GainedFocus and Resized events

        // InputView handles other window events
        inputView->OnSfmlEvent(event);
    }
}

