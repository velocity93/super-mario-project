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
#include <vector>

using namespace sf;
using namespace std;

namespace SuperMarioProject
{
    class Keystate
    {
	public:
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

    
		Keystate();
		void update(RenderWindow& App);

		vector<bool> getActual();
		vector<bool> getPrevious();

    private:
		vector<bool> _actual;
		vector<bool> _previous;
    };
} // namespace

#endif // HPP_KEYSTATE
