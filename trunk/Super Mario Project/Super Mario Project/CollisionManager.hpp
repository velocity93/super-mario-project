////////////////////////////////////////////////////////////////////////
// CollisionManager.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_COLLISIONMANAGER
#define HPP_COLLISIONMANAGER

namespace Collisions
{
	class CollisionManager
	{
		enum Type {
			FROM_BOTTOM,
			FROM_LEFT,
			FROM_RIGHT,
			FROM_TOP,
			SUPERPOSITION,
			INCLINE_FROM_BOTTOM,
			INCLINE_FROM_LEFT,
			INCLINE_FROM_RIGHT,
			NONE_COLLISION
		};

	public:
		CollisionManager();
		virtual ~CollisionManager();

	private:
	};
} // namespace

#endif // HPP_COLLISIONMANAGER
