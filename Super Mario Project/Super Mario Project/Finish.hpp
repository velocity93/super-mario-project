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
		Finish(string textureName) : Collisionable(textureName) { }
		Finish(string textureName, Coord<float> position) : Collisionable(textureName, position) { }

		void update(float time);
		void render(RenderWindow& app);

        virtual ~Finish();
		
    private:
    };
} // namespace

#endif // HPP_FINISH
