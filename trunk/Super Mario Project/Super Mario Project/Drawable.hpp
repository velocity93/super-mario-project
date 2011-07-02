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
#include <SFML/Graphics.hpp>
#include <vector>

#define BLOCK_WIDTH 32

using namespace std;
using namespace sf;

namespace Rendering
{
	class Drawable
	{
	
	public:
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
	
		/* Constructors */
		Drawable(const string& textureName);
		Drawable(const string& textureName,Vector2f& position);

		/* getters and setters */
		Vector2f getPosition();
		Texture* getTexture();
		void setPosition(float x, float y);

		/* It will be defined in subclasses */
		/* update drawable object context */
		virtual void update(RenderWindow& app) = 0;

		/* Draw actual object state */
		virtual void render(RenderWindow& app) = 0;

		virtual ~Drawable();

	protected:
		Texture* _texture;
		Vector2f _position;
		/*vector<int> _spriteNumbersByState;
		vector<int> _animationSpeeds;*/

		void InitializeDrawable(const string& textureName);
	};
} // namespace

#endif // HPP_DRAWABLE
