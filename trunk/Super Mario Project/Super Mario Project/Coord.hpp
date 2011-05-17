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
		Coord() : _x(0), _y(0) { }
		Coord(C x, C y) : _x(x), _y(y) { }
		C getX() 
		{ 
			return _x; 
		}

		C getY() 
		{ 
			return _y; 
		}

		void set(C x, C y)
		{
			_x = x;
			_y = y;
		}

		void set(Coord<C>& c1)
		{
			_x = c1.getX();
			_y = c1.getY();
		}

		void operator=(Coord<C>& c1)
		{
			this->set(c1.getX(), c1.getY());
		}

			
    private:
		C _x, _y;
    };
	
} // namespace

#endif // HPP_COORD