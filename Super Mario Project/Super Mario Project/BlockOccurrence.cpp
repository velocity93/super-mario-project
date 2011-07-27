////////////////////////////////////////////////////////////////////////
// BlockOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "BlockOccurrence.hpp"
#include "Blocks.hpp"

namespace Collisions
{
	BlockOccurrence::BlockOccurrence(
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed,
		State state, 
		Side side,
		Vector2i& _nbSprites,
		int vAnim,
		int physicIndex)
		: EntityMovable(textureName, position, speed, side),
		_state(UNMOVABLE),
		_physicIndex(physicIndex)
    {
		/* Compute blocs coords into the texture */
		_coordSprite.y = physicIndex / _nbSprites.x;
		_coordSprite.x = physicIndex % _nbSprites.x;
    }

	int BlockOccurrence::getPhysic()
	{
		return _actualBlock->getPhysic(_physicIndex);
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
