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
#include "Exceptions.hpp"

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

// P1 TODO: check monster/character collision								- Bof pour l'instant
// P1 TODO: check character transformations									- En cours, reste encore probleme de postionnement
// P2 TODO: implement background layers
// P2 TODO: check fireballs
// P3 TODO: check if mario properly handles shells
// P4 TODO: check behavior of pipes
// P4 TODO: check collision with slope blocks
// P4 TODO: check characters' death
// P4 TODO: check monsters and projectiles' death
// P4 TODO: check if mario can still climb on plants
// P4 TODO: a [?] should move up when hit from behind by mario
// P4 TODO: an item should jump when on a [?] block hit by mario
// P4 TODO: an enemy should die when on a [?] block hit by mario
// P4 TODO: implement [?] coins dispensers
// P4 TODO: breakable blocks should break into multiple particles
// P4 TODO: check backgrounds animation										- OK
// P4 TODO: add ice mario
// P5 TODO: finalize the level
// P6 TODO: use libxml++ instead of libxml
// P6 TODO: add a way to pause the game
// P6 TODO: attaque rodéo
// P6 TODO: "twisted" jump
// P7 TODO: use only .xml files instead of .item . perso...
// P8 TODO: add a boss
// P8 TODO: levels with auto scrolling, based on key positions and timers
// P8 TODO: other types of monsters (paratroopas...)
// P8 TODO: allow mario to slide on slope blocks
// P8 TODO: implement plant growing from [?] block
// P9 TODO: particles generator
// P9 TODO: integration of resources into the executable file?
// P9 TODO: update the project webpage (images and description)


int main(int, char**)
{

    // Create the main window
    sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");

	sf::View view = View(FloatRect(0, WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT));

    // Limit to 60 FPS
    App.setFramerateLimit(60);

    try
    {
        // Create world
        World w(&App);

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
    catch(FileException &fe)
    {
        cout << fe.what() << endl;
        return EXIT_FAILURE;
    }
    catch(exception &e)
    {
        cout << "Random exception occured: " << e.what() << endl;
        return EXIT_FAILURE;
    }
    catch(...)
    {
        cout << "Oh boy, everything's seriously fucked up in there!" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}