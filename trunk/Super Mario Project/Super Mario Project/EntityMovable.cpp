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

	Vect<float> EntityMovable::getSpeed()
	{
		return _speed;
	}

	EntityMovable::Side EntityMovable::getSide()
	{
		return _side;
	}

	void EntityMovable::getPreviousPosition(Coord<float>& previousPosition)
	{
		_previousPosition.set(previousPosition);
	}

	void EntityMovable::setSpeed(Vect<float>& speed)
	{
		_speed.set(speed);
	}

	void EntityMovable::setSpeed(float x, float y)
	{
		_speed.set(x, y);
	}

	void EntityMovable::setSide(Side side)
	{
		_side = side;
	}


	EntityMovable::~EntityMovable()
	{
	}
} // namespace
