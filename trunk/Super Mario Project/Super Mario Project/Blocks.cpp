////////////////////////////////////////////////////////////////////////
// Blocks.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Blocks.hpp"
#include <fstream>
#include <sstream>

using namespace SuperMarioProject;

namespace Collisions
{
	Blocks::Blocks(const string& textureName) : Resource("textures\\blocs\\" + textureName),
		_blockOccurrences(vector<BlockOccurrence*>()),
		_nbSprites(Vector2i()),
		_frameDelay(0)
	{
		loadBlockConfiguration(textureName);
    }

	void Blocks::addNewBlockOccurrence(int physicIndex, Vector2f &position, Vector2f &speed, Collisions::BlockOccurrence::State state, Collisions::EntityMovable::Side side)
	{
		_blockOccurrences.push_back(new BlockOccurrence(name(), position, speed, state, side, _nbSprites, _frameDelay, physicIndex));
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
		/* Build cfg file path */
		string fileName = "textures\\blocs\\";
		string buffer = textureName;
		while(buffer.find_first_of("\\") != string::npos)
		{

			fileName += buffer.substr(0, buffer.find_first_of("\\"));
			buffer = buffer.substr(buffer.find_first_of("\\") + 1, buffer.length());

			if(buffer.find_first_of("\\") != string::npos)
				fileName += "\\";
			else
				fileName += fileName.substr(fileName.find_last_of("\\"), fileName.length()); 
		}

		fileName += ".cfg";

		ifstream stream(fileName.c_str());

		if(stream)
		{
			/* Frame delay */
			stream >> _frameDelay;

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
