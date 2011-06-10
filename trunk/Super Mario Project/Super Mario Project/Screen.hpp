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

#include <SFML/Graphics.hpp>

using namespace sf;

namespace Rendering
{
    class Screen
    {
    public:
		/* Constructors */
		Screen() : _origine(Vector2i()), _size(Vector2i()), _scrolling(Vector2f()) { }
		Screen(Vector2i& origine,Vector2i& size,Vector2f& scrolling) : _origine(origine), _size(size), _scrolling(scrolling) { }

		/* getters and setters */
		Vector2i getOrigine();
		Vector2i getSize();
		Vector2f getScrolling();
		void setOrigine(Vector2i& Origine);
		void setSize(Vector2i& Size);
		void setScrolling(Vector2f& Scrolling);

		/* Destructor */
		virtual ~Screen();
		
    private:
		Vector2i _origine;
		Vector2i _size;
		Vector2f _scrolling;
    };
} // namespace

#endif // HPP_SCREEN
