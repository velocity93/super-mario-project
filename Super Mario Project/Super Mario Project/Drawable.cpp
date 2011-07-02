////////////////////////////////////////////////////////////////////////
// Drawable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Drawable.hpp"
#include "ResourceManager.hpp"

namespace Rendering
{
	Drawable::Drawable(const string& textureName)
	{
		InitializeDrawable(textureName);
	}

	Drawable::Drawable(const string& textureName, Vector2f& position)
	{
		InitializeDrawable(textureName);
		_position = position;
	}

	void Drawable::InitializeDrawable(const string& textureName)
	{
        _texture = SuperMarioProject::ResourceManager::getTexture(textureName);
		/*_spriteNumbersByState = vector<int>();
		_animationSpeeds = vector<int>();*/
		_position = Vector2f();
	}

	Texture* Drawable::getTexture()
	{
		return _texture;
	}

	Vector2f Drawable::getPosition()
	{
		return _position;
	}

	void Drawable::setPosition(float x, float y)
	{
		_position = Vector2f(x, y);
	}

	Drawable::~Drawable()
	{
        _texture->release();
	}
} // namespace
