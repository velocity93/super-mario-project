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
        _submission(submission)
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
        _itemOccurences.push_back(new ItemOccurrence(name(), this));
    }

    void Item::addNewItemOccurrence(Vector2f& position, ItemOccurrence::State state)
    {
        _itemOccurences.push_back(new ItemOccurrence(name(), this, position, state));
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
                }

                /* Manage sprites numbers here */
                found = word.find("nb_sprites=");
                if(found != string::npos)
                {
                    /* where put value ? */
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
