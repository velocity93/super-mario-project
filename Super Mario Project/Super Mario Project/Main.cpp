////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "World.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

using namespace SuperMarioProject;
using namespace sf;

int main(int argc, char* argv[])
{
	World* w = new World();
	//Background background = Background("textures\\backgrounds\\skyBlueHills");
	//Background background2 = Background("textures\\backgrounds\\blueHills");
	argc;
	argv;

	// Create the main window
	sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");

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

			case Event::KeyPressed : 
				{
					switch(Event.Key.Code)
					{
					case Key::Escape :
						App.Close();
						break;
					}
				}
				break;
			}
		}

		// Update World
		//w->update(App);
		//background.update(App);
		//background2.update(App);

		// Draw World
		//w->render(App);
		//background.render(App);
		//background2.render(App);

		// Update the window
		App.Display();
	}

	delete w;

	return EXIT_SUCCESS;
}