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

namespace smp
{
	// forward declaration
	class Block;

	class Tileset : public Resource
	{
	public :
		Tileset(const std::string& textureName);

		sf::Vector2i& getNbSprites();
		int getFrameDelay();
		std::vector<Block*>& getBlocks();
		int getBlockPhysic(int index);
		void addBlock(int physicIndex, int type);
		
		void render(sf::RenderWindow& app);

		/* Serialize Data */
		void serialize(std::ofstream& file, std::string& tabs);

		virtual ~Tileset();
	private:
		std::vector<Block*> _blocks;
		std::vector<int> _physics;
		sf::Vector2i _nbSprites;
		int _frameDelay;

		void loadConfiguration(const std::string& textureName);
	};
}

#endif
