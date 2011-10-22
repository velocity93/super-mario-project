////////////////////////////////////////////////////////////////////////
// Item.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Item.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
    Item::Item(const string& textureName, Type type, int submission)
        : Resource("textures\\items\\" + textureName),
        _type(type),
        _submission(submission),
		_nbSpritesByState(map<ItemOccurrence::State, int>())
    {
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

    Vector2f& Item::getInitialSpeed()
    {
        return _initialSpeed;
    }

	vector<ItemOccurrence*>& Item::getItemOccurrences()
	{
		return _itemOccurrences;
	}

	void Item::addNewItemOccurrence(Vector2f& position, Vector2f& speed, ItemOccurrence::State state, ItemOccurrence::Side side)
    {
        _itemOccurrences.push_back(new ItemOccurrence(name(), position, speed, state, side, _nbSpritesByState, _frameDelayByState));
    }

    void Item::removeItemOccurrence(const ItemOccurrence* item)
    {
        vector<ItemOccurrence*>::iterator itItemOccurrence;

        for(itItemOccurrence = _itemOccurrences.begin(); itItemOccurrence != _itemOccurrences.end(); itItemOccurrence++)
        {
            if((*itItemOccurrence) == item)
                _itemOccurrences.erase(itItemOccurrence);
        }
    }

    void Item::loadItem()
    {
        string fileName = name() + ".item";
        ifstream stream(fileName.c_str());

        if(stream)
        {
            string word;

            /* We read file to search the keyword and read his value */
            while(getline(stream, word))
            {
                int found = word.find("speed_x=");
                if(found != string::npos)
                {
                    istringstream initialSpeedX(word.substr(found + 8));
                    initialSpeedX >> _initialSpeed.x;
                    continue;
                }

                found = word.find("speed_y=");
                if(found != string::npos)
                {
                    istringstream initialSpeedY(word.substr(found + 8));
                    initialSpeedY >> _initialSpeed.y;
                    continue;
                }

                /* Read hexadecimal value */
                found = word.find("submission=");
                if(found != string::npos)
                {
                    istringstream submission(word.substr(found + 11));
                    submission >> hex >> _submission;
					continue;
                }

                /* Manage sprites numbers here */
                found = word.find("nb_sprites=");
                if(found != string::npos)
                {
					int _nbSprites;
                    istringstream nbSprites(word.substr(found + 11));
                    nbSprites >> _nbSprites;
					_nbSpritesByState.insert(pair<ItemOccurrence::State, int>(ItemOccurrence::State::NORMAL, _nbSprites));
                }
            }
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
        for(itItems = this->_itemOccurrences.begin(); itItems != this->_itemOccurrences.end(); ++itItems)
        {
            (*itItems)->update(app);
        }
    }

    void Item::render(RenderWindow& app)
    {
        vector<ItemOccurrence*>::iterator itItems;

        /* ItemsOccurrences */
        for(itItems = this->_itemOccurrences.begin(); itItems != this->_itemOccurrences.end(); ++itItems)
        {
            (*itItems)->render(app);
        }
    }

    Item::~Item()
    {
        vector<ItemOccurrence*>::iterator itItems;

        /* ItemsOccurrences */
        for(itItems = this->_itemOccurrences.begin(); itItems != this->_itemOccurrences.end(); ++itItems)
        {
            delete (*itItems);
        }

		release();
    }
} // namespace
