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

namespace Rendering {

	class ReversedSprite : public sf::Sprite
	{
	public:
		void Render(sf::RenderTarget& Target) const;
	};
}

#endif