////////////////////////////////////////////////////////////////////////
// Texture.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"

namespace Rendering
{
	Coord<int> Texture::getSpriteSize()
	{
		return _spriteSize;
	}

	string Texture::getName()
	{
		return _name;
	}

	Image Texture::getImage()
	{
		return _image;
	}

	void Texture::setSpriteSize(Coord<int>& spriteSize)
	{
		_spriteSize = spriteSize;
	}

	void Texture::setName(string name)
	{
		_name = name;
	}

	Texture* Texture::loadTexture(string name)
	{
		Texture* texture = new Texture();
		texture->setName(name);
		texture->getImage().LoadFromFile(name);

		return texture;
	}

	Texture::~Texture()
	{

	}
} // namespace
