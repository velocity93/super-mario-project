////////////////////////////////////////////////////////////////////////
// CollisionManager.cpp
// Super Mario Project
// Copyright (C) 2011
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "CollisionManager.hpp"
#include "EntityMovable.hpp"
#include <iostream>

using sf::FloatRect;

namespace smp
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
		FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y,
			c2->getHitboxSize().x, c2->getHitboxSize().y);
		bool collisionDetected = false;
		
		bool intersectPrec = intersects(r1Prec, r2);
		bool intersect = intersects(r1, r2);

		if(intersect && !intersectPrec)
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
		FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y,
			et1->getHitboxSize().x, et1->getHitboxSize().y),

			r2(et2->getHitboxPosition().x, et2->getHitboxPosition().y,
			et2->getHitboxSize().x, et2->getHitboxSize().y),

			r2Prec(et2->getPreviousHitboxPosition().x, et2->getPreviousHitboxPosition().y,
			et2->getHitboxSize().x, et2->getHitboxSize().y);
		bool collisionDetected = false;

		bool intersectPrec = intersects(r1Prec, r2Prec);
		bool intersect = intersects(r1, r2);

		if(intersect && !intersectPrec)
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

		if(r1.top >= r2Bottom
			&& r1Prec.top <= r2PrecBottom
			&&
			((r2.left <= r1.left && r1.left <= r1Right)
			|| (r2.left <= r1Right && r1Right <= r1Right)
			|| (r1.left <= r2.left && r2.left <= r1Right)
			|| (r1.left <= r2Right && r2Right <= r1Right)))
			collision = FROM_TOP;

		else if(r1.top <= r2Bottom
			&& r1Prec.top >= r2PrecBottom
			&&
			((r2.left <= r1.left && r1.left <= r2Right)
			|| (r2.left <= r1Right && r1Right <= r2Right)
			|| (r1.left <= r2.left && r2.left <= r1Right)
			|| (r1.left <= r2Right && r2Right <= r1Right)))
			collision = FROM_BOTTOM;

		else if(r1Right >= r2.left
			&& r1PrecRight <= r2Prec.left
			&&
			((r2Bottom >= r1.top && r1.top >= r2.top)
			|| (r2Bottom >= r1.top && r1.top >= r2.top)
			|| (r1Bottom >= r2.top && r2.top >= r1.top)
			|| (r2.top >= r2Bottom && r2Bottom >= r1.top)))
			collision = FROM_RIGHT;

		else if(r1.left <= r2Right
			&& r1Prec.left >= r2PrecRight
			&&
			((r2Bottom >= r1.top && r1.top >= r2.top)
			|| (r2Bottom >= r1.top && r1.top >= r2.top)
			|| (r1Bottom >= r2.top && r2.top >= r1.top)
			|| (r2.top >= r2Bottom && r2Bottom >= r1.top)))
			collision = FROM_LEFT;
	}

	bool CollisionManager::intersects(const sf::FloatRect& r1, const sf::FloatRect& r2)
	{
		// Rectangles with negative dimensions are allowed, so we must handle them correctly

		// Compute the min and max of the first rectangle on both axes
		float r1MinX = std::min(r1.left, r1.left + r1.width);
		float r1MaxX = std::max(r1.left, r1.left + r1.width);
		float r1MinY = std::min(r1.top, r1.top + r1.height);
		float r1MaxY = std::max(r1.top, r1.top + r1.height);

		// Compute the min and max of the second rectangle on both axes
		float r2MinX = std::min(r2.left, r2.left + r2.width);
		float r2MaxX = std::max(r2.left, r2.left + r2.width);
		float r2MinY = std::min(r2.top, r2.top + r2.height);
		float r2MaxY = std::max(r2.top, r2.top + r2.height);

		// Compute the intersection boundaries
		float interLeft   = std::max(r1MinX, r2MinX);
		float interTop    = std::max(r1MinY, r2MinY);
		float interRight  = std::min(r1MaxX, r2MaxX);
		float interBottom = std::min(r1MaxY, r2MaxY);

		// If the intersection is valid (positive non zero area), then there is an intersection
		if ((interLeft < interRight) && (interTop < interBottom))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CollisionManager::killManager()
	{
		if(_manager != NULL)
			delete _manager;
	}
} // namespace
