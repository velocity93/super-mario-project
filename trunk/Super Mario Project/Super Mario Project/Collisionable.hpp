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
		Collisionable() : position(Coord<float>()), hitboxPosition(Coord<float>()), hitboxSize(Coord<int>()) { }
		Collisionable(Coord<float> Position) : position(Position), hitboxPosition(Coord<float>()), hitboxSize(Coord<int>()) { }
		Coord<float> GetPosition()
		{
			return position;
		}

		Coord<float> GetHitboxPosition()
		{
			return hitboxPosition;
		}

		Coord<int> GetHitboxSize()
		{
			return hitboxSize;
		}

		void SetPosition(Coord<float> Position)
		{
			position = Position;
		}

		void SetHitboxPosition(Coord<float> HitboxPosition)
		{
			hitboxPosition = HitboxPosition;
		}

		void SetHitboxSize(Coord<int> HitboxSize)
		{
			hitboxSize = HitboxSize;
		}

        ~Collisionable();
		
    private:
		Coord<float> position;
		Coord<float> hitboxPosition;
		Coord<int> hitboxSize;
    };
} // namespace

#endif // HPP_COLLISIONABLE
