////////////////////////////////////////////////////////////////////////
// ItemOccurrence.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ITEMOCCURRENCE
#define HPP_ITEMOCCURRENCE

namespace Collisions
{
	enum Item_type
	{
		COIN,
		MUSHROOM,
		FLOWER,
		ICE_FLOWER,
		MINI_MUSHROOM,
		POISON_MUSHROOM,
		STAR,
		LIFE_MUSHROOM
	};

	enum Item_state
	{
		NORMAL,
		GET_OUT_FROM_BLOC
	};

    class ItemOccurrence
    {
    public:
        ItemOccurrence();
        ~ItemOccurrence();
		
    private:
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE
