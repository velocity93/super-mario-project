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

#include "Object.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace Rendering
{
	class Foreground : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

        /* Constructors */
		Foreground(const string& textureName);

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);
		void setActivity(RenderWindow& app);
		
		/* Destructor */
        virtual ~Foreground();
		
    private:
		Animation<State> _animation;
		
		
		void loadCfgForeground(const string& textureName);
    };
} // namespace

#endif // HPP_FOREGROUND
