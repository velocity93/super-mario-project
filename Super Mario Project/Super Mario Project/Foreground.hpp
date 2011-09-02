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
	class Foreground : public Object
    {
    public:
        /* Constructors */
		Foreground(const string& textureName);

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		
		/* Destructor */
        virtual ~Foreground();
		
    private:
    };
} // namespace

#endif // HPP_FOREGROUND
