////////////////////////////////////////////////////////////////////////
// Screen.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Screen.hpp"

namespace Rendering
{
	Coord<int> Screen::getOrigine()
	{
		return _origine;
	}

	Coord<int> Screen::getSize()
	{
		return _size;
	}

	Coord<float> Screen::getScrolling()
	{
		return _scrolling;
	}

	void Screen::setOrigine(Coord<int>& origine)
	{
		_origine = origine;
	}

	void Screen::setSize(Coord<int>& size)
	{
		_size = size;
	}

	void Screen::setScrolling(Coord<float>& scrolling)
	{
		_scrolling = scrolling;
	}

} // namespace
