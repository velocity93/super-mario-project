////////////////////////////////////////////////////////////////////////
// Object.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_OBJECT
#define HPP_OBJECT

#include "Drawable.hpp"
#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>

namespace smp
{
    class Object : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

		Object(const std::string& textureName, sf::Vector2f& position);
		
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);
		void setActivity(sf::RenderWindow& app);

        virtual ~Object();
		
    protected:
		Animation<State> _animation;
		void loadCfgObject();
		
    };
} // namespace

#endif // HPP_OBJECT
