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

#define WINDOW_WIDTH		1024
#define WINDOW_HEIGHT		768

using namespace SuperMarioProject;
using namespace sf;

int main(int argc, char* argv[])
{
	World* w = new World();
	Background background = Background("Edge");
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
		background.update(w->getElapsedTime());

		// Draw World
		//w->render(App);
		background.render(App, Screen());

		// Update the window
		App.Display();
	}

	delete w;

	return EXIT_SUCCESS;
}