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

#define SPEED_Y_MAX						0.008F
#define GRAVITY							0.002F

#include "Collisionable.hpp"

namespace Collisions
{
    class EntityMovable : public Collisionable
    {
	
	public:
		enum Side {
			LEFT_SIDE,
			RIGHT_SIDE
		};

    
		/* Constructors */
		EntityMovable(const string& textureName) : Collisionable(textureName), _previousPosition(Coord<float>()), _speed(Vector2f()), _side(RIGHT_SIDE) { }
		EntityMovable(const string& textureName, Coord<float>& position) : Collisionable(textureName, position), _previousPosition(position), _speed(Vector2f()), _side(RIGHT_SIDE) { }

		/* getters and setters */
		Coord<float> getPreviousPosition();
		Vector2f getSpeed();
		Side getSide();
		void setPreviousPosition(Coord<float>& previousPosition);
		void setSpeed(Vector2f& speed);
		void setSpeed(float x, float y);
		void setSide(Side side);

		void gravity(Vector2f* speed, float time);

		/* Destructors */
        virtual ~EntityMovable();
		
    private:
		Coord<float> _previousPosition;
		Vector2f _speed;
		Side _side;
    };
} // namespace

#endif // HPP_ENTITYMOVABLE
