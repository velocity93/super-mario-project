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
		Collisionable(const string& textureName) : Drawable(textureName), _hitboxPosition(Coordf()), _hitboxSize(Vector2i()) { }
		Collisionable(const string& textureName,Coordf& position) : Drawable(textureName, position), _hitboxPosition(Coordf()), _hitboxSize(Vector2i()) { }

		/* Destructors */
        virtual ~Collisionable();
		
    protected:
		Coordf _hitboxPosition;
		Vector2i _hitboxSize;
    };
} // namespace

#endif // HPP_COLLISIONABLE
