////////////////////////////////////////////////////////////////////////
// Drawable.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DRAWABLE
#define HPP_DRAWABLE

namespace Rendering
{

	enum Layer
	{
		BACKGROUND_LAYER,
		BACKGROUND_PARTICLES_LAYER,
		OBJECTS_LAYER,
		BLOC_LAYER_1,
		ITEM_LAYER,
		BLOC_LAYER_2,
		FOREGROUND_LAYER,
		FOREGROUND_PARTICLES_LAYER
	};

	enum Angle
	{
		ANGLE_0,
		ANGLE_90,
		ANGLE_180,
		ANGLE_270
	};

    class Drawable
    {
    public:
        Drawable();
        ~Drawable();
		
    private:
    };
} // namespace

#endif // HPP_DRAWABLE
