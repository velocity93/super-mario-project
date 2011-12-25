////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "ItemOccurrence.hpp"
#include "Item.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	ItemOccurrence::ItemOccurrence(
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed, 
		State state, 
		Side side,
		map<ItemOccurrence::State, int>& nbSpritesByState,
		map<ItemOccurrence::State, int>& frameDelayByState) : 
		EntityMovable(textureName, position, speed, side), 
			_state(state), 
			_blockExitTime(0)
	{
		_item = ResourceManager::getItem(textureName);

		/* Initialize animation class */
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setCurrentState(_state);

		_position = _hitboxPosition = position;
		_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax();
		_hitboxSize.y = _texture->getImage()->GetHeight();
	}

	ItemOccurrence::State ItemOccurrence::getState()
	{
		return _state;
	}

	void ItemOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	void ItemOccurrence::setActivity(RenderWindow& app)
	{

	}

	void ItemOccurrence::update(RenderWindow& app)
	{
	//	pause_item(n, item, e);

	//if(item->actif)
	//{
	//	/* Test si l'item est sorti du bloc */
	//	if(item->etat == NORMAL)
	//	{
	//		/* Gravité */
	//		if(n->items[item->type_item]->soumission & SOUMIS_GRAVITE)
	//			gravity(&item->vitesse, duree);
	//	}
	//	else
	//	{
	//		if(item->tps_sortie_bloc <= 0)
	//		{
	//			if(n->items[item->type_item]->nom == PIECE)
	//			{
	//				supprime_item(n->items[item->type_item]->occ_items, item);
	//				return 1;
	//			}
	//			else
	//			{
	//				item->etat = NORMAL;
	//				item->vitesse.x = n->items[item->type_item]->vitesse.x;
	//				item->vitesse.y = n->items[item->type_item]->vitesse.y;
	//			}
	//		}
	//		else
	//		{
	//			item->tps_sortie_bloc -= duree;
	//		}
	//	}

	//	/* Sauvegarde de la position precedente */
	//	item->position_prec.x = item->position.x;
	//	item->position_prec.y = item->position.y;

	//	/* Mise à jour des positions à partir de la vitesse */
	//	item->position.x += item->vitesse.x * duree;
	//	item->position.y += item->vitesse.y * duree;
	//}
	//return 0;

		if(_isActive)
		{
			/* If it falls in hole */
			if(_hitboxPosition.y + _hitboxSize.y < 0)
				_item->removeItemOccurrence(this);

			/* Submissions */
			if(this->_item->getSubmission() & GRAVITY_SUBMISSION)
				gravity(_speed, app.GetFrameTime());

			/* Update physic position */
			/* Save actual position in previous position */
			_previousPosition = _position;

			/* Compute new position */
			_position.x = _position.x + _speed.x * app.GetFrameTime(); 
			_position.y = _position.y + _speed.y * app.GetFrameTime();
		}

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, _side == Side::LEFT_SIDE);
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
