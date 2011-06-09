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
	Coordf Collisionable::getHitboxPosition()
	{
		return _hitboxPosition;
	}

	Vector2i Collisionable::getHitboxSize()
	{
		return _hitboxSize;
	}

	void Collisionable::setHitboxPosition(const Coordf& hitboxPosition)
	{
		_hitboxPosition = hitboxPosition;
	}

	void Collisionable::setHitboxSize(const Vector2i& hitboxSize)
	{
		_hitboxSize = hitboxSize;
	}

	Collisionable::~Collisionable()
	{

	}
} // namespace
