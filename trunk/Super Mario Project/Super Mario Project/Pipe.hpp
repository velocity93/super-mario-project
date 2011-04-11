////////////////////////////////////////////////////////////////////////
// Pipe.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PIPE
#define HPP_PIPE

namespace Collisions
{
	enum Pipe_state
	{
		OPEN,
		CLOSED
	};

	enum Pipe_direction
	{
		TO_TOP,
		TO_LEFT,
		TO_RIGHT,
		TO_BOTTOM
	};

    class Pipe
    {
    public:
        Pipe();
        ~Pipe();
		
    private:
    };
} // namespace

#endif // HPP_PIPE
