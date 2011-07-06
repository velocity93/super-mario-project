////////////////////////////////////////////////////////////////////////
// BlockOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "BlockOccurrence.hpp"

namespace Collisions
{
	BlockOccurrence::BlockOccurrence(
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed, 
		State state, 
		Side side,
		const map<BlockOccurrence::State, int>& nbSpritesByState,
		const map<BlockOccurrence::State, int>& vAnimByState) 
		: EntityMovable(textureName, position, speed, side),
		_state(UNMOVABLE)
    {

    }

	void BlockOccurrence::update(RenderWindow& app)
	{

	}
	
	void BlockOccurrence::render(RenderWindow& app)
	{

	}

    BlockOccurrence::~BlockOccurrence()
    {
    }
} // namespace
