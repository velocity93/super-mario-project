////////////////////////////////////////////////////////////////////////
// Particle.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PARTICLE
#define HPP_PARTICLE

#include "EntityMovable.hpp"
#include "Animation.hpp"

namespace smp
{
    class Particle : public EntityMovable
    {
    public:
		enum State
		{
			NORMAL
		};

		Particle(const std::string& textureName, sf::Vector2f& position) : EntityMovable(textureName, position), _life(0), _animation(1) { }

		int getLife();

		void updateGraphicData(sf::RenderWindow& app);
		void updatePhysicData(float time, sf::RenderWindow&);
		void update(float time, bool hasGravity);
		void render(sf::RenderWindow& app);
		void onCollision(Collisionable *c, int collision_type);

        virtual ~Particle();
		
    private:
		Animation<State> _animation;
		int _life;

		void loadParticle(const std::string& textureName);
    };
} // namespace

#endif // HPP_PARTICLE
