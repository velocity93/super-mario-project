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

#include <SFML/Graphics.hpp>
#include "Drawable.hpp"
#include "Animation.hpp"
#include <fstream>

using namespace sf;

namespace Rendering
{
    class Object : public Drawable
    {
    public:
		enum State
		{
			NORMAL
		};

		Object(const string& textureName);
		Object(const string& textureName,Vector2f& position);
		
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);

        virtual ~Object();
		
    protected:
		Animation<State> _animation;
		void loadCfgObject(const string& textureName);
		
    };
} // namespace

#endif // HPP_OBJECT
