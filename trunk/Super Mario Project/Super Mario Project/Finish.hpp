////////////////////////////////////////////////////////////////////////
// Finish.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_FINISH
#define HPP_FINISH

#include "Collisionable.hpp"

namespace Collisions
{
    class Finish : public Collisionable
    {
    public:
		Finish() : Collisionable() { }

		void update(float time);
		void render();

        virtual ~Finish();
		
    private:
    };
} // namespace

#endif // HPP_FINISH
