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

namespace Collisions
{

	enum Collision_type {
		FROM_BOTTOM,
		FROM_LEFT,
		FROM_RIGHT,
		FROM_TOP,
		SUPERPOSITION,
		INCLINE_FROM_BOTTOM,
		INCLINE_FROM_LEFT,
		INCLINE_FROM_RIGHT,
		NONE_COLLISION
	};

    class Collisionable
    {
    public:
        Collisionable();
        ~Collisionable();
		
    private:
    };
} // namespace

#endif // HPP_COLLISIONABLE
