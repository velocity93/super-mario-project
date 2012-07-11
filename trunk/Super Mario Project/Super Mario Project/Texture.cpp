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
		: Resource(name), sf::Texture()
    {
        /* Load texture */
		
        if(!loadFromFile(name + ".png"))
        {
            cout << "Error in loading texture " << name << endl;
        }

        setSmooth(false);
		_sprite.setTexture(*this);
    }

    ReversedSprite& Texture::getSprite()
    {
        return _sprite;
    }

    void Texture::setSubRect(int left, int top, int right, int bottom)
    {
        _sprite.setTextureRect(IntRect(left, top, right, bottom));
    }

    void Texture::setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    }

	void Texture::setSpriteOrigin(float x, float y)
    {
        _sprite.setOrigin(x, y);
    }

    Texture::~Texture()
    {
		release();
    }
} // namespace
