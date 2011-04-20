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
	argc;
	argv;

	World* w = new World();

	// Create the main window
     sf::RenderWindow App(sf::VideoMode(800, 600), "Super Mario project");

	 // Start the game loop
     while (App.IsOpened())
     {
         // Process events
         //sf::Event Event;
         //while (App.GetEvent(Event))
         //{
         //    // Close window : exit
         //    if (Event.Type == sf::Event::Closed)
         //        App.Close();
         //}

		 w->getKeystate().update(App);		 
 
         // Clear screen
         App.Clear();
 
         // Draw the sprite
         //App.Draw(Sprite);
 
         // Draw the string
         //App.Draw(Text);
 
         // Update the window
         App.Display();
     }
 
     return EXIT_SUCCESS;


	return 0;
}