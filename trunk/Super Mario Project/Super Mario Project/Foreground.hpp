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
		void updateGraphicData(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);
		void setActivity(RenderWindow& app);
		
		/* Destructor */
        virtual ~Foreground();
		
    private:
		Animation<State> _animation;
		
		
		void loadCfgForeground();
    };
} // namespace

#endif // HPP_FOREGROUND
