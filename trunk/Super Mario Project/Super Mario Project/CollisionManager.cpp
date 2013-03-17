////////////////////////////////////////////////////////////////////////
// CollisionManager.cpp
// Super Mario Project
// Copyright (C) 2011
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "CollisionManager.hpp"
#include <iostream>

namespace Collisions
{
	CollisionManager* CollisionManager::_manager = NULL;

	/* SINGLETON PATTERN */
	CollisionManager* CollisionManager::getManager()
	{
		if(_manager == nullptr)
		{
			_manager = new CollisionManager();
		}

		return _manager;
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2)
	{
		Type collision = NONE_COLLISION;

		if(detectCollisions(et1, c2, collision))
		{
			et1->onCollision(c2, collision);
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2)
	{
		Type collision = NONE_COLLISION;

		if(detectCollisions(et1, et2, collision))
		{
			et1->onCollision(et2, collision);
			et2->onCollision(et1, collision);
		}
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, Collisionable* c2, Type& collision)
	{
		//InverseFloatrect
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y,
			c2->getHitboxSize().x, c2->getHitboxSize().y),
			zone;
		bool collisionDetected = false;
		
		bool intersectsPrec = r1Prec.intersects(r2);
		bool intersects = r1.intersects(r2, zone);

		if(intersects && !intersectsPrec)
		{
			collisionDetected = true;

			/* Fill collisions collision_type with rects and rect */
			interprateCollisions(r1, r1Prec, r2, r2, collision);
		}

		return collisionDetected;
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, EntityMovable* et2, Type& collision)
	{
		// inverseFloatRect
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r2(et2->getHitboxPosition().x, et2->getHitboxPosition().y,
			et2->getHitboxSize().x, et2->getHitboxSize().y),

			r2Prec(et2->getPreviousHitboxPosition().x, et2->getPreviousHitboxPosition().y,
			et2->getHitboxSize().x, et2->getHitboxSize().y);
		bool collisionDetected = false;

		bool intersectsPrec = r1Prec.intersects(r2Prec);
		bool intersects = r1.intersects(r2);

		if(intersects && !intersectsPrec)
		{
			collisionDetected = true;

			/* Fill collisions collision_type with rects and rect */
			interprateCollisions(r1, r1Prec, r2, r2Prec, collision);
		}

		return collisionDetected;
	}

	void CollisionManager::interprateCollisions(const FloatRect& r1, const FloatRect& r1Prec,
										const FloatRect& r2, const FloatRect& r2Prec, Type& collision)
	{
		float r1Right = r1.left + r1.width;
		float r1Bottom = r1.top + r1.height;
		float r2Right = r2.left + r2.width;
		float r2Bottom = r2.top + r2.height;
		float r1PrecRight = r1Prec.left + r1Prec.width;
		float r1PrecBottom = r1Prec.top + r1Prec.height;
		float r2PrecRight = r2Prec.left + r2Prec.width;
		float r2PrecBottom = r2Prec.top + r2Prec.height;

		if(r1.top <= r2Bottom
			&& r1Prec.top >= r2PrecBottom
			&&
			((r2.left <= r1.left && r1.left <= r1Right)
			|| (r2.left <= r1Right && r1Right <= r1Right)
			|| (r1.left <= r2.left && r2.left <= r1Right)
			|| (r1.left <= r2Right && r2Right <= r1Right)))
			collision = FROM_TOP;

		else if(r1Bottom >= r2.top
			&& r1PrecBottom <= r2Prec.top
			&&
			((r2.left <= r1.left && r1.left <= r2Right)
			|| (r2.left <= r1Right && r1Right <= r2Right)
			|| (r1.left <= r2.left && r2.left <= r1Right)
			|| (r1.left <= r2Right && r2Right <= r1Right)))
			collision = FROM_BOTTOM;

		else if(r1Right >= r2.left
			&& r1PrecRight <= r2Prec.left
			&&
			((r2.top <= r1.top && r1.top <= r2Bottom)
			|| (r2.top <= r1Bottom && r1.top <= r2Bottom)
			|| (r1.top <= r2.top && r2.top <= r1Bottom)
			|| (r1.top <= r2Bottom && r2Bottom <= r2.top)))
			collision = FROM_RIGHT;

		else if(r1.left <= r2Right
			&& r1Prec.left >= r2PrecRight
			&&
			((r2.left <= r1.left && r1.left <= r2Right)
			|| (r2.left <= r1Right && r1Right <= r2Right)
			|| (r1.left <= r2.left && r2.left <= r1Right)
			|| (r1.left <= r2Right && r2Right <= r1Right)))
			collision = FROM_LEFT;
	}

	void CollisionManager::killManager()
	{
		if(_manager != NULL)
			delete _manager;
	}
} // namespace
