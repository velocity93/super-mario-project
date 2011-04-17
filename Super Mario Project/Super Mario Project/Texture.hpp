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
#include <string>

using namespace Utils;
using namespace std;

namespace Rendering
{
    class Texture
    {
    public:
		/* Constructor */
		Texture() : _spriteSize(Coord<int>()), _name(""), _id(-1) { }

		/* getters and setters */
		Coord<int> getSpriteSize();
		Coord<int> getSize();
		string getName();
		int getId();
		void setSpriteSize(Coord<int>& spriteSize);
		void setSize(Coord<int>& size);
		void setName(string name);

		/* Method */
		void LoadTexture(string Name);

		/* Destructor */
		virtual ~Texture();
		
    private:
		Coord<int> _spriteSize;
		Coord<int> _size;
		string _name;
		int _id;
    };
} // namespace

#endif // HPP_TEXTURE
