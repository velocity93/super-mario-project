////////////////////////////////////////////////////////////////////////
// Projectile.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PROJECTILE
#define HPP_PROJECTILE

#include "ProjectileOccurrence.hpp"
#include <list>

using namespace std;

namespace Collisions
{
	

    class Projectile
    {
	
		enum Type {
		FRAGMENT,
		FIREBALL,
		SPECIAL_FIREBALL,
		ICEBALL,
		THUNDER_BALL,
		SUPER_FIREBALL,
		HYPER_FIREBALL,
		SHURIKEN
	};


    public:
		/* Constructor */
		Projectile() : _type(FRAGMENT), _submission(0) { }

		/* getters and setters */
		int getSubmission();
		list<ProjectileOccurrence> getProjectileOccurrences();
		void setSubmission(int submission);

		/* Destructor */
        ~Projectile();
		
    private:
		Type _type;
		int _submission;
		list<ProjectileOccurrence> _projectileOccurences;
    };
} // namespace

#endif // HPP_PROJECTILE
