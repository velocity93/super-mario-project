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
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

namespace Rendering
{
	template <typename T>
	class Animation
    {
	public:
		/* Constructor */
		Animation() { }
		Animation(map<T, int>& nbSpritesByState, map<T, int>& vAnimByState);

		void setMapNbSprites(map<T, int>& nbSpritesByState);
		void setMapVAnim(map<T, int>& vAnimByState);
		void setCurrentState(T state);

		int getNbSpritesMax();

		void render(Texture* texture, RenderWindow& app, Vector2f& position);

	private:
		map<T, int> _nbSpritesByState;
		map<T, int> _vAnimByState;
		T _currentState;
	};

	#include "Animation.inl"
}

#endif