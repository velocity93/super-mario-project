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
	enum Projectile_Type {
		FRAGMENT,
		FIREBALL,
		SPECIAL_FIREBALL,
		ICEBALL,
		THUNDER_BALL,
		SUPER_FIREBALL,
		HYPER_FIREBALL,
		SHURIKEN
	};

    class Projectile
    {
    public:
		Projectile() : type(FRAGMENT), submission(0) { }

		int GetSubmission()
		{
			return submission;
		}

		list<ProjectileOccurrence> GetProjectileOccurrences()
		{
			return projectileOccurences;
		}

		void SetSubmission(int Submission)
		{
			submission = Submission;
		}

        ~Projectile();
		
    private:
		Projectile_Type type;
		int submission;
		list<ProjectileOccurrence> projectileOccurences;
    };
} // namespace

#endif // HPP_PROJECTILE
