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

namespace Collisions
{
    class EntityMovable : public Collisionable
    {
	
	public:
		typedef enum Side {
			LEFT_SIDE,
			RIGHT_SIDE
		} Side;

    
		/* Constructors */
		EntityMovable(const string& textureName, const Vector2f& position, const Vector2f& speed = Vector2f(0,0), Side side = RIGHT_SIDE) :
			Collisionable(textureName, position), 
			_previousPosition(position),
			_previousHitboxPosition(position),
			_speed(speed), 
			_side(side),
			_deltaX(0) { }

		/* getters and setters */
		Vector2f& getPreviousPosition();
		Vector2f& getPreviousHitboxPosition();
		void updatePositions(float positionX, float positionY);

		virtual void onCollision(Collisionable* c, vector<bool>& infos) = 0;
		virtual void updatePhysicData(RenderWindow& app) = 0;

		/* Destructors */
        virtual ~EntityMovable();
		
    protected:
		Vector2f _previousPosition;
		Vector2f _previousHitboxPosition;
		Vector2f _speed;
		Side _side;
		int _deltaX;

		void gravity(Vector2f &speed, float time);
    };

	class PhysicConstants
	{
	public :
		/* Physics constants */
		static const int SPEED_Y_MAX				= 400;
		static const int JUMP_SPEED					= 600;
		static const float RUN_SPEED;
		static const float EJECTION_SPEED_Y;
		static const int GRAVITY					= 1400;

		/* Accelerations constants (* 200) */
		static const int RUN_ACCEL					= 50;
		static const int WALK_ACCEL					= 20;

		/* Frictions constants (* 1000) */
		static const int SLIDE_COEFF_FRICTION		= 3;
		static const int CLASSIC_COEFF_FRICTION		= 5;
		static const int ICE_COEFF_FRICTION			= 4;
		static const float AIR_COEFF_FRICTION;

		/* Submissions */
		static const int GROUND_SUBMISSION			= 0x0000001;
		static const int GRAVITY_SUBMISSION			= 0x0000002;
		static const int RETURN_SENDER_SUBMISSION	= 0x0000004;
	};
} // namespace

#endif // HPP_ENTITYMOVABLE
