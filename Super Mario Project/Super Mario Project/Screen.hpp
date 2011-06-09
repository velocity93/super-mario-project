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
		Screen() : _origine(Coordi()), _size(Coordi()), _scrolling(Coordf()) { }
		Screen(Coordi& origine,Coordi& size,Coordf& scrolling) : _origine(origine), _size(size), _scrolling(scrolling) { }

		/* getters and setters */
       Coordi getOrigine();
		Coordi getSize();
		Coordf getScrolling();
		void setOrigine(Coordi& Origine);
		void setSize(Coordi& Size);
		void setScrolling(Coordf& Scrolling);

		/* Destructor */
		virtual ~Screen();
		
    private:
		Coordi _origine;
		Coordi _size;
		Coordf _scrolling;
    };
} // namespace

#endif // HPP_SCREEN
