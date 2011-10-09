////////////////////////////////////////////////////////////////////////
// Block.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Block.hpp"
#include "Tileset.hpp"
#include <fstream>
#include <sstream>

using namespace SuperMarioProject;

namespace Collisions
{
	Tileset* Block::getTileset()
	{
		return _tileset;
	}

	void Block::addNewBlockOccurrence(Block* alternativeBlock, Vector2f &position, Vector2f &speed, Collisions::BlockOccurrence::State state, Collisions::EntityMovable::Side side)
	{
		_blockOccurrences.push_back(new BlockOccurrence(_tileset->name(), position, speed, state, side, _physicIndex, this, alternativeBlock));
	}

	void Block::removeBlockOccurrence(const BlockOccurrence* block)
    {
        vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
            if((*itBlockOccurrence) == block)
                _blockOccurrences.erase(itBlockOccurrence);
        }
    }

	void Block::update(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->update(app);
        }
	}

	void Block::render(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->render(app);
        }
	}

    Block::~Block()
    {

    }
} // namespace
