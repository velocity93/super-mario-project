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
#include <SFML\Graphics.hpp>

using namespace sf;

namespace Rendering
{
    class Object : public Drawable
    {
    public:
		Object() : Drawable() { }
		Object(string name) : Drawable() { loadObject(name);}
		
		void update(float time);
		void render(RenderWindow& app);
		void loadObject(string name);

        virtual ~Object();
		
    private:
    };
} // namespace

#endif // HPP_OBJECT
