////////////////////////////////////////////////////////////////////////
// EntityMovable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "EntityMovable.hpp"

namespace Collisions
{
	Vector2f EntityMovable::getPreviousPosition()
	{
		return _previousPosition;
	}

	Vector2f EntityMovable::getSpeed()
	{
		return _speed;
	}

	EntityMovable::Side EntityMovable::getSide()
	{
		return _side;
	}

	void EntityMovable::setSpeed(const Vector2f& speed)
	{
		_speed = speed;
	}

	void EntityMovable::setSide(const Side &side)
	{
		_side = side;
	}

	void EntityMovable::gravity(Vector2f &speed, float time)
	{
		speed.y -= GRAVITY * time;

		if(speed.y < -SPEED_Y_MAX)
			speed.y = -SPEED_Y_MAX;
	}

	EntityMovable::~EntityMovable()
	{
	}
} // namespace
