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

#include "ItemOccurrence.hpp"
#include <list>

using namespace std;

namespace Collisions
{
	class Item
	{
		enum Type
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


	public:
		/* Constructor */
		Item() : _type(COIN), _submission(0) { }

		/* Getters and setters */
		Type getType();
		int getSubmission();
		list<ItemOccurrence> getItemOccurrences();
		void setType(Type type);
		void setSubmission(int submission);

		/* Destructor */
		virtual ~Item();

	private:
		Type _type;
		int _submission;
		list<ItemOccurrence> _itemOccurences;
	};
} // namespace

#endif // HPP_ITEM
