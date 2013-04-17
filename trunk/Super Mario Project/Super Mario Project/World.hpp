////////////////////////////////////////////////////////////////////////
// World.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_WORLD
#define HPP_WORLD

#include "InputState.hpp"
#include <SFML/Config.hpp>
#include <string>

#define WINDOW_WIDTH							800
#define WINDOW_HEIGHT							600
#define SCROLLING_AV                            (float)0.5
#define SCROLLING_AR                            (float)0.2
#define SCROLLING_HAUT                          (float)0.5
#define SCROLLING_BAS                           (float)0.2

// forward declaration
namespace sf
{
	class View;
	class RenderWindow;
}

namespace smp
{
	// forward declaration
	class QuadTree;
	class Perso;
	class Level;

    class World
    {
    public:
		World(const sf::Window* window);

		Level* getLevel();

		/* Methods */
		void addLevelName(const std::string &levelName);

		void update(sf::RenderWindow& app, sf::View* view);
		void render(sf::RenderWindow& app);

		float getElapsedTime();
		void loadWorld();

        virtual ~World();
		
    private:
		std::vector<std::string> _levelNames;
		std::vector<Perso*> _persos;
		Level* _level;
		InputState* _inputState;
		sf::Vector2i _windowSize;
		sf::Clock _clock;
		float _fpsTime;
		float _actualTime;
		float _previousTime;
		float _elapsedTime;
		float _previousElapsedTime;
		float _fps;
		float _nbFramesCalculated;

		QuadTree* _levelTree;

		/* Update data time in world */
		void updateTime();
    };
} // namespace

#endif // HPP_WORLD
