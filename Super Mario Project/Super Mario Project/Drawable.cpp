////////////////////////////////////////////////////////////////////////
// Drawable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Drawable.hpp"
#include "ResourceManager.hpp"
#include "Texture.hpp"

using namespace std;
using sf::Vector2f;

namespace smp
{
	Drawable::Drawable(const string& textureName) : _isActive(true)
	{
		InitializeDrawable(textureName);
	}

	Drawable::Drawable(const string& textureName, const Vector2f& position) : _isActive(true)
	{
		InitializeDrawable(textureName);
		_position = position;
	}

	void Drawable::InitializeDrawable(const string& textureName)
	{
        _texture = ResourceManager::getTexture(textureName);
		_position = Vector2f();
	}

	Texture* Drawable::getTexture()
	{
		return _texture;
	}

	Vector2f& Drawable::getPosition()
	{
		return _position;
	}

	bool Drawable::isActive()
	{
		return _isActive;
	}

	void Drawable::setPositionX(float x)
	{
		_position.x = x;
	}

	void Drawable::setPositionY(float y)
	{
		_position.y = y;
	}

	Drawable::~Drawable()
	{
        _texture->release();
	}
} // namespace
