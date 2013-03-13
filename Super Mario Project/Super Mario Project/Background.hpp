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

namespace Rendering
{
    class Background : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

		/* Constructor */
		Background(const string& textureName, const Vector2f& position = Vector2f(0,0));
		
		/* getter and setter */
		bool getVerticalRepetition();

		/* Methods */
		void updateGraphicData(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);
		
		/* Destructor */
        virtual ~Background();
		
    private:
		Animation<State> _animation;
		bool _verticalRepetition;
		Vector2f _position;

		void loadCfgBackground();
    };
} // namespace

#endif // HPP_BACKGROUND
