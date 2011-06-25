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
#include "Resource.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace Collisions
{
    class Projectile : public SuperMarioProject::Resource
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
		Projectile(const string& textureName, Type type = FRAGMENT, int submission = 0);

		/* Physic submission */
		int getSubmission();

		/* List of occurences */
		vector<ProjectileOccurrence*> getProjectileOccurrences();

		/* Add occurrence to list */
		void addNewProjectileOccurrence();

		/* Remove occurrence to list */
		void removeProjectileOccurrence(const ProjectileOccurrence* projectile);

		/* Update data */
		void update(RenderWindow& app);

		/* Render all occurrences */
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~Projectile();
		
    private:
		Type _type;
		Vector2f _initialSpeed;
		int _submission;
		int _nbSprites;
		vector<ProjectileOccurrence*> _projectileOccurences;

		/* Loading Projectile */
		void loadProjectile();
    };
} // namespace

#endif // HPP_PROJECTILE
