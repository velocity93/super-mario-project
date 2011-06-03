////////////////////////////////////////////////////////////////////////
// Collisionable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Collisionable.hpp"

namespace Collisions
{
	Coord<float> Collisionable::getHitboxPosition()
	{
		return _hitboxPosition;
	}

	Vector2i Collisionable::getHitboxSize()
	{
		return _hitboxSize;
	}

	void Collisionable::setHitboxPosition(Coord<float>& hitboxPosition)
	{
		_hitboxPosition = hitboxPosition;
	}

	void Collisionable::setHitboxSize(Vector2i& hitboxSize)
	{
		_hitboxSize = hitboxSize;
	}

	Collisionable::~Collisionable()
	{

	}
} // namespace
