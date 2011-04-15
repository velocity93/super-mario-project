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

using namespace Rendering;

namespace Collisions
{
    class Collisionable : Drawable
    {
	public:
		/* Constructors */
		Collisionable() : _position(Coord<float>()), _hitboxPosition(Coord<float>()), _hitboxSize(Coord<int>()) { }
		Collisionable(Coord<float> position) : _position(position), _hitboxPosition(Coord<float>()), _hitboxSize(Coord<int>()) { }

		/* getters and setters */
		Coord<float> getPosition();
		Coord<float> getHitboxPosition();
		Coord<int> getHitboxSize();
		void setPosition(Coord<float> position);
		void setHitboxPosition(Coord<float> hitboxPosition);
		void setHitboxSize(Coord<int> hitboxSize);

		/* Destructors */
        ~Collisionable();
		
    private:
		Coord<float> _position;
		Coord<float> _hitboxPosition;
		Coord<int> _hitboxSize;
    };
} // namespace

#endif // HPP_COLLISIONABLE
