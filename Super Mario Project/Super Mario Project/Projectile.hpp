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
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>

namespace smp
{
    class Projectile : public Resource
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
		Projectile(const std::string& textureName, Type type = FRAGMENT);

		/* Physic submission */
		int getSubmission();
		void setSubmission(int submission);

		/* Bottom Left of hitbox size from left of sprite */
		int getBottomLeft();
		void setBottomLeft(int bottomLeft);

		/* Top of hitbox size */
		int getTop();
		void setTop(int top);

		/* Initial Speed */
		void setInitialSpeedX(float x);
		void setInitialSpeedY(float y);

		/* get all occurrences */
		std::vector<ProjectileOccurrence*>& getProjectileOccurrences();

		/* Add occurrence to list */
		void addNewProjectileOccurrence(const sf::Vector2f& position = sf::Vector2f(0,0),
			ProjectileOccurrence::State state = ProjectileOccurrence::LAUNCHED,
			ProjectileOccurrence::Side side = ProjectileOccurrence::RIGHT_SIDE);

		/* Remove occurrence to list */
		void removeProjectileOccurrence(const ProjectileOccurrence* projectile);

		/* Update data */
		void updatePhysicData(float time, sf::RenderWindow& app);
		void updateGraphicData(sf::RenderWindow& app);

		void addNbSpritesForState(ProjectileOccurrence::State state, int nbSprites);
		void addFrameDelayForState(ProjectileOccurrence::State state, int FrameDelay);

		/* Render all occurrences */
		void render(sf::RenderWindow& app);

		/* Serialize data */
		void serialize(std::ofstream& file, const std::string& tabs);

		/* Destructor */
        virtual ~Projectile();
		
    private:
		Type _type;
		sf::Vector2f _initialSpeed;
		int _bottomLeft;
		int _top;
		int _submission;
		std::vector<ProjectileOccurrence*> _projectileOccurences;
		std::map<ProjectileOccurrence::State, int> _nbSpritesByState;
		std::map<ProjectileOccurrence::State, int> _frameDelayByState;

		/* Loading Projectile */
		void loadProjectile();
    };
} // namespace

#endif // HPP_PROJECTILE