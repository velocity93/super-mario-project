////////////////////////////////////////////////////////////////////////
// Keystate.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_KEYSTATE
#define HPP_KEYSTATE

#include <SFML\Graphics.hpp>

using namespace sf;

namespace SuperMarioProject
{
	enum Keys
	{
		NONE = -1,
		LEFT,
		RIGHT,
		UP,
		DOWN,
		JUMP,
		RUN,
		LEFT_CLICK,
		RIGHT_CLICK,
		ENTER,
		ESCAPE,
		LEFT_CTRL,
		SUPPR,
		CUT,
		COPY,
		PASTE,
		NB_KEYS,
	};

    class Keystate
    {
    public:
		Keystate();
		void Update(RenderWindow App);

		bool* GetActual()
		{
			return actual;
		};

		bool* GetPrevious()
		{
			return previous;
		};

    private:
		bool actual[NB_KEYS];
		bool previous[NB_KEYS];
    };
} // namespace

#endif // HPP_KEYSTATE
