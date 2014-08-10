#ifndef Core_Controller_h
#define Core_Controller_h

#include <GLFW/glfw3.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <thread>

#include "GraphicsView.h"
#include "InputView.h"
#include "SoundView.h"
#include "ResourceView.h"
#include "GameStateManager.h"
#include "InitialState.h"
#include "ControllerPackage.h"

class Controller
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    Controller();
    
    /**
     * Starts the game. Initializes systems and starts updating them.
     */
    void Start();
    
private:
    // Private constructors to disallow access.
    Controller(Controller const &other);
    Controller operator=(Controller other);
    
    /**
     * The method that udpates all game logic.
     */
    void gameLoop();
    
    /**
     * The method that updates the GraphicsView.
     */
    void viewLoop();
    
    /**
     * How quickly the game logic updates. 1 over the number of updates per second.
     */
    const double UPDATE_RATE = (1 / 60.0) * 1000;
    
    /**
     * How quickly the graphics are updated. 1 over the number of frames per second.
     */
    const double FRAMERATE = (1 / 60.0) * 1000;

    /**
     * Boolean that represents whether the game should exit or not.
     */
    bool shouldExit;
    
    /**
     * Boolean that represents whether the views have been created or not.
     */
    bool viewsCreated;
};

#endif
