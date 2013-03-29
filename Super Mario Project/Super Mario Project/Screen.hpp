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

namespace smp
{
    class Screen
    {
    public:
		/* Constructors */
		Screen() : _origine(sf::Vector2i()), _size(sf::Vector2i()), _scrolling(sf::Vector2f()) { }
		Screen(sf::Vector2i& origine,sf::Vector2i& size,sf::Vector2f& scrolling) : _origine(origine), _size(size), _scrolling(scrolling) { }

		/* getters and setters */
		sf::Vector2i getOrigine();
		sf::Vector2i getSize();
		sf::Vector2f getScrolling();
		void setOrigine(sf::Vector2i& Origine);
		void setSize(sf::Vector2i& Size);
		void setScrolling(sf::Vector2f& Scrolling);

		/* Destructor */
		virtual ~Screen();
		
    private:
		sf::Vector2i _origine;
		sf::Vector2i _size;
		sf::Vector2f _scrolling;
    };
} // namespace

#endif // HPP_SCREEN
