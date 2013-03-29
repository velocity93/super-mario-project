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

namespace smp
{
    class Finish : public Collisionable
    {
    public:
		enum State
		{
			WAITING,
			FINISH,
			NB_STATES
		};

		Finish(const std::string& textureName, sf::Vector2f& position);

		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);
		void setState(const State& state);

        virtual ~Finish();
		
    private:
		Animation<State> _animation;

		void loadFinish(const std::string& textureName);
    };
} // namespace

#endif // HPP_FINISH
