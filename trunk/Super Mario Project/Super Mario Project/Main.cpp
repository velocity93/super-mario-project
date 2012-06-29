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
#include "ReversedSprite.hpp"

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
    App.setView(View(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)));
	ReversedSprite::setWindowsHeight((int) App.getView().getSize().y);
	
    // Limit to 60 FPS
    App.setFramerateLimit(60);

    // Create world
    World w(&App);
	/*Level lvl;
    lvl.loadLevel("levels/smb.xml");
    Perso perso = Perso("fire_mario", Vector2f(0, 0));
    InputState input = InputState(&App);*/
	//Tileset tiles("speciaux/incassables/[Q]/overworld");
	//tiles.addBlock(0, EMPTY);
	//tiles.getBlocks()[0]->addNewBlockOccurrence(tiles.getBlocks()[0]);
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

                case(Event::Resized):
                    ReversedSprite::setWindowsHeight(Event.size.height);
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
			w.update(App);
			//tiles.update(App);

            // Draw World
			w.render(App);
			//tiles.render(App);

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