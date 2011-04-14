////////////////////////////////////////////////////////////////////////
// EntityMovable.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENTITYMOVABLE
#define HPP_ENTITYMOVABLE

#include "Collisionable.hpp"

using namespace Utils;

namespace Collisions
{

	enum Side {
		LEFT_SIDE,
		RIGHT_SIDE
	};

    class EntityMovable : public Collisionable
    {
    public:
		/* Constructors */
		EntityMovable() : Collisionable(), previousPosition(Coord<float>()), speed(Vect<float>()), side(RIGHT_SIDE) { }
		EntityMovable(Coord<float> Position) : Collisionable(Position), previousPosition(Position), speed(Vect<float>()), side(RIGHT_SIDE) { }

		/* Getters and setters */
		Coord<float> GetPreviousPosition()
		{
			return previousPosition;
		}

		Vect<float> GetSpeed()
		{
			return speed;
		}

		Side GetSide()
		{
			return side;
		}

		void GetPreviousPosition(Coord<float> PreviousPosition)
		{
			previousPosition = PreviousPosition;
		}

		void GetSpeed(Vect<float> Speed)
		{
			speed = Speed;
		}

		void SetSide(Side Side)
		{
			side = Side;
		}

		/* Destructors */
        ~EntityMovable();
		
    private:
		Coord<float> previousPosition;
		Vect<float> speed;
		Side side;
    };
} // namespace

#endif // HPP_ENTITYMOVABLE
