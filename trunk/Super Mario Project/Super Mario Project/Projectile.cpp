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

	}

	void Projectile::render(RenderWindow& App)
	{

	}


    Projectile::~Projectile()
    {
    }
} // namespace
