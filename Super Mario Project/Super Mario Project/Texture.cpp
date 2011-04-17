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

	Coord<int> Texture::getSize()
	{
		return _size;
	}

	string Texture::getName()
	{
		return _name;
	}

	int Texture::getId()
	{
		return _id;
	}

	void Texture::setSpriteSize(Coord<int>& spriteSize)
	{
		_spriteSize = spriteSize;
	}

	void Texture::setSize(Coord<int>& size)
	{
		_size = size;
	}

	void Texture::setName(string name)
	{
		_name = name;
	}

	void Texture::LoadTexture(string Name)
	{
		setName(Name);

		/* To do */
	}

	Texture::~Texture()
	{

	}
} // namespace
