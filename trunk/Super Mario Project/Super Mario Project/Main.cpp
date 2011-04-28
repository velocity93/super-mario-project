////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "World.hpp"
#include <SFML\Graphics.hpp>

using namespace SuperMarioProject;
using namespace sf;

int main(int argc, char* argv[])
{
	World* w = new World();
	argc;
	argv;

	// Create the main window
     sf::RenderWindow App(sf::VideoMode(800, 600), "Super Mario project");

	 // Start the game loop
     while (App.IsOpened())
     {
         w->getKeystate()->update(App);		 
 
         // Clear screen
         App.Clear();

		 // Update World
		 w->update();
 
         // Draw the sprite
		 w->render(App);
 
         // Update the window
         App.Display();
     }

	 delete w;
 
     return EXIT_SUCCESS;
}