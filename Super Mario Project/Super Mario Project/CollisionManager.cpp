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

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level*, RenderWindow&)
	{
		vector<bool> infos;

		/* Initialize collisions infos */
		for(int i = 0; i < COLLISION_CASES; ++i)
			infos.push_back(false);
		
		if(detectCollisions(et1, c2, infos))
		{
			et1->onCollision(c2, infos);
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level*, RenderWindow&)
	{
		vector<bool> infos;

		/* Initialize collisions infos */
		for(int i = 0; i < COLLISION_CASES; ++i)
			infos.push_back(false);
		
		if(detectCollisions(et1, et2, infos))
		{
			et1->onCollision(et2, infos);
			et2->onCollision(et1, infos);
		}
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, Collisionable* c2, vector<bool>& collisions_info)
	{
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y + et1->getHitboxSize().y,
			et1->getHitboxPosition().x + et1->getHitboxSize().x, et1->getHitboxPosition().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y + et1->getHitboxSize().y,
			et1->getPreviousHitboxPosition().x + et1->getHitboxSize().x, et1->getPreviousHitboxPosition().y),

			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y + c2->getHitboxSize().y, 
			c2->getHitboxPosition().x + c2->getHitboxSize().x, c2->getHitboxPosition().y),
			zone;
		bool collisionDetected = false;
		
		bool intersects = Intersects(r1, r2, &zone), intersectsPrec = Intersects(r1Prec, r2);

		if(intersects && !intersectsPrec)
		{
			collisionDetected = true;

			float width = r1.GetWidth();
			float height = (-1) * r1.GetHeight(); // Due to inversion of Top and Bottom 

			if(zone.Right <= r1.Left + width / 2)
				collisions_info[FROM_LEFT] = true;

			if(zone.Left >= r1.Right - width / 2)
				collisions_info[FROM_RIGHT] = true;

			if(zone.Top <= r1.Bottom + height / 2)
				collisions_info[FROM_BOTTOM] = true;

			if(zone.Bottom >= r1.Top - height / 2)
				collisions_info[FROM_TOP] = true;
		
		}

		return collisionDetected;
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, EntityMovable* et2, vector<bool>& collisions_info)
	{
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y + et1->getHitboxSize().y,
			et1->getHitboxPosition().x + et1->getHitboxSize().x, et1->getHitboxPosition().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y + et1->getHitboxSize().y,
			et1->getPreviousHitboxPosition().x + et1->getHitboxSize().x, et1->getPreviousHitboxPosition().y),

			r2(et2->getHitboxPosition().x, et2->getHitboxPosition().y + et2->getHitboxSize().y, 
			et2->getHitboxPosition().x + et2->getHitboxSize().x, et2->getHitboxPosition().y),

			r2Prec(et2->getPreviousHitboxPosition().x, et2->getPreviousHitboxPosition().y + et2->getHitboxSize().y,
			et2->getPreviousHitboxPosition().x + et2->getHitboxSize().x, et2->getPreviousHitboxPosition().y),
			zone;
		bool collisionDetected = false;

		bool intersects = Intersects(r1, r2, &zone), intersectsPrec = Intersects(r1Prec, r2Prec);

		if(intersects && !intersectsPrec)
		{
			collisionDetected = true;

			float width = r1.GetWidth();
			float height = (-1) * r1.GetHeight(); // Due to inversion of Top and Bottom 

			if(zone.Right <= r1.Left + width)
				collisions_info[FROM_LEFT] = true;

			if(zone.Left >= r1.Right - width)
				collisions_info[FROM_RIGHT] = true;

			if(zone.Top <= r1.Bottom + height)
				collisions_info[FROM_BOTTOM] = true;

			if(zone.Bottom >= r1.Top - height)
				collisions_info[FROM_TOP] = true;
		
		}

		return collisionDetected;
	}

	void CollisionManager::killManager()
	{
		if(_manager != NULL)
			delete _manager;
	}

	bool CollisionManager::Intersects(const FloatRect& r1, const FloatRect& r2, FloatRect* OverlappingRect)
	{
		// Compute overlapping rect
		FloatRect Overlapping(std::max(r1.Left,   r2.Left),
			std::min(r1.Top,    r2.Top),
			std::min(r1.Right,  r2.Right),
			std::max(r1.Bottom, r2.Bottom));

		// If overlapping rect is valid, then there is intersection
		if ((Overlapping.Left < Overlapping.Right) && (Overlapping.Bottom < Overlapping.Top))
		{
			if (OverlappingRect)
				*OverlappingRect = Overlapping;
			return true;
		}
		else
		{
			if (OverlappingRect)
				*OverlappingRect = FloatRect(0, 0, 0, 0);
			return false;
		}
	}

} // namespace
