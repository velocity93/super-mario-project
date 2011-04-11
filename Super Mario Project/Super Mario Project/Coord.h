////////////////////////////////////////////////////////////////////////
// Background.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_COORD
#define HPP_COORD

namespace Utils
{
    template<int> class Coordi
    {
    public:
		int x, y;
        Coordi();
        ~Coordi();
		
    private:
    };

	template<float> class Coordf
    {
    public:
		float x, y;
        Coordf();
        ~Coordf();
		
    private:
    };
} // namespace

#endif // HPP_COORD