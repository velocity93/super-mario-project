////////////////////////////////////////////////////////////////////////
// Item.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Item.hpp"
#include "Exceptions.hpp"
#include "XMLItemParser.hpp"
#include <sstream>

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
    Item::Item(const string& textureName, Type type, int submission)
        : Resource("textures/items/" + textureName),
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

	void Item::setSubmission(int submission)
	{
		_submission = submission;
	}

    Vector2f& Item::getInitialSpeed()
    {
        return _initialSpeed;
    }

	void Item::setInitialSpeedX(float x)
    {
		_initialSpeed.x = x;
    }

	void Item::setInitialSpeedY(float y)
    {
		_initialSpeed.y = y;
    }

	vector<ItemOccurrence*>& Item::getItemOccurrences()
	{
		return _itemOccurrences;
	}

	void Item::addNewItemOccurrence(const Vector2f& position, const Vector2f& speed, ItemOccurrence::State state, ItemOccurrence::Side side)
    {
        _itemOccurrences.push_back(new ItemOccurrence(this, name(), position, speed, state, side, _nbSpritesByState, _frameDelayByState));
    }

    void Item::updatePhysicData(float time, RenderWindow& app)
    {
        unsigned int initSize = _itemOccurrences.size();

		for(unsigned int i = 0; i < initSize; ++i)
        {
            _itemOccurrences[i]->updatePhysicData(time, app);
        }
    }

	void Item::updateGraphicData(RenderWindow& app)
    {
        for(vector<ItemOccurrence*>::iterator itItems = this->_itemOccurrences.begin(); itItems != this->_itemOccurrences.end(); ++itItems)
        {
			(*itItems)->updateGraphicData(app);
        }
    }

	void Item::addNbSpritesForState(ItemOccurrence::State state, int nbSprites)
	{
		_nbSpritesByState.insert(pair<ItemOccurrence::State, int>(state, nbSprites));
	}

	void Item::addFrameDelayForState(ItemOccurrence::State state, int frameDelay)
	{
		_frameDelayByState.insert(pair<ItemOccurrence::State, int>(state, frameDelay));
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

	void Item::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<item ";
		file << "img=\"" << shorterName() << "\" ";
		file << "type=\"" << _type << "\"/>" << endl;
	}


	void Item::loadItem()
    {
		XMLItemParser::getParser()->loadItem(name() + ".xml", this);
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
