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

#include "Perso.hpp"
#include "Level.hpp"
#include "InputState.hpp"
#include <SFML/Config.hpp>
#include <string>
#include <fstream>
#include <iostream>

#define WINDOW_WIDTH							800
#define WINDOW_HEIGHT							600
#define SCROLLING_AV                            (float)0.5
#define SCROLLING_AR                            (float)0.2
#define SCROLLING_HAUT                          (float)0.5
#define SCROLLING_BAS                           (float)0.2


using namespace Collisions;

namespace SuperMarioProject
{
    class World
    {
    public:
		World(const Window* window);

		Level* getLevel();

		/* Methods */
		void addLevelName(string levelName);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

		float getElapsedTime();
		void loadWorld();

        virtual ~World();
		
    private:
		vector<string> _levelNames;
		vector<Perso*> _persos;
		Level* _level;
		InputState _inputState;
		Vector2i _windowSize;
		Clock _clock;
		float _fpsTime;
		float _actualTime;
		float _previousTime;
		float _elapsedTime;
		float _previousElapsedTime;
		float _fps;
		float _nbFramesCalculated;

		/* Update data time in world */
		void updateTime();
    };
} // namespace

#endif // HPP_WORLD
