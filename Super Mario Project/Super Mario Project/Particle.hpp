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

namespace Collisions
{
    class Particle : public EntityMovable
    {
    public:
		Particle() : EntityMovable(), _life(0) { }
		Particle(Coord<float> position) : EntityMovable(position), _life(0) { }

		int getLife();
		void setLife(int life);

		void update(float time);
		void render();

        ~Particle();
		
    private:
		int _life;
    };
} // namespace

#endif // HPP_PARTICLE
