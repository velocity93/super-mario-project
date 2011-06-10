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
	Vector2i Screen::getOrigine()
	{
		return _origine;
	}

	Vector2i Screen::getSize()
	{
		return _size;
	}

	Vector2f Screen::getScrolling()
	{
		return _scrolling;
	}

	void Screen::setOrigine(Vector2i& origine)
	{
		_origine = origine;
	}

	void Screen::setSize(Vector2i& size)
	{
		_size = size;
	}

	void Screen::setScrolling(Vector2f& scrolling)
	{
		_scrolling = scrolling;
	}

	Screen::~Screen()
	{

	}

} // namespace
