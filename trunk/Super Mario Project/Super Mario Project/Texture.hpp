////////////////////////////////////////////////////////////////////////
// Texture.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_TEXTURE
#define HPP_TEXTURE

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

namespace Rendering
{
    class Texture
    {
    public:
		/* Constructor */
		Texture(const string& name);

		/* getters and setters */
		string getName();
		Image getImage();
		Sprite getSprite();
		void setName(const string& name);

		void setCoordSprite(int left, int top, int right, int bottom);

		/* Destructor */
		virtual ~Texture();
		
    private:
		string _name;
		Image _image;
		Sprite _sprite;

    };
} // namespace

#endif // HPP_TEXTURE
