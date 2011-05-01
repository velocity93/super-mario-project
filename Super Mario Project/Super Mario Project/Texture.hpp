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

#include "Coord.hpp"
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

using namespace Utils;
using namespace std;
using namespace sf;

namespace Rendering
{
    class Texture
    {
    public:
		/* Constructor */
		Texture(string name);

		/* getters and setters */
		Coord<int> getSpriteSize();
		string getName();
		Image getImage();
		void setSpriteSize(Coord<int>& spriteSize);
		void setName(string name);

		/* Destructor */
		virtual ~Texture();
		
    private:
		Coord<int> _spriteSize;
		string _name;
		Image _image;

    };
} // namespace

#endif // HPP_TEXTURE
