////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011 
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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


	img.SaveToFile(imgFileName);
}


int main(int, char**)
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");
    App.SetView(View(FloatRect(0, WINDOW_HEIGHT, WINDOW_WIDTH, 0)));
	ReversedSprite::setWindowsHeight((int) App.GetView().GetRect().GetHeight());

    // Limit to 60 FPS
    App.SetFramerateLimit(60);

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
        while (App.IsOpened())
        {
            sf::Event Event;
            // Static Events
            while(App.GetEvent(Event)) 
            {
                switch(Event.Type)
                {
                case Event::Closed : 
                    App.Close();
                    break;

                case(Event::Resized):
                    ReversedSprite::setWindowsHeight(Event.Size.Height);
                    break;

                case Event::KeyPressed : 
                    {
                        switch(Event.Key.Code)
                        {
                        case sf::Key::Escape :
                            App.Close();
                            break;
                        case sf::Key::F1 :
                            const sf::Image img = App.Capture();
                            writeCapture(img);
                            break;
                        }
                    }
                    break;
                }
            }

            App.Clear();

			// Clear color and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Update World
			w.update(App);
			//tiles.update(App);

            // Draw World
			w.render(App);
			//tiles.render(App);

            // Update the window
            App.Display();
        }
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }

    return EXIT_SUCCESS;
}