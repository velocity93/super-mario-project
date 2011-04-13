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
    class EntityMovable : Collisionable
    {
    public:
		EntityMovable() : Collisionable(), previousPosition(Coord<float>()), speed(Vect<float>()) { }
		
		Coord<float> GetPreviousPosition()
		{
			return previousPosition;
		}

		Vect<float> GetSpeed()
		{
			return speed;
		}

		void GetPreviousPosition(Coord<float> PreviousPosition)
		{
			previousPosition = PreviousPosition;
		}

		void GetSpeed(Vect<float> Speed)
		{
			speed = Speed;
		}

        ~EntityMovable();
		
    private:
		Coord<float> previousPosition;
		Vect<float> speed;
    };
} // namespace

#endif // HPP_ENTITYMOVABLE
