////////////////////////////////////////////////////////////////////////
// Projectile.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Projectile.hpp"

namespace Collisions
{

	int Projectile::getSubmission()
	{
		return _submission;
	}

	vector<ProjectileOccurrence*> Projectile::getProjectileOccurrences()
	{
		return _projectileOccurences;
	}

	void Projectile::addProjectileOccurrence(ProjectileOccurrence* projectile)
	{
		_projectileOccurences.push_back(projectile);
	}

	void Projectile::removeProjectileOccurrence(ProjectileOccurrence* projectile)
	{
		vector<ProjectileOccurrence*>::iterator itProjectileOccurrence;

		for(itProjectileOccurrence = _projectileOccurences.begin(); itProjectileOccurrence < _projectileOccurences.end(); itProjectileOccurrence++)
		{
			if((*itProjectileOccurrence) == projectile)
				_projectileOccurences.erase(itProjectileOccurrence);
		}
	}

	void Projectile::update(RenderWindow& app)
	{
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ProjectilesOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->update(app);
		}
	}

	void Projectile::render(RenderWindow& app)
	{
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ProjectilesOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->render(app);
		}
	}


    Projectile::~Projectile()
    {
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ProjectilesOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			delete (*itProjectiles);
		}
    }
} // namespace
