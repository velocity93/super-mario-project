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
	Coordi Screen::getOrigine()
	{
		return _origine;
	}

	Coordi Screen::getSize()
	{
		return _size;
	}

	Coordf Screen::getScrolling()
	{
		return _scrolling;
	}

	void Screen::setOrigine(Coordi& origine)
	{
		_origine = origine;
	}

	void Screen::setSize(Coordi& size)
	{
		_size = size;
	}

	void Screen::setScrolling(Coordf& scrolling)
	{
		_scrolling = scrolling;
	}

	Screen::~Screen()
	{

	}

} // namespace
