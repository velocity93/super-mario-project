////////////////////////////////////////////////////////////////////////
// EntityMovable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "EntityMovable.hpp"

using sf::Vector2f;

namespace smp
{
	Vector2f& EntityMovable::getSpeed()
	{
		return _speed;
	}

	Vector2f& EntityMovable::getPreviousPosition()
	{
		return _previousPosition;
	}

	Vector2f& EntityMovable::getHitboxPosition()
	{
		return Vector2f(_hitboxPosition.x + _deltaX, _hitboxPosition.y);
	}

	Vector2f& EntityMovable::getPreviousHitboxPosition()
	{
		return _previousHitboxPosition;
	}

	void EntityMovable::setDeltaX(int delta)
	{
		_deltaX = delta;
	}

	void EntityMovable::setDeltaY(int delta)
	{
		_deltaY = delta;
	}

	void EntityMovable::updatePositions(float positionX, float positionY)
	{
		/* Update hitbox position */
		_hitboxPosition.x = positionX;
		_hitboxPosition.y = positionY;

		setPositionX(_hitboxPosition.x - _deltaX);
		setPositionY(_hitboxPosition.y);
	}

	void EntityMovable::gravity(Vector2f &speed, float time)
	{
		speed.y -= PhysicConstants::GRAVITY * time;

		if(speed.y < -PhysicConstants::SPEED_Y_MAX)
			speed.y = -PhysicConstants::SPEED_Y_MAX;
	}

	EntityMovable::~EntityMovable()
	{
	}

	/* Initialize float physic constants */
	const float PhysicConstants::EJECTION_SPEED_Y = 600.0F;
	const float PhysicConstants::RUN_SPEED = 0.6F;
	const float PhysicConstants::AIR_COEFF_FRICTION = 0.5F;
} // namespace
