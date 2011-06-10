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
    class Background : public Object
    {
    public:
		/* Constructors */
		Background(const string& textureName, const View& view);
		Background(const string& textureName, const View& view,Vector2f& position);
		
		/* getter and setter */
		bool getVerticalRepetition();

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		
		/* Destructor */
        virtual ~Background();
		
    private:
		bool _verticalRepetition;
		vector<Sprite> _sprites;

		void loadCfgBackground(const string& textureName);
		void configureBackground(const string& textureName, const View& view);
    };
} // namespace

#endif // HPP_BACKGROUND
