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
		 _name = name;
		 _image = sf::Image();
		 _sprite = sf::Sprite();

		 /* Load texture */
		 if(!_image.LoadFromFile(name + ".png"))
		 {
			 cout << "Erreur de chargement de la texture " << name;
		 }
		 _image.SetSmooth(false);

		 _sprite.SetImage(_image);
	}

	string Texture::getName()
	{
		return _name;
	}

	Image Texture::getImage()
	{
		return _image;
	}

	Sprite Texture::getSprite()
	{
		return _sprite;
	}

	void Texture::setName(const string& name)
	{
		_name = name;
	}

	void Texture::setCoordSprite(int left, int top, int right, int bottom)
	{
		_sprite.SetSubRect(IntRect(left, top, right, bottom));
	}

	Texture::~Texture()
	{

	}
} // namespace
