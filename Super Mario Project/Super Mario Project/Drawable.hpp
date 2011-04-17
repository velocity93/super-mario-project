////////////////////////////////////////////////////////////////////////
// Drawable.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DRAWABLE
#define HPP_DRAWABLE

#include "Texture.hpp"
#include <vector>

using namespace std;

namespace Rendering
{
	class Drawable
	{
		enum Layer
		{
			BACKGROUND_LAYER,
			BACKGROUND_PARTICLES_LAYER,
			OBJECTS_LAYER,
			BLOC_LAYER_1,
			ITEM_LAYER,
			BLOC_LAYER_2,
			FOREGROUND_LAYER,
			FOREGROUND_PARTICLES_LAYER
		};

		enum Angle
		{
			ANGLE_0,
			ANGLE_90,
			ANGLE_180,
			ANGLE_270
		};

	public:
		/* Constructor */
		Drawable() : _texture(Texture()), _spriteNumbers(vector<int>()), _animationSpeeds(vector<int>()) { }

		/* getters and setters */
		Texture getTexture();
		vector<int> getSpriteNumbers();
		vector<int> getAnimationSpeeds();
		void setTexture(Texture& texture);
		void setSpriteNumbers(vector<int> spriteNumbers);
		void setAnimationSpeeds(vector<int> animationSpeeds);

		/* It will be defined in subclasses */
		/* update drawable object context */
		virtual void update(float time) = 0;

		/* Draw actual object state */
		virtual void render() = 0;

		virtual ~Drawable();

	private:
		Texture _texture;
		vector<int> _spriteNumbers;
		vector<int> _animationSpeeds;
	};
} // namespace

#endif // HPP_DRAWABLE
