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
		return Drawable::_spriteNumbersByState;
	}

	vector<int> Drawable::getAnimationSpeeds()
	{
		return _animationSpeeds;
	}

	void Drawable::setTexture(Texture* texture)
	{
		_texture = texture;
	}

	Drawable::~Drawable()
	{
	}
} // namespace
