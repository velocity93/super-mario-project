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

#include "Resource.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace smp
{
	class Texture : public Resource, public sf::Texture
    {
    public:
		/* Constructor */
		Texture(const std::string& name);

		/* getters and setters */
        sf::Sprite& getSprite();
		void setPosition(float x, float y);

		/* Destructor */
		virtual ~Texture();
		
    private:
        sf::Sprite _sprite;
    };
} // namespace

#endif // HPP_TEXTURE
