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
	Texture Drawable::getTexture()
	{
		return _texture;
	}

	vector<int> Drawable::getSpriteNumbers()
	{
		return Drawable::_spriteNumbers;
	}

	vector<int> Drawable::getAnimationSpeeds()
	{
		return _animationSpeeds;
	}

	void Drawable::setTexture(Texture& texture)
	{
		_texture = texture;
	}

	void Drawable::setSpriteNumbers(vector<int> spriteNumbers)
	{
		_spriteNumbers = spriteNumbers;
	}

	void Drawable::setAnimationSpeeds(vector<int> animationSpeeds)
	{
		_animationSpeeds = animationSpeeds;
	}

	Drawable::~Drawable()
	{
	}
} // namespace
