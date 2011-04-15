////////////////////////////////////////////////////////////////////////
// Item.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Item.hpp"

namespace Collisions
{
	Item::Type Item::getType()
	{
		return _type;
	}

	int Item::getSubmission()
	{
		return _submission;
	}

	list<ItemOccurrence> Item::getItemOccurrences()
	{
		return _itemOccurences;
	}

	void Item::setType(Type type)
	{
		_type = type;
	}

	void Item::setSubmission(int submission)
	{
		_submission = submission;
	}

    Item::~Item()
    {
    }
} // namespace
