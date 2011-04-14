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
    class Background : Object
    {
    public:
		Background() : verticalRepetition(false), Object() { }
		Background(bool VerticalRepetition) : verticalRepetition(VerticalRepetition), Object() { }
		bool GetVerticalRepetition()
		{
			return verticalRepetition;
		}

		void SetVerticalRepetition(bool VerticalRepetition)
		{
			verticalRepetition = VerticalRepetition;
		}

		void Update(float time);
		void Render();
		
        ~Background();
		
    private:
		bool verticalRepetition;
    };
} // namespace

#endif // HPP_BACKGROUND
