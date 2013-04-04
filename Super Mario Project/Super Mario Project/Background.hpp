////////////////////////////////////////////////////////////////////////
// Background.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_BACKGROUND
#define HPP_BACKGROUND

#include "Drawable.hpp"
#include "Animation.hpp"

namespace smp
{
    class Background : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

		/* Constructor */
		Background(const std::string& textureName, const sf::Vector2f& position = sf::Vector2f(0,0));
		
		/* getter and setter */
		bool getVerticalRepetition();
		void setVerticalRepetition(bool verticalRepetition);
		Animation<State>& getAnimation();

		/* Methods */
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);
		
		/* Destructor */
        virtual ~Background();
		
    private:
		Animation<State> _animation;
		bool _verticalRepetition;
		sf::Vector2f _position;

		void loadCfgBackground();
    };
} // namespace

#endif // HPP_BACKGROUND
