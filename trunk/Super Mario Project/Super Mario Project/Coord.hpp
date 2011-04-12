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

namespace Utils
{
    template<class C> class Coord
    {
	public:
		Coord() : x(0), y (0) { }
		Coord(C X, C Y) : x(X), y(Y) { }
		C GetX() 
		{ 
			return x; 
		}

		C GetY() 
		{ 
			return y; 
		}

		void Set(C X, C Y)
		{
			x = X;
			y = Y;
		}
		
    private:
		C x, y;
    };

	
} // namespace

#endif // HPP_COORD