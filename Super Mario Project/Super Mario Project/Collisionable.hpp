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
    class Collisionable : public Rendering::Drawable
    {
	public:
		/* Constructors */
		Collisionable(const string& textureName) : Drawable(textureName), _hitboxPosition(Coord<float>()), _hitboxSize(Coord<int>()) { }
		Collisionable(const string& textureName, Coord<float>& position) : Drawable(textureName, position), _hitboxPosition(Coord<float>()), _hitboxSize(Coord<int>()) { }

		/* getters and setters */
		Coord<float> getHitboxPosition();
		Coord<int> getHitboxSize();
		void setHitboxPosition(Coord<float>& hitboxPosition);
		void setHitboxSize(Coord<int>& hitboxSize);

		/* Destructors */
        virtual ~Collisionable();
		
    private:
		Coord<float> _hitboxPosition;
		Coord<int> _hitboxSize;
    };
} // namespace

#endif // HPP_COLLISIONABLE
