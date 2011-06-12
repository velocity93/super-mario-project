////////////////////////////////////////////////////////////////////////
// Item.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Item.hpp"
#include <fstream>

namespace Collisions
{
	Item::Item(const string& textureName) : _type(COIN), _submission(0)
	{
		_textureName = "textures\\items\\" + textureName;
		loadItem();
	}

	 Item::Item(const string& textureName, Type type, int submission) :  _type(type), _submission(submission)
	 {
		_textureName = "textures\\items\\" + textureName;
		 loadItem();
	 }

	Item::Type Item::getType()
	{
		return _type;
	}

	int Item::getSubmission()
	{
		return _submission;
	}

	Vector2f Item::getInitialSpeed()
	{
		return _initialSpeed;
	}

	vector<ItemOccurrence*> Item::getItemOccurrences()
	{
		return _itemOccurences;
	}

	void Item::addNewItemOccurrence()
	{
		_itemOccurences.push_back(new ItemOccurrence(_textureName, this));
	}

	void Item::addNewItemOccurrence(Vector2f& position, ItemOccurrence::State state)
	{
		_itemOccurences.push_back(new ItemOccurrence(_textureName, this, position, state));
	}

	void Item::removeItemOccurrence(const ItemOccurrence* item)
	{
		vector<ItemOccurrence*>::iterator itItemOccurrence;

		for(itItemOccurrence = _itemOccurences.begin(); itItemOccurrence < _itemOccurences.end(); itItemOccurrence++)
		{
			if((*itItemOccurrence) == item)
				_itemOccurences.erase(itItemOccurrence);
		}
	}

	void Item::loadItem()
	{
		string fileName = _textureName + ".item";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

			stream >> word;
			if(word == "speed_x=")
			{
				stream >> _initialSpeed.x;
			}
			else
				throw exception(" \"speed_x=\" keyword is missing");

			stream >> word;
			if(word == "speed_y=")
			{
				stream >> _initialSpeed.y;
			}
			else
				throw exception("\"speed_y=\" keyword is missing");

			stream >> word;
			if(word == "submission=")
			{
				/* Read hexadecimal number with 'hex' manipulator */
				stream >> hex >> _submission;
			}
			else
				throw exception("\"submission=\" keyword is missing");

			stream >> word;
			if(word == "nb_sprites=")
			{
				stream >> _nbSprites;
			}
			else
				throw exception("\"nb_sprites=\" keyword is missing");
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
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
