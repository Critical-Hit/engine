
//  main.cpp
//

#include <iostream>
#include <string>

#include <unordered_set>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <GL/glew.h>

using namespace std;

int main(int argc, const char * argv[])
{
	sf::Window window(sf::VideoMode(640, 480, 32), "SFML Window with OpenGL");
	GLenum err = glewInit();
	if (err != GLEW_OK)
		printf("There was an error initializing glew.");
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	getchar();
	return 0;
}

