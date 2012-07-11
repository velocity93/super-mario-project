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
			_frameNumber = 0;
			_nbSpritesMax = 1;
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
		void render(Rendering::Texture* texture, RenderWindow& app, Vector2f& position, bool flipX, int delta = 0);
		void render(Rendering::Texture* texture, RenderWindow& app, Vector2f& position, Vector2i& coords, Vector2i& size);

	private:
		map<T, int> _nbSpritesByState;
		map<T, int> _frameDelayByState;
		T _currentState;
		int _frameNumber;
		int _nbSpritesMax;
		int _frameDelayForCurrentState;
		int _nbSpritesForCurrentState;
		SuperMarioProject::PausableClock _clock;

		/* Get nbSprites for currentState */
		int getNbSpritesForCurrentState();
		int getFrameDelayForCurrentState(); 

		int computeNbSpritesMax();

	};

	#include "Animation.inl"
}

#endif