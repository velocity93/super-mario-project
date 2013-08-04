////////////////////////////////////////////////////////////////////////
// Texture.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"
#include "Exceptions.hpp"
#include <iostream>

using namespace std;
using sf::Sprite;
using sf::IntRect;

namespace smp
{
    Texture::Texture(const string& name)
		: Resource(name), sf::Texture()
    {
        /* Load texture */
		
        if(!loadFromFile(name + ".png"))
        {
			throw FileException(name + ".png");
        }

        setSmooth(false);
		_sprite.setTexture(*this);
    }

    Sprite& Texture::getSprite()
    {
        return _sprite;
    }

    void Texture::setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    }

    Texture::~Texture()
    {
		release();
    }
} // namespace
