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

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level* level, RenderWindow& app)
	{
		vector<bool> infos = vector<bool>(false);
		
		if(detectCollisions(et1, c2, infos))
		{
			et1->onCollision(c2, infos);
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level, RenderWindow& app)
	{
		vector<bool> infos;
		
		if(detectCollisions(et1, et2, infos))
		{
			et1->onCollision(et2, infos);
			et2->onCollision(et1, infos);
		}
	}

	/* SPECIFIC COLLISIONS */
	void CollisionManager::solveCollisions(EntityMovable* et1, BlockOccurrence* block, vector<bool>& infos, Level* level, RenderWindow& app)
	{
		if(infos[FROM_BOTTOM] && (block->getActualModel()->getType() & BlocksConstants::GROUND))
		{
			et1->setPositionY(block->getHitboxPosition().y + block->getHitboxSize().y);
		}

		if(infos[FROM_TOP] && (block->getActualModel()->getType() & BlocksConstants::ROOF))
		{
			et1->setPositionY(block->getHitboxPosition().y - et1->getHitboxSize().y);
		}

		if(infos[FROM_LEFT] && (block->getActualModel()->getType() & BlocksConstants::RIGHT_WALL))
		{
			et1->setPositionX(block->getHitboxPosition().x + block->getHitboxSize().x);
		}

		if(infos[FROM_RIGHT] && (block->getActualModel()->getType() & BlocksConstants::LEFT_WALL))
		{
			et1->setPositionX(block->getHitboxPosition().x - et1->getHitboxSize().x);
		}
	}

	bool CollisionManager::detectCollisions(Collisionable* c1, Collisionable* c2, vector<bool>& collisions_info)
	{
		sf::FloatRect r1(c1->getHitboxPosition().x, c1->getHitboxPosition().y + c1->getHitboxSize().y,
			c1->getHitboxPosition().x + c1->getHitboxSize().x, c1->getHitboxPosition().y),
			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y + c2->getHitboxSize().y, c2->getHitboxPosition().x + c2->getHitboxSize().x, c2->getHitboxPosition().y),
                zone;
 
       if (r1.Intersects(r2, &zone))
       {
        if (zone.Left < r1.Left + r1.GetWidth() / 2) 
			collisions_info[FROM_LEFT] = true;
        if (zone.Right > r1.Left + r1.GetWidth() / 2)
			collisions_info[FROM_RIGHT] = true;
 
        if (zone.Top > r1.Top + r1.GetHeight() / 2)
			collisions_info[FROM_BOTTOM] = true;
        if (zone.Bottom < r1.Top + r1.GetHeight() / 2)
            collisions_info[FROM_TOP] = true;

		return true;
	   }

	   return false;
	}

	void CollisionManager::killManager()
	{
		delete _manager;
	}

	CollisionManager::~CollisionManager()
	{

	}

} // namespace
