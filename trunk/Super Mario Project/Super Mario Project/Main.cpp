////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011 
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <sstream>
#include "World.hpp"
#include "Block.hpp"

using namespace SuperMarioProject;
using namespace Rendering;
using namespace sf;

void writeCapture(const sf::Image& img)
{
	/* Building fileName */
	string prefix = "capture";
	int id = 0;
	std::ostringstream out;
	out << id;
	string fileName = prefix + out.str();
	string imgFileName = fileName + ".png";

	bool loopingAgain = true;

	while(loopingAgain)
	{
		ifstream file(imgFileName.c_str());
		if(!file)
		{
			loopingAgain = false;
		}
		else
		{
			std::ostringstream out2;
			out2 << ++id;
			fileName = prefix + out2.str();
			imgFileName = fileName + ".png";
		}
	}


	img.saveToFile(imgFileName);
}


int main(int, char**)
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");

	sf::View view = View(FloatRect(0, WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT));

    // Limit to 60 FPS
    App.setFramerateLimit(60);

    // Create world
    World w(&App);
	
    try
    {
        // Start the game loop
		while (App.isOpen())
        {
            sf::Event Event;
            // Static Events
            while(App.pollEvent(Event)) 
            {
				switch(Event.type)
                {
                case Event::Closed : 
                    App.close();
                    break;

                case Event::KeyPressed : 
                    {
                        switch(Event.key.code)
                        {
                        case sf::Keyboard::Escape :
                            App.close();
                            break;
                        case sf::Keyboard::F1 :
                            const sf::Image img = App.capture();
                            writeCapture(img);
                            break;
                        }
                    }
                    break;
                }
            }
			
            App.clear();

			// Clear color and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
			glLoadIdentity();
			gluOrtho2D(0.0f, (float)WINDOW_WIDTH, 0.0f, (float)WINDOW_HEIGHT); // set origin to bottom left corner
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

            // Update World
			w.update(App, &view);

			App.setView(view);

            // Draw World
			w.render(App);

            // Update the window
            App.display();
        }
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }

    return EXIT_SUCCESS;
}