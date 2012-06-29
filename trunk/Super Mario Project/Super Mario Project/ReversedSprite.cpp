////////////////////////////////////////////////////////////////////////
// ReversedSprite.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ReversedSprite.hpp"

namespace Rendering 
{
    int ReversedSprite::_winHeight = 0;

    ReversedSprite::ReversedSprite()
        : Sprite(),
        _flippedX(false),
        _flippedY(false)
    {
    }


    void ReversedSprite::FlipX(bool Flipped)
    {
        if(Flipped)
		{
			setScale(-1, -1);
		}
		else
		{
			setScale(1, -1);
		}
    }
        
    
    void ReversedSprite::FlipY(bool Flipped)
    {
        if(Flipped)
		{
			setScale(1, 1);
		}
		else
		{
			setScale(1, -1);
		}
    }


    void ReversedSprite::Render(sf::RenderTarget&) const
    {
       
    }

	void ReversedSprite::Render(sf::RenderTarget& target, sf::View& view)
	{
		setWindowsHeight((int)view.getSize().y);
	}

    void ReversedSprite::setWindowsHeight(int winHeight)
    {
        _winHeight = winHeight;
    }
}
