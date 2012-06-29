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

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Resource.hpp"
#include "ReversedSprite.hpp"

using namespace std;
using namespace sf;

namespace Rendering
{
	class Texture : public SuperMarioProject::Resource, public sf::Texture
    {
    public:
		/* Constructor */
		Texture(const string& name);

		/* getters and setters */
        ReversedSprite& getSprite();
		void setSubRect(int left, int top, int right, int bottom);
		void setPosition(float x, float y);
		void setSpriteOrigin(float x, float y);

		/* Destructor */
		virtual ~Texture();
		
    private:
        ReversedSprite _sprite;
    };
} // namespace

#endif // HPP_TEXTURE
