////////////////////////////////////////////////////////////////////////
// Blocks.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_BLOCKS
#define HPP_BLOCKS

namespace Collisions
{
	enum Block_state {
		UNMOVABLE,
		PUSHED_TO_LEFT,
		PUSHED_TO_RIGHT,
		PUSHED_TO_TOP,
	};

    class Blocks
    {
    public:
        Blocks();
        virtual ~Blocks();
		
    private:
    };
} // namespace

#endif // HPP_BLOCKS
