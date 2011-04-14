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
    class Finish : Collisionable
    {
    public:
		Finish() : Collisionable() { }

		void Update(float time);
		void Render();
        ~Finish();
		
    private:
    };
} // namespace

#endif // HPP_FINISH
