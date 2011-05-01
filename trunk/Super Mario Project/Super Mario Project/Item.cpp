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

	vector<ItemOccurrence*> Item::getItemOccurrences()
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

	void Item::update(float time)
	{

	}

	void Item::render(RenderWindow &App)
	{

	}

    Item::~Item()
    {
		vector<ItemOccurrence*>::iterator itItems;
		
		/* ItemsOccurrences */
		for(itItems = this->_itemOccurences.begin(); itItems < this->_itemOccurences.end(); itItems++)
		{
			delete (*itItems);
		}
    }
} // namespace
