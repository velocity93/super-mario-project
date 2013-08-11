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
#include "Texture.hpp"
#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <climits>

namespace smp
{
	template <typename T>
	class Animation
    {
	public:
		/* Constructor */
		Animation(int nbStatesMax)
		{
			_frameNumber = 0;
			_nbSpritesMax = 1;
			_nbStatesMax = nbStatesMax;
			_clock.Start();
		}

		void setMapNbSprites(std::map<T, int>& nbSpritesByState);
		void setMapFrameDelay(std::map<T, int>& frameDelayByState);
		void setCurrentState(T state);

		int getNbSpritesMax();
		int getNbStates();
		void reset();

		/* Setting Maps directly */
		void addNbSpritesForGivenState(T state, int nbSprites);
		void addFrameDelayForGivenState(T state, int frameDelay);

		/* Drawing */
		void update();
		void render(Texture* texture, sf::RenderWindow& app, sf::Vector2f& position, bool flipX, int delta = 0);
		void render(Texture* texture, sf::RenderWindow& app, sf::Vector2f& position, sf::Vector2i& coords, sf::Vector2i& size);

	private:
		std::map<T, int> _nbSpritesByState;
		std::map<T, int> _frameDelayByState;
		T _currentState;
		int _frameNumber;
		int _nbSpritesMax;
		int _nbStatesMax;
		int _frameDelayForCurrentState;
		int _nbSpritesForCurrentState;
		PausableClock _clock;

		/* Get nbSprites for currentState */
		int getNbSpritesForCurrentState();
		int getFrameDelayForCurrentState(); 
		int computeNbSpritesMax();

	};

	#include "Animation.inl"
}

#endif
