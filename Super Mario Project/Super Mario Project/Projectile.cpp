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

	void Projectile::setSubmission(int submission)
	{
		_submission = submission;
	}

	void Projectile::update(float time)
	{
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ItemsOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->update(time);
		}
	}

	void Projectile::render(RenderWindow& app, Screen& screen)
	{
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ItemsOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->render(app, screen);
		}
	}


    Projectile::~Projectile()
    {
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ItemsOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			delete (*itProjectiles);
		}
    }
} // namespace
