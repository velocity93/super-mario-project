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

	Drawable::Drawable(const string& textureName,Coordf& position)
	{
		InitializeDrawable(textureName);
		_position = position;
	}

	void Drawable::InitializeDrawable(const string& textureName)
	{
		_texture = new Texture(textureName);
		_spriteNumbersByState = vector<int>();
		_animationSpeeds = vector<int>();
		_position =Coordf();
	}

	Texture* Drawable::getTexture()
	{
		return _texture;
	}

	Coordf Drawable::getPosition()
	{
		return _position;
	}

	void Drawable::setPosition(float x, float y)
	{
		_position = Coordf(x, y);
	}

	Drawable::~Drawable()
	{
	}
} // namespace
