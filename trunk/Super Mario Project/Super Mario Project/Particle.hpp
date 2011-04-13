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
    class Particle : EntityMovable
    {
    public:
		Particle() : EntityMovable(), life(0) { }

		int GetLife()
		{
			return life;
		}

		void SetLife(int Life)
		{
			life = Life;
		}

		void Update();
		void Render();

        ~Particle();
		
    private:
		int life;
    };
} // namespace

#endif // HPP_PARTICLE
