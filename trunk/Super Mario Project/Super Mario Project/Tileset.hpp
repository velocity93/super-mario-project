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
#include <SFML\System.hpp>
#include <vector>

using namespace std;
using namespace sf;

namespace Collisions
{
	class Tileset : public SuperMarioProject::Resource
	{
	public :
		Tileset(const string& textureName, Vector2i blocSize);

		Vector2i& getNbSprites();
		int getFrameDelay();

		virtual ~Tileset();
	private:
		vector<int> _physics;
		Vector2i _nbSprites;
		int _frameDelay;

		void loadConfiguration(const string& textureName);
	};
}

#endif