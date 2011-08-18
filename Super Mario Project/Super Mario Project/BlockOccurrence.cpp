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
		Vector2i& nbSprites,
		int frameDelay,
		int physicIndex)
		: EntityMovable(textureName, position, speed, side),
		_state(UNMOVABLE),
		_physicIndex(physicIndex)
    {
		/* Compute blocs coords into the texture */
		_coordSprite.y = physicIndex / nbSprites.x;
		_coordSprite.x = physicIndex % nbSprites.x;

		/* Animation */
		if(frameDelay > 0)
		{
			/* So, we have a special block */
			_animation.addNbSpritesForGivenState(state, nbSprites.x);
			_animation.addFrameDelayForGivenState(state, frameDelay);
			_animation.setCurrentState(state);
		}
		/*else
		{*/
			/* Otherwise, we have a tileset */
		//}
    }

	int BlockOccurrence::getPhysic()
	{
		return _actualBlock->getPhysic(_physicIndex);
	}

	void BlockOccurrence::update(RenderWindow& app)
	{
		if(_animation.getNbSpritesMax() > 1)
		{
			_animation.update(app);
		}
	}
	
	void BlockOccurrence::render(RenderWindow& app)
	{
		if(_animation.getNbSpritesMax() > 1)
		{
			_animation.render(_texture, app, _position);
		}
	}

    BlockOccurrence::~BlockOccurrence()
    {
    }
} // namespace
