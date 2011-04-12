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
		Texture() : spriteSize(Coord<int>()), name(""), id(-1) { }
		Coord<int> GetSpriteSize()
		{
			return spriteSize;
		}

		Coord<int> GetSize()
		{
			return size;
		}

		string GetName()
		{
			return name;
		}

		int GetId()
		{
			return id;
		}

		void SetSpriteSize(Coord<int> SpriteSize)
		{
			spriteSize = SpriteSize;
		}

		void SetSize(Coord<int> Size)
		{
			size = Size;
		}

		void SetName(string Name)
		{
			name = Name;
		}

		void SetId(int Id)
		{
			Id = id;
		}

		void LoadTexture(string Name);

		
    private:
		Coord<int> spriteSize;
		Coord<int> size;
		string name;
		int id;
    };
} // namespace

#endif // HPP_TEXTURE
