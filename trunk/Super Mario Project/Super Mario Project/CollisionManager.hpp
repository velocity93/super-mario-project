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
		typedef enum Type {
			FROM_LEFT,
			FROM_TOP,
			FROM_RIGHT,
			FROM_BOTTOM,
			SUPERPOSITION,
			COLLISION_CASES,
			INCLINE_FROM_BOTTOM,
			INCLINE_FROM_LEFT,
			INCLINE_FROM_RIGHT,
			NONE_COLLISION
		} Type;
	
		static CollisionManager* getManager();

		static void solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level, RenderWindow& app);
		static void solveCollisions(EntityMovable* et1, Collisionable* et2, Level* level, RenderWindow& app);

		static void killManager();

	private:
		static CollisionManager* _manager;

		/* Constructor */
		CollisionManager() { }

		virtual ~CollisionManager() { }

		static bool detectCollisions(EntityMovable* c1, Collisionable* c2, vector<bool>& collisions_info);
		static bool detectCollisions(EntityMovable* et1, EntityMovable* et2, vector<bool>& collisions_info);
		static bool Intersects(const FloatRect& r1, const FloatRect& r2, FloatRect* overlapZone = NULL);
	};
} // namespace

#endif // HPP_COLLISIONMANAGER
