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

namespace Collisions
{
    class Particle : public EntityMovable
    {
    public:
		enum State
		{
			NORMAL
		};

		Particle(const string& textureName, Vector2f& position) : EntityMovable(textureName, position), _life(0) { }

		int getLife();		

		void updateGraphicData(RenderWindow& app);
		void updatePhysicData(RenderWindow&);
		void update(float time, bool hasGravity);
		void render(RenderWindow& app);
		void setActivity(RenderWindow& app);

        virtual ~Particle();
		
    private:
		Animation<State> _animation;
		int _life;

		void loadParticle(const string& textureName);
    };
} // namespace

#endif // HPP_PARTICLE
