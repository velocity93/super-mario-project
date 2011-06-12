////////////////////////////////////////////////////////////////////////
// Projectile.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Projectile.hpp"
#include <fstream>

namespace Collisions
{

	Projectile::Projectile(const string& textureName) : _type(FRAGMENT), _submission(0), _initialSpeed(Vector2f())
	{
		_textureName = textureName;
		loadProjectile();
	}

	Projectile::Projectile(const string& textureName, Type type, int submission) : _type(type), _submission(submission), _initialSpeed(Vector2f())
	{
		_textureName = textureName;
		loadProjectile();
	}

	int Projectile::getSubmission()
	{
		return _submission;
	}

	vector<ProjectileOccurrence*> Projectile::getProjectileOccurrences()
	{
		return _projectileOccurences;
	}

	void Projectile::addNewProjectileOccurrence()
	{
		_projectileOccurences.push_back(new ProjectileOccurrence(_textureName));
	}

	void Projectile::removeProjectileOccurrence(const ProjectileOccurrence* projectile)
	{
		vector<ProjectileOccurrence*>::iterator itProjectileOccurrence;

		for(itProjectileOccurrence = _projectileOccurences.begin(); itProjectileOccurrence < _projectileOccurences.end(); itProjectileOccurrence++)
		{
			if((*itProjectileOccurrence) == projectile)
				_projectileOccurences.erase(itProjectileOccurrence);
		}
	}

	void Projectile::loadProjectile()
	{
		
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
