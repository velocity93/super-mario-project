////////////////////////////////////////////////////////////////////////
// Tileset.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Tileset.hpp"
#include "Block.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using sf::RenderWindow;
using sf::Vector2i;

namespace smp
{
	Tileset::Tileset(const string& textureName) : Resource("textures/blocs/" + textureName)
	{
		loadConfiguration(textureName);
	}

	int Tileset::getBlockPhysic(int index)
	{
		return _physics[index];
	}

	int Tileset::getFrameDelay()
	{
		return _frameDelay;
	}

	Vector2i& Tileset::getNbSprites()
	{
		return _nbSprites;
	}

	vector<Block*>& Tileset::getBlocks()
	{
		return _blocks;
	}

	vector<int>& Tileset::getPhysics()
	{
		return _physics;
	}

	void Tileset::setNbSprites(int x, int y)
	{
		_nbSprites.x = x;
		_nbSprites.y = y;
	}

	void Tileset::setFrameDelay(int frameDelay)
	{
		_frameDelay = frameDelay;
	}

	void Tileset::addBlock(int physicIndex, int type)
	{
		Block* block = new Block(this, physicIndex, type);
		_blocks.push_back(block);
	}

	void Tileset::render(RenderWindow& app)
	{
		vector<Block*>::iterator itBlock;

        for(itBlock = _blocks.begin(); itBlock != _blocks.end(); ++itBlock)
        {
			(*itBlock)->render(app);
        }
	}

	void Tileset::loadConfiguration(const string& textureName)
	{
		/* Build cfg file shorterName */
		string fileName = "textures/blocs/";
		string buffer = textureName;
		while(buffer.find_first_of("/") != string::npos)
		{

			fileName += buffer.substr(0, buffer.find_first_of("/"));
			buffer = buffer.substr(buffer.find_first_of("/") + 1, buffer.length());

			if(buffer.find_first_of("/") != string::npos)
				fileName += "/";
			else
				fileName += fileName.substr(fileName.find_last_of("/"), fileName.length()); 
		}

		fileName += ".cfg";

		ifstream stream(fileName.c_str());

		if(stream)
		{
			int phys;

			/* Number of sprites in width and height */
			stream >> _nbSprites.y;
			stream >> _nbSprites.x;

			/* Frame delay */
			stream >> _frameDelay;

			for(int i = 0; i < _nbSprites.x * _nbSprites.y; ++i)
			{
				/* If we have only one line, then we have only one block 
				 * following by his animation, with the same physic obviously 
				 */
				stream >> hex >> phys;
				_physics.push_back(phys);
				
				if(_nbSprites.y == 1 && i == 0)
					break;
			}
		}
		else
		{
			throw FileNotFoundException(fileName);
		}
	}

	void Tileset::serialize(ofstream& file, string& tabs)
	{
		string blocs = name().substr(name().find_first_of("/") + 1, name().size());
		string typeBlocs = blocs.substr(blocs.find_first_of("/") + 1, blocs.size());

		file << tabs << "<tileset ";
		file << "img=\"" << typeBlocs << "\"";

		if(_blocks.size() > 0)
		{
			file << ">" << endl;
			tabs += '\t';
			for(vector<Block*>::iterator itBlock = _blocks.begin();
				itBlock < _blocks.end(); itBlock++)
			{
				(*itBlock)->serialize(file, tabs);
			}
			//tabs.pop_back();
			file << tabs << "</tileset>" << endl;
		}
		else
		{
			file << "/>" << endl;
		}
	}

	Tileset::~Tileset()
	{
		release();
	}
}