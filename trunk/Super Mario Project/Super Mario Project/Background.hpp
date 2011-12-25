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

#include "Object.hpp"

namespace Rendering
{
    class Background : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

		/* Constructors */
		Background(const string& textureName);
		Background(const string& textureName, Vector2f& position);
		
		/* getter and setter */
		bool getVerticalRepetition();

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);
		void setActivity(RenderWindow& app);
		
		/* Destructor */
        virtual ~Background();
		
    private:
		Animation<State> _animation;
		bool _verticalRepetition;
		Vector2f _position;

		void loadCfgBackground(const string& textureName);
    };
} // namespace

#endif // HPP_BACKGROUND
