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
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

namespace Collisions
{
	class Projectile
    {
	
	public:
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

		/* Constructor */
		Projectile() : _type(FRAGMENT), _submission(0) { }
		Projectile(Type type, int submission) : _type(type), _submission(submission) { }

		/* Physic submission */
		int getSubmission();

		/* List of occurences */
		vector<ProjectileOccurrence*> getProjectileOccurrences();

		/* Add occurrence to list */
		void addProjectileOccurrence(ProjectileOccurrence* projectile);

		/* Remove occurrence to list */
		void removeProjectileOccurrence(ProjectileOccurrence* projectile);

		/* Update data */
		void update(RenderWindow& app);

		/* Render all occurrences */
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~Projectile();
		
    private:
		Type _type;
		int _submission;
		vector<ProjectileOccurrence*> _projectileOccurences;
    };
} // namespace

#endif // HPP_PROJECTILE
