////////////////////////////////////////////////////////////////////////
// Main.cpp
// Super Mario Project
// Copyright (C) 2011 
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "World.hpp"
#include "ReversedSprite.hpp"


using namespace SuperMarioProject;
using namespace Rendering;
using namespace sf;

int main(int, char**)
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario project");
    App.SetView(View(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)));

    // Limit to 60 FPS
    App.SetFramerateLimit(60);

    // Create world
    World w(&App);
    Level lvl;
    lvl.loadLevel("levels/smb.xml");
    Perso perso = Perso("fire_mario", Vector2f(0, 0));
    InputState input = InputState(&App);
    ReversedSprite::setWindowsHeight((int) App.GetView().GetRect().GetHeight());

	/*Block bloc = Block("speciaux\\incassables\\liquids\\poison");
	bloc.addNewBlockOccurrence(0);*/


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
                            img.SaveToFile("test.png");
                            break;
                        }
                    }
                    break;
                }
            }

            App.Clear();

            // Update World
            //background.update(App);
            perso.updatePerso(App, input);

            // Draw World
            //background.render(App);
            perso.render(App);

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