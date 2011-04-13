////////////////////////////////////////////////////////////////////////
// Item.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ITEM
#define HPP_ITEM

#include"ItemOccurrence.hpp"
#include <list>

using namespace std;

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

    class Item
    {
    public:
		Item() : type(COIN), submission(0) { }

		Item_type GetType()
		{
			return type;
		}

		int GetSubmission()
		{
			return submission;
		}

		list<ItemOccurrence> GetItemOccurrences()
		{
			return itemOccurences;
		}

		void SetType(Item_type Type)
		{
			type = Type;
		}

		void SetSubmission(int Submission)
		{
			submission = Submission;
		}

        ~Item();
		
    private:
		Item_type type;
		int submission;
		list<ItemOccurrence> itemOccurences;
    };
} // namespace

#endif // HPP_ITEM
