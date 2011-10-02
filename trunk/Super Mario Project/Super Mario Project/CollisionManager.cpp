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
	void CollisionManager::solveCollisions(Collisionable* c1, Collisionable* c2, Level* level)
	{
		EntityMovable* et1, *et2;
		et1 = dynamic_cast<EntityMovable*>(c1);
		et2 = dynamic_cast<EntityMovable*>(c2);

		if(et1 != 0)
		{
			// et1 successfully casted in EntityMovable
			if(et2 != 0)
			{
				solveCollisions(et1, et2, level);
			}
			else
			{
				solveCollisions(et1, c2, level);
			}
		}
		else
		{
			// et1 not successfully casted in EntityMovable
			if(et2 != 0)
			{
				solveCollisions(et2, c1, level);
			}
			else
			{
				throw exception("Error in collisions");
			}
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level* level)
	{
		Collisions_info infos;
		
		if(detectCollisions(et1, c2, &infos))
		{

		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level)
	{
		Collisions_info infos;
		
		if(detectCollisions(et1, et2, &infos))
		{

		}
	}

	bool CollisionManager::detectCollisions(Collisionable* c1, Collisionable* c2, Collisions_info* collisions_info)
	{
		sf::FloatRect r1(c1->getHitboxPosition().x, c1->getHitboxPosition().y + c1->getHitboxSize().y,
			c1->getHitboxPosition().x + c1->getHitboxSize().x, c1->getHitboxPosition().y),
			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y + c2->getHitboxSize().y, c2->getHitboxPosition().x + c2->getHitboxSize().x, c2->getHitboxPosition().y),
                zone;
 
       if (r1.Intersects(r2, &zone))
       {
 
        if (zone.Left < r1.Left + r1.GetWidth() / 2) 
			collisions_info->type = FROM_LEFT;
        if (zone.Right > r1.Left + r1.GetWidth() / 2)
			collisions_info->type = FROM_RIGHT;
 
        if (zone.Top > r1.Top + r1.GetHeight() / 2)
			collisions_info->type = FROM_BOTTOM;
        if (zone.Bottom < r1.Top + r1.GetHeight() / 2)
            collisions_info->type = FROM_TOP;

		return true;
	   }

	   return false;
	}

} // namespace
