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
		Animation() : _nbSpritesByState(map<T, int>()), _vAnimByState(map<T, int>()), _column(0) { }

		void setMapNbSprites(map<T, int>& nbSpritesByState);
		void setMapVAnim(map<T, int>& vAnimByState);
		void setCurrentState(T state);

		int getNbSpritesMax();

		void addNbSpritesForGivenState(T state, int nbSprites);
		void addVAnimForGivenState(T state, int vAnim);

		/* Drawing */
		void update(Texture* texture, RenderWindow& app);
		void render(Texture* texture, RenderWindow& app, Vector2f& position);

	private:
		map<T, int> _nbSpritesByState;
		map<T, int> _vAnimByState;
		T _currentState;
		int _column;
	};

	#include "Animation.inl"
}

#endif