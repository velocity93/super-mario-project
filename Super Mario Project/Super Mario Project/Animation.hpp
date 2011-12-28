////////////////////////////////////////////////////////////////////////
// Animation.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ANIMATION
#define HPP_ANIMATION

#include "Texture.hpp"
#include "PausableClock.hpp"
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;
using namespace SuperMarioProject;

namespace Rendering
{
	template <typename T>
	class Animation
    {
	public:
		/* Constructor */
		Animation()
		{
			_clock.Start();
		}

		void setMapNbSprites(map<T, int>& nbSpritesByState);
		void setMapFrameDelay(map<T, int>& frameDelayByState);
		void setCurrentState(T state);

		int getNbSpritesMax();

		/* Setting Maps directly */
		void addNbSpritesForGivenState(T state, int nbSprites);
		void addFrameDelayForGivenState(T state, int frameDelay);

		/* Drawing */
		void update();
		void render(Texture* texture, RenderWindow& app, Vector2f& position, bool flipY, int delta = 0);

	private:
		map<T, int> _nbSpritesByState;
		map<T, int> _frameDelayByState;
		T _currentState;
		int _frameNumber;
		int _frameDelayForCurrentState;
		int _nbSpritesForCurrentState;
		SuperMarioProject::PausableClock _clock;

		/* Get nbSprites for currentState */
		int getNbSpritesForCurrentState();
		int getFrameDelayForCurrentState(); 

	};

	#include "Animation.inl"
}

#endif