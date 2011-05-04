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
#include <SFML\Graphics.hpp>
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
	
		/* Constructor */
		Drawable(const string& textureName) : _texture(new Texture(textureName)), _spriteNumbersByState(vector<int>()), _animationSpeeds(vector<int>()),
					 _position(Coord<float>()) { }
		Drawable(const string& textureName, Coord<float> position) :  _texture(new Texture(textureName)), _spriteNumbersByState(vector<int>()), _animationSpeeds(vector<int>()),
			_position(position) { }

		/* getters and setters */
		Coord<float> getPosition();
		Texture* getTexture();
		vector<int> getSpriteNumbersByState();
		vector<int> getAnimationSpeeds();
		void setPosition(Coord<float>& position);
		void setTexture(Texture* texture);

		/* It will be defined in subclasses */
		/* update drawable object context */
		virtual void update(float time) = 0;

		/* Draw actual object state */
		virtual void render(RenderWindow& app) = 0;

		virtual ~Drawable();

	private:
		Texture* _texture;
		Coord<float> _position;
		vector<int> _spriteNumbersByState;
		vector<int> _animationSpeeds;
	};
} // namespace

#endif // HPP_DRAWABLE
