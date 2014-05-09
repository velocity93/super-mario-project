////////////////////////////////////////////////////////////////////////
// Sprite.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SPRITE
#define HPP_SPRITE

#include <SFML/Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Texture.hpp"
#include <string>

namespace smp
{
	class Sprite : public sf::Sprite
	{
	public :
		Sprite(smp::Texture& texture) : sf::Sprite(texture) { }
		void draw(bool isFlipX)
		{
			Texture::bind(this->getTexture());

			sf::Vector2u textureSize = getTexture()->getSize();
			sf::IntRect textureRect = getTextureRect();
			sf::Vector2f position = getPosition();

			sf::Vector2f bottomLeft((float)textureRect.left / textureSize.x, (float)(textureRect.top + textureRect.height) / textureSize.y);
			sf::Vector2f topRight((float)(textureRect.left + textureRect.width) / textureSize.x, (float)textureRect.top / textureSize.y);

			if(isFlipX)
			{
				float temp = bottomLeft.x;
				bottomLeft.x = topRight.x;
				topRight.x = temp;
			}

			glBegin(GL_QUADS);
			glTexCoord2f(bottomLeft.x, -bottomLeft.y);
			glVertex2i(position.x, position.y + textureRect.height);
			glTexCoord2f(topRight.x, -bottomLeft.y);
			glVertex2i(position.x + textureRect.width, position.y + textureRect.height);
			glTexCoord2f(topRight.x, -topRight.y);
			glVertex2i(position.x + textureRect.width, position.y);
			glTexCoord2f(bottomLeft.x, -topRight.y);
			glVertex2i(position.x, position.y);

			glEnd();
		}
	};
}

#endif