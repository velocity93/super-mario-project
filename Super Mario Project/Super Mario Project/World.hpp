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

#include "Screen.hpp"
#include "Perso.hpp"
#include "Level.hpp"
#include "Keystate.hpp"
#include "Coord.hpp"
#include <string>
#include <SFML\Config.hpp>

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
		World() : _keystate(Keystate()), _levelNames(vector<string>()), _persos(vector<Perso>()),
			_screen(Screen()), _windowSize(Coord<int>()), _fpsTime(0), _actualTime(0), _previousTime(0), 
			_elapsedTime(0), _previousElapsedTime(0), _fps(0), _nbFramesCalculated(0), _clock(Clock()) { }

		Keystate getKeystate();

		/* Methods */
		void update();
		void render(RenderWindow& app);

        virtual ~World();
		
    private:
		Keystate _keystate;
		vector<string> _levelNames;
		vector<Perso> _persos;
		Level _level;
		Screen _screen;
		Coord<int> _windowSize;
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
		
		/* Update  */
		void updateScreen();
    };
} // namespace

#endif // HPP_WORLD
