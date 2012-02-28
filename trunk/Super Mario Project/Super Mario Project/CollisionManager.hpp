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

#include "EntityMovable.hpp"
#include "Level.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	class CollisionManager
	{
		public:
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

		struct Collisions_info
		{
			vector<bool> type;
			bool isFirstEntityTouched;
			bool isSecondEntityTouched;
		};

	
		CollisionManager();

		static void solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level, RenderWindow& app);
		static void solveCollisions(EntityMovable* et1, Collisionable* et2, Level* level, RenderWindow& app);

		virtual ~CollisionManager();

	private:
		static bool detectCollisions(Collisionable* c1, Collisionable* c2, Collisions_info* collisions_info);
	};
} // namespace

#endif // HPP_COLLISIONMANAGER
