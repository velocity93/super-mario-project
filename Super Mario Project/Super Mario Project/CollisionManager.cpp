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
	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level* level, RenderWindow& app)
	{
		Collisions_info infos;
		
		if(detectCollisions(et1, c2, &infos))
		{
			et1->updatePhysicData(app);

			/* Appel de la méthode de MAJ de collisions

			Méthode abstraite OnCollision(Collisionable* c, vector<bool>& infos) = 0 définie dans EntityMoveable

			et1->OnCollision(c2, infos->type_collision)

			Tester à l'aide de dynamic_cast contre quoi et1 s'est cogné.
			Faire le necessaire ensuite selon le type.

			*/
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level, RenderWindow& app)
	{
		Collisions_info infos;
		
		if(detectCollisions(et1, et2, &infos))
		{
			et2->updatePhysicData(app);
			/* Appel de la méthode de MAJ de collisions
			et2->OnCollision(et1, infos->type_collision)
			*/

			/* Appel de la méthode de MAJ de collisions
			et1->OnCollision(et2, infos->type_collision)
			*/

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
			collisions_info->type[FROM_LEFT] = true;
        if (zone.Right > r1.Left + r1.GetWidth() / 2)
			collisions_info->type[FROM_RIGHT] = true;
 
        if (zone.Top > r1.Top + r1.GetHeight() / 2)
			collisions_info->type[FROM_BOTTOM] = true;
        if (zone.Bottom < r1.Top + r1.GetHeight() / 2)
            collisions_info->type[FROM_TOP] = true;

		return true;
	   }

	   return false;
	}

} // namespace
