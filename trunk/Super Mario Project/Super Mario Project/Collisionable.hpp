////////////////////////////////////////////////////////////////////////
// Collisionable.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_COLLISIONABLE
#define HPP_COLLISIONABLE

#include "Drawable.hpp"

namespace smp
{
    class Collisionable : public Drawable
    {
	public:
		/* Constructors */
		Collisionable(const std::string& textureName) : Drawable(textureName), _hitboxPosition(sf::Vector2f()), _hitboxSize(sf::Vector2i()) { }
		Collisionable(const std::string& textureName, const sf::Vector2f& position) : Drawable(textureName, position), _hitboxPosition(sf::Vector2f()), _hitboxSize(sf::Vector2i()) { }

		/* Getters */
		sf::Vector2f& getHitboxPosition();
		sf::Vector2i& getHitboxSize();

		/* Destructors */
        virtual ~Collisionable();
		
    protected:
		sf::Vector2f _hitboxPosition;
		sf::Vector2i _hitboxSize;

		void setActivity(sf::RenderWindow& app);
    };
} // namespace

#endif // HPP_COLLISIONABLE
