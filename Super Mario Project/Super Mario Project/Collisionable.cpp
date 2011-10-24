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
	Collisionable::~Collisionable()
	{

	}

	Vector2f& Collisionable::getHitboxPosition()
	{
		return _hitboxPosition;
	}

	Vector2i& Collisionable::getHitboxSize()
	{
		return _hitboxSize;
	}
} // namespace
