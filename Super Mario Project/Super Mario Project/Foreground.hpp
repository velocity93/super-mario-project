////////////////////////////////////////////////////////////////////////
// Foreground.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_FOREGROUND
#define HPP_FOREGROUND

#include "Drawable.hpp"
#include "Animation.hpp"

namespace smp
{
	class Foreground : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

        /* Constructors */
		Foreground(const std::string& textureName);

		/* Methods */
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);
		void setActivity(sf::RenderWindow& app);
		
		/* Destructor */
        virtual ~Foreground();
		
    private:
		Animation<State> _animation;
		
		
		void loadCfgForeground();
    };
} // namespace

#endif // HPP_FOREGROUND
