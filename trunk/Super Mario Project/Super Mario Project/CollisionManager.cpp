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
			if(et2 != 0)
			{
				solveCollisions(et2, c1, level);
			}
			else
			{
				throw exception("Problème dans les collisions");
			}
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level* level)
	{

	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level* level)
	{

	}

	void CollisionManager::detectCollisions(Collisionable* c1, Collisionable* c2, Collisions_info* collisions_info)
	{

	}

} // namespace
