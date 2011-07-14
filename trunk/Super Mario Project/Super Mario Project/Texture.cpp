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
        : Resource(name)
    {
        _image = sf::Image();
        _sprite = sf::Sprite();

        /* Load texture */
		
        if(!_image.LoadFromFile(name + ".png"))
        {
            cout << "Error in loading texture " << name << endl;
        }
        _image.SetSmooth(false);

        _sprite.SetImage(_image);

        _image.Bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    Image* Texture::getImage()
    {
        return &_image;
    }

    Sprite Texture::getSprite()
    {
        return _sprite;
    }

    void Texture::setSubRect(int left, int top, int right, int bottom)
    {
        _sprite.SetSubRect(IntRect(left, top, right, bottom));
    }

    void Texture::setPosition(float x, float y)
    {
        _sprite.SetPosition(x, y);
    }

    Texture::~Texture()
    {
		release();
    }
} // namespace
