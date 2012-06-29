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
	class Texture;
	class Drawable
	{
	
	public:
		typedef enum Layer
		{
			BACKGROUND_LAYER,
			BACKGROUND_PARTICLES_LAYER,
			OBJECTS_LAYER,
			BLOC_LAYER_1,
			ITEM_LAYER,
			BLOC_LAYER_2,
			FOREGROUND_LAYER,
			FOREGROUND_PARTICLES_LAYER
		} Layer;

		typedef enum Angle
		{
			ANGLE_0,
			ANGLE_90,
			ANGLE_180,
			ANGLE_270
		} Angle;
	
		/* Constructors */
		Drawable(const string& textureName);
		Drawable(const string& textureName, const Vector2f& position);

		/* getters and setters */
		Vector2f& getPosition();
		Rendering::Texture* getTexture();
		bool isActive();
		void setPositionX(float x);
		void setPositionY(float y);

		/* It will be defined in subclasses */
		/* update drawable object context */
		virtual void updateGraphicData(RenderWindow& app) = 0;

		/* Draw actual object state */
		virtual void render(RenderWindow& app) = 0;

		virtual ~Drawable();

	protected:
		Rendering::Texture* _texture;
		Vector2f _position;
		bool _isActive;

		void InitializeDrawable(const string& textureName);
	};
} // namespace

#endif // HPP_DRAWABLE
