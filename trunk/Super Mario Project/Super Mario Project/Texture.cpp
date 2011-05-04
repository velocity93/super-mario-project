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
	Texture::Texture(const string& name)
	{
		 _spriteSize = Coord<int>();
		 _name = name;

		 /* Load texture */
		 if(!_image.LoadFromFile(name))
		 {
			 cout << "Erreur de chargement de la texture " << name;
		 }
	}

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

	void Texture::setName(const string& name)
	{
		_name = name;
	}

	Texture::~Texture()
	{

	}
} // namespace
