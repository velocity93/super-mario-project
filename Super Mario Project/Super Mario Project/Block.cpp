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

using namespace std;
using sf::RenderWindow;
using sf::Vector2f;

namespace smp
{
	Tileset* Block::getTileset()
	{
		return _tileset;
	}

	int Block::getPhysic()
	{
		return _tileset->getBlockPhysic(_physicIndex);
	}
	
	int Block::getType()
	{
		return _type;
	}

	BlockOccurrence* Block::addNewBlockOccurrence(Block* alternativeBlock, const Vector2f &position, const Vector2f &speed, BlockOccurrence::State state, EntityMovable::Side side)
	{
		BlockOccurrence* block = new BlockOccurrence( _tileset->name(), position, speed, state, side, _physicIndex, this, alternativeBlock);
		_blockOccurrences.push_back(block);
		return block;
	}

	void Block::removeBlockOccurrence(const BlockOccurrence* block)
    {
        vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
            if((*itBlockOccurrence) == block)
                _blockOccurrences.erase(itBlockOccurrence);

			if(_blockOccurrences.size() == 0)
				break;
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

	void Block::serialize(ofstream& file, string& tabs)
	{
		file << tabs << "<block ";
		file << "physicIndex=\"" << _physicIndex << "\" ";
		file << "type=\"" << _type << "\" ";
		
		if(_blockOccurrences.size() > 0)
		{
			file << ">" << endl;
			tabs += '\t';
			for(vector<BlockOccurrence*>::iterator itBlock = _blockOccurrences.begin();
				itBlock < _blockOccurrences.end(); ++itBlock)
			{
				file << tabs << "<occ_block ";
				file << "positionX=\"" << (*itBlock)->getPosition().x << "\" ";
				file << "positionY=\"" << (*itBlock)->getPosition().y << "\"/>" << endl;
			}
			//tabs.pop_back();
			file << tabs << "</block>" << endl;
		}
		else
		{
			file << "/>" << endl;
		}
	}

    Block::~Block()
    {

    }
} // namespace
