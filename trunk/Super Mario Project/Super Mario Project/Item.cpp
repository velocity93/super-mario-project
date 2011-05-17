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

	void Item::addItemOccurrence(ItemOccurrence* item)
	{
		_itemOccurences.push_back(item);
	}

	void Item::removeItemOccurrence(ItemOccurrence* item)
	{
		vector<ItemOccurrence*>::iterator itItemOccurrence;

		for(itItemOccurrence = _itemOccurences.begin(); itItemOccurrence < _itemOccurences.end(); itItemOccurrence++)
		{
			if((*itItemOccurrence) == item)
				_itemOccurences.erase(itItemOccurrence);
		}
	}

	void Item::update(RenderWindow& app)
	{
		vector<ItemOccurrence*>::iterator itItems;
		
		/* ItemsOccurrences */
		for(itItems = this->_itemOccurences.begin(); itItems < this->_itemOccurences.end(); itItems++)
		{
			(*itItems)->update(app);
		}
	}

	void Item::render(RenderWindow& App)
	{
		vector<ItemOccurrence*>::iterator itItems;
		
		/* ItemsOccurrences */
		for(itItems = this->_itemOccurences.begin(); itItems < this->_itemOccurences.end(); itItems++)
		{
			(*itItems)->render(App);
		}
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
