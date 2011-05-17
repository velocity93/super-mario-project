////////////////////////////////////////////////////////////////////////
// Screen.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SCREEN
#define HPP_SCREEN

#include "Coord.hpp"

using namespace Utils;

namespace Rendering
{
    class Screen
    {
    public:
		/* Constructors */
		Screen() : _origine(Coord<int>()), _size(Coord<int>()), _scrolling(Coord<float>()) { }
		Screen(Coord<int>& origine, Coord<int>& size, Coord<float>& scrolling) : _origine(origine), _size(size), _scrolling(scrolling) { }

		/* getters and setters */
        Coord<int> getOrigine();
		Coord<int> getSize();
		Coord<float> getScrolling();
		void setOrigine(Coord<int>& Origine);
		void setSize(Coord<int>& Size);
		void setScrolling(Coord<float>& Scrolling);

		/* Destructor */
		virtual ~Screen();
		
    private:
		Coord<int> _origine;
		Coord<int> _size;
		Coord<float> _scrolling;
    };
} // namespace

#endif // HPP_SCREEN
