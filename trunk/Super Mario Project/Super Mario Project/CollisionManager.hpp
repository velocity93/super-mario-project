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

#include <SFML/Graphics.hpp>

namespace smp
{
	// forward declaration
	class EntityMovable;
	class Collisionable;

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

		static void solveCollisions(EntityMovable* et1, EntityMovable* et2);
		static void solveCollisions(EntityMovable* et1, Collisionable* c2);

		static void killManager();

	private:
		static CollisionManager* _manager;

		/* Constructor */
		CollisionManager() { }

		virtual ~CollisionManager() { }

		static bool detectCollisions(EntityMovable* c1, Collisionable* c2, Type& collisions_info);
		static bool detectCollisions(EntityMovable* et1, EntityMovable* et2, Type& collisions_info);
		static void interprateCollisions(const sf::FloatRect& r1, const sf::FloatRect& r1Prec,
										const sf::FloatRect& r2, const sf::FloatRect& r2Prec,Type& collisions_info);
	};
} // namespace

#endif // HPP_COLLISIONMANAGER
