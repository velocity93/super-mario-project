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
#include <fstream>

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
		Projectile(const string& textureName, Type type = FRAGMENT);

		/* Physic submission */
		int getSubmission();

		/* Bottom Left of hitbox size from left of sprite */
		int getBottomLeft();

		/* Top of hitbox size */
		int getTop();

		/* Add occurrence to list */
		void addNewProjectileOccurrence(Vector2f& position = Vector2f(0,0), Vector2f& speed = Vector2f(0,0),
			ProjectileOccurrence::State state = ProjectileOccurrence::State::LAUNCHED,
			ProjectileOccurrence::Side side = ProjectileOccurrence::Side::RIGHT_SIDE);

		/* Remove occurrence to list */
		void removeProjectileOccurrence(const ProjectileOccurrence* projectile);

		/* Update data */
		void update(RenderWindow& app);

		/* Render all occurrences */
		void render(RenderWindow& app);

		/* Serialize data */
		void serialize(ofstream& file, const string& tabs);

		/* Destructor */
        virtual ~Projectile();
		
    private:
		Type _type;
		Vector2f _initialSpeed;
		int _bottomLeft;
		int _top;
		int _submission;
		vector<ProjectileOccurrence*> _projectileOccurences;
		map<ProjectileOccurrence::State, int> _nbSpritesByState;
		map<ProjectileOccurrence::State, int> _frameDelayByState;

		/* Loading Projectile */
		void loadProjectile();
    };
} // namespace

#endif // HPP_PROJECTILE
