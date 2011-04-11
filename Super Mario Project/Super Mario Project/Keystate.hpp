////////////////////////////////////////////////////////////////////////
// Keystate.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_KEYSTATE
#define HPP_KEYSTATE

namespace SuperMarioProject
{
	enum Keys
	{
		NONE = -1,
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
		JUMP,
		RUN,
		CLICK_G,
		CLICK_D,
		ENTER,
		ESCAPE,
		CTRL_G,
		ERASE,
		CUT,
		COPY,
		PASTE,
		NB_KEYS,
	};

    class Keystate
    {
    public:
        Keystate();
        ~Keystate();
		
    private:
    };
} // namespace

#endif // HPP_KEYSTATE
