////////////////////////////////////////////////////////////////////////
// Drawable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Drawable.hpp"

namespace Rendering
{
	Drawable::Drawable(const string& textureName)
	{
		InitializeDrawable(textureName);
	}

	Drawable::Drawable(const string& textureName, Coord<float>& position)
	{
		InitializeDrawable(textureName);
		_position = position;
	}

	void Drawable::InitializeDrawable(const string& textureName)
	{
		_texture = new Texture(textureName);
		_spriteNumbersByState = vector<int>();
		_animationSpeeds = vector<int>();
		_position = Coord<float>();
	}

	Coord<float> Drawable::getPosition()
	{
		return _position;
	}
	
	Texture* Drawable::getTexture()
	{
		return _texture;
	}

	vector<int> Drawable::getSpriteNumbersByState()
	{
		return _spriteNumbersByState;
	}

	void Drawable::addSpriteNumber(int number)
	{
		_spriteNumbersByState.push_back(number);
	}

	vector<int> Drawable::getAnimationSpeeds()
	{
		return _animationSpeeds;
	}

	void Drawable::addAnimationSpeed(int number)
	{
		return _animationSpeeds.push_back(number);
	}

	void Drawable::setTexture(Texture* texture)
	{
		_texture = texture;
	}

	void Drawable::setPosition(float x, float y)
	{
		_position.set(x, y);
	}

	Drawable::~Drawable()
	{
	}
} // namespace
