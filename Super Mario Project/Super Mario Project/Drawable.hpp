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

#include <SFML/Graphics.hpp>
#include <string>

#define BLOCK_WIDTH 32

namespace smp
{
	// forward declaration
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
		Drawable(const std::string& textureName);
		Drawable(const std::string& textureName, const sf::Vector2f& position);

		/* getters and setters */
		sf::Vector2f& getPosition();
		Texture* getTexture();
		bool isActive();
		void setPositionX(float x);
		void setPositionY(float y);

		/* It will be defined in subclasses */
		/* update drawable object context */
		virtual void updateGraphicData(sf::RenderWindow& app) = 0;

		/* Draw actual object state */
		virtual void render(sf::RenderWindow& app) = 0;

		virtual ~Drawable();

	protected:
		Texture* _texture;
		sf::Vector2f _position;
		bool _isActive;

		void InitializeDrawable(const std::string& textureName);
	};
} // namespace

#endif // HPP_DRAWABLE
