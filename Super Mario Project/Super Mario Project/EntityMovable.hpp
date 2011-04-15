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
    class EntityMovable : public Collisionable
    {
		enum Side {
			LEFT_SIDE,
			RIGHT_SIDE
		};

    public:
		/* Constructors */
		EntityMovable() : Collisionable(), _previousPosition(Coord<float>()), _speed(Vect<float>()), _side(RIGHT_SIDE) { }
		EntityMovable(Coord<float> position) : Collisionable(position), _previousPosition(position), _speed(Vect<float>()), _side(RIGHT_SIDE) { }

		/* getters and setters */
		Coord<float> getPreviousPosition();
		Vect<float> getSpeed();
		Side getSide();
		void getPreviousPosition(Coord<float> previousPosition);
		void getSpeed(Vect<float> speed);
		void setSide(Side side);

		/* Destructors */
        ~EntityMovable();
		
    private:
		Coord<float> _previousPosition;
		Vect<float> _speed;
		Side _side;
    };
} // namespace

#endif // HPP_ENTITYMOVABLE
