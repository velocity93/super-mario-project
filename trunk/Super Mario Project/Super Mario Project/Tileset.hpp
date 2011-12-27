////////////////////////////////////////////////////////////////////////
// Tileset.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////


#pragma once
#ifndef HPP_TILESET
#define HPP_TILESET

#include "Resource.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

namespace Collisions
{
	class Block;
	class Tileset : public SuperMarioProject::Resource
	{
	public :
		Tileset(const string& textureName);

		Vector2i& getNbSprites();
		int getFrameDelay();
		vector<Block*>& getBlocks();
		void addBlock(int physicIndex, int type);
		
		void update(RenderWindow& app);
		void render(RenderWindow& app);

		/* Serialize Data */
		void serialize(ofstream& file, string& tabs);

		virtual ~Tileset();
	private:
		vector<Block*> _blocks;
		vector<int> _physics;
		Vector2i _nbSprites;
		int _frameDelay;

		void loadConfiguration(const string& textureName);
	};
}

#endif