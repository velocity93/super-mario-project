////////////////////////////////////////////////////////////////////////
// ReversedSprite.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_REVERSED_SPRITE
#define HPP_REVERSED_SPRITE

#include <SFML/Graphics.hpp>

namespace smp 
{
	// P0 TODO: fix the origin problem properly (need to patch sfml?)
    class ReversedSprite : public sf::Sprite
    {
    public:
        ReversedSprite();

        void FlipX(bool Flipped);
        void FlipY(bool Flipped);
    };
}

#endif
