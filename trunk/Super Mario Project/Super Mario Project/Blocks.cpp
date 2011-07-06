////////////////////////////////////////////////////////////////////////
// Blocks.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Blocks.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	Blocks::Blocks(const string& textureName, int type) : Resource("textures\\blocs\\" + textureName),
		_blockOccurrences(vector<BlockOccurrence*>()),
		_nbSpritesByState(map<BlockOccurrence::State, int>()),
		_vAnimByState(map<BlockOccurrence::State, int>()),
		_type(type)
	{
		loadBlockConfiguration();
    }

	void Blocks::addNewBlockOccurrence(Vector2f &position, Vector2f &speed, Collisions::BlockOccurrence::State state, Collisions::EntityMovable::Side side)
	{
		_blockOccurrences.push_back(new BlockOccurrence(name(), position, speed, state, side, _nbSpritesByState, _vAnimByState));
	}

	void Blocks::removeBlockOccurrence(const BlockOccurrence* block)
    {
        vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence < _blockOccurrences.end(); ++itBlockOccurrence)
        {
            if((*itBlockOccurrence) == block)
                _blockOccurrences.erase(itBlockOccurrence);
        }
    }

	void Blocks::update(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence < _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->update(app);
        }
	}

	void Blocks::render(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence < _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->render(app);
        }
	}

	void Blocks::loadBlockConfiguration()
	{

	}

    Blocks::~Blocks()
    {
    }
} // namespace
