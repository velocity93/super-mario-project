////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011 
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "World.hpp"
#include "Block.hpp"
#include "Exceptions.hpp"
#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <fstream>
#include <sstream>

using namespace smp;
using namespace sf;
using namespace std;

void writeCapture(const sf::Image& img)
{
	/* Building fileName */
	std::string prefix = "capture";
	int id = 0;
	std::stringstream out;
	out << id;
	std::string fileName = prefix + out.str();
	std::string imgFileName = fileName + ".png";

	bool loopingAgain = true;

	while(loopingAgain)
	{
		std::ifstream file(imgFileName.c_str());
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

/* Trick to have origin at bottom left even if using SFML */ 
void InitializeTextureMatrice(RenderWindow& App)
{
	/* Bidouille pour mettre l'origine en bas à gauche !!! \o/
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.set(x,y);

	App.draw(sprite);
	glMatrixMode(GL_TEXTURE);
	glScalef(1.f, -1.f, 1.f);
	*/

	/* Save the default texture in case of texture loading error */
	smp::Texture* texture = ResourceManager::getTexture("textures/default");

	sf::Sprite sprite;
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, 0);

	App.draw(sprite);
	glMatrixMode(GL_TEXTURE);
	glScalef(1.f, -1.f, 1.f);
}

// P1 TODO: check monster/character collision								- 50 %
// P1 TODO: check character transformations									- 75 %
// P1 TODO : check collisions between other entities than Perso
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
// P6 TODO: use libxml++ instead of libxml									- libxml++ not compatible with Win32 system for the moment
// P6 TODO: add a way to pause the game
// P6 TODO: attaque rodéo													- Sprites have been downloaded
// P6 TODO: "twisted" jump
// P7 TODO: use only .xml files instead of .item . perso...					- OK
// P8 TODO: add a boss
// P8 TODO: levels with auto scrolling, based on key positions and timers
// P8 TODO: other types of monsters (paratroopas...)
// P8 TODO: allow mario to slide on slope blocks
// P8 TODO: implement plant growing from [?] block
// P8 TODO: Test classes for differente animations
// P9 TODO: Think to transform SMP into a dll loaded by editor
// P9 TODO: particles generator
// P9 TODO: integration of resources into the executable file?
// P9 TODO: update the project webpage (images and description)

int main(int, char**)
{

    // Create the main window
    sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");

	sf::View view = View(FloatRect(0, WINDOW_HEIGHT, WINDOW_WIDTH, -WINDOW_HEIGHT));

    // Limit to 60 FPS
    App.setFramerateLimit(60);

	InitializeTextureMatrice(App);
	
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

                        break;
                    }
                }
            }
			
            App.clear();

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
