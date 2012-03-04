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

/* Physics constants */
#define SPEED_Y_MAX						400
#define JUMP_SPEED			    		600
#define RUN_SPEED						0.6F
#define EJECTION_SPEED_Y				0.2F
#define GRAVITY							1400

/* Accelerations constants (* 200) */
#define RUN_ACCEL						50
#define WALK_ACCEL						20

/* Frictions constants (* 1000) */
#define SLIDE_COEFF_FRICTION			3
#define CLASSIC_COEFF_FRICTION			5
#define ICE_COEFF_FRICTION				4
#define AIR_COEFF_FRICTION				0.5F

/* Submissions */
#define GROUND_SUBMISSION			    0x0000001
#define GRAVITY_SUBMISSION              0x0000002
#define RETURN_SENDER_SUBMISSION        0x0000004


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
		EntityMovable(const string& textureName, Vector2f& position, Vector2f& speed = Vector2f(0,0), Side side = RIGHT_SIDE) :
			Collisionable(textureName, position), 
			_previousPosition(position),
			_speed(speed), 
			_side(side) { }

		/* getters and setters */
		Vector2f& getPreviousPosition();
		Vector2f& getSpeed();
		Side getSide();
		void setSpeed(const Vector2f& speed);
		void setSide(const Side &side);

		virtual void onCollision(Collisionable* c, vector<bool>& infos) = 0;
		virtual void updatePhysicData(RenderWindow& app) = 0;

		/* Destructors */
        virtual ~EntityMovable();
		
    protected:
		Vector2f _previousPosition;
		Vector2f _speed;
		Side _side;

		void gravity(Vector2f &speed, float time);
    };
} // namespace

#endif // HPP_ENTITYMOVABLE
