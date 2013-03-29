////////////////////////////////////////////////////////////////////////
// Coord.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_COORD
#define HPP_COORD

namespace smp
{
    template<class C> class Coord
    {
	public:
		Coord(C x = 0, C y = 0) : x(x), y(y) { }
	
		C x, y;
    };
	
    typedef Coord<int> Coordi;
    typedef Coord<float> Coordf;
} // namespace

#endif // HPP_COORD
