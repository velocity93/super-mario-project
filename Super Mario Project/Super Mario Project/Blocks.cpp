////////////////////////////////////////////////////////////////////////
// Blocks.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Blocks.hpp"
#include <fstream>

using namespace SuperMarioProject;

namespace Collisions
{
	Blocks::Blocks(const string& textureName) : Resource("textures\\blocs\\" + textureName),
		_blockOccurrences(vector<BlockOccurrence*>()),
		_nbSprites(Vector2i())
	{
		loadBlockConfiguration(textureName);
    }

	void Blocks::addNewBlockOccurrence(int physicIndex, Vector2f &position, Vector2f &speed, Collisions::BlockOccurrence::State state, Collisions::EntityMovable::Side side)
	{
		_blockOccurrences.push_back(new BlockOccurrence(name(), position, speed, state, side, _nbSprites, _vAnim, physicIndex));
	}

	void Blocks::removeBlockOccurrence(const BlockOccurrence* block)
    {
        vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
            if((*itBlockOccurrence) == block)
                _blockOccurrences.erase(itBlockOccurrence);
        }
    }

	int Blocks::getPhysic(int index)
	{
		return _physics[index];
	}

	void Blocks::update(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->update(app);
        }
	}

	void Blocks::render(RenderWindow& app)
	{
		vector<BlockOccurrence*>::iterator itBlockOccurrence;

        for(itBlockOccurrence = _blockOccurrences.begin(); itBlockOccurrence != _blockOccurrences.end(); ++itBlockOccurrence)
        {
			(*itBlockOccurrence)->render(app);
        }
	}

	void Blocks::loadBlockConfiguration(const string& textureName)
	{
		string fileName = "textures\\blocs\\" + textureName.substr(0, textureName.find_first_of("\\")) + "\\" + textureName.substr(0, textureName.find_first_of("\\")) + ".cfg";
		ifstream stream(fileName.c_str());

		if(stream)
		{
			/* Number of sprites in width and height */
			stream >> _nbSprites.y;
			stream >> _nbSprites.x;

			for(int i = 0; i < _nbSprites.x * _nbSprites.y; ++i)
			{
				int phys;
				stream >> hex >> phys;
				_physics.push_back(phys);
			}
		}
		else
		{
			// Exception
		}
	}

    Blocks::~Blocks()
    {
		release();
    }
} // namespace
