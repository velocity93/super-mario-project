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
	Coord<float> EntityMovable::getPreviousPosition()
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

	void EntityMovable::setPreviousPosition(Coord<float>& previousPosition)
	{
		_previousPosition.set(previousPosition);
	}

	void EntityMovable::setSpeed(Vector2f& speed)
	{
		_speed = speed;
	}

	void EntityMovable::setSpeedX(float x)
	{
		_speed.x = x;
	}

	void EntityMovable::setSpeedY(float y)
	{
		_speed.y = y;
	}

	void EntityMovable::setSide(Side side)
	{
		_side = side;
	}

	void EntityMovable::gravity(Vector2f* speed, float time)
	{
		speed->y -= GRAVITY * time;

		if(speed->y < -SPEED_Y_MAX)
			speed->y = -SPEED_Y_MAX;
	}

	EntityMovable::~EntityMovable()
	{
	}
} // namespace
