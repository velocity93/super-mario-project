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

namespace Rendering
{
    class Object : public Drawable
    {
    public:
		Object() : Drawable() { }
		
		void update(float time);
		void render();

        ~Object();
		
    private:
    };
} // namespace

#endif // HPP_OBJECT
