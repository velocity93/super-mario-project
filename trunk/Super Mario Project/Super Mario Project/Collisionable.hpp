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
		Collisionable(const string& textureName) : Drawable(textureName), _hitboxPosition(Coord<float>()), _hitboxSize(Vector2i()) { }
		Collisionable(const string& textureName, Coord<float>& position) : Drawable(textureName, position), _hitboxPosition(Coord<float>()), _hitboxSize(Vector2i()) { }

		/* getters and setters */
		Coord<float> getHitboxPosition();
		Vector2i getHitboxSize();
		void setHitboxPosition(Coord<float>& hitboxPosition);
		void setHitboxSize(Vector2i& hitboxSize);

		/* Destructors */
        virtual ~Collisionable();
		
    protected:
		Coord<float> _hitboxPosition;
		Vector2i _hitboxSize;
    };
} // namespace

#endif // HPP_COLLISIONABLE
