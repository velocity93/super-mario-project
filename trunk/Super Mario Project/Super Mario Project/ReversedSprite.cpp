////////////////////////////////////////////////////////////////////////
// ReversedSprite.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ReversedSprite.hpp"

namespace smp 
{
    ReversedSprite::ReversedSprite()
        : Sprite()
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
}
