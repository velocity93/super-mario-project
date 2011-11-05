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
#include "Animation.hpp"

namespace Collisions
{
    class Finish : public Collisionable
    {
    public:
		enum State
		{
			WAITING,
			FINISH
		};

		Finish(const string& textureName);
		Finish(const string& textureName, Vector2f& position);

		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);

        virtual ~Finish();
		
    private:
		Animation<State> _animation;

		void loadFinish(const string& textureName);
    };
} // namespace

#endif // HPP_FINISH
