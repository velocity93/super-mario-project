////////////////////////////////////////////////////////////////////////
// Item.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ITEM
#define HPP_ITEM

#include "ItemOccurrence.hpp"
#include "Resource.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

namespace smp
{
	class Item : public Resource
	{
	
	public:
		typedef enum Type
		{
			COIN,
			MUSHROOM,
			FLOWER,
			ICE_FLOWER,
			MINI_MUSHROOM,
			POISON_MUSHROOM,
			STAR,
			LIFE_MUSHROOM
		} Type;
	
		/* Constructors */
        Item(const std::string& textureName, Type type = COIN, int submission = 0);

		/* Item type */
		Type getType();

		/* Physic submission */
		int getSubmission();
		void setSubmission(int submission);

		/* Initial Speed of Item */
		sf::Vector2f& getInitialSpeed();
		void setInitialSpeedX(float x);
		void setInitialSpeedY(float y);

		/* Access to all of his occurences */
		std::vector<ItemOccurrence*>& getItemOccurrences();

		/* Add New Item Occurrence */
		void addNewItemOccurrence(const sf::Vector2f& position = sf::Vector2f(0,0), const sf::Vector2f& speed = sf::Vector2f(0,0), 
			ItemOccurrence::State state = ItemOccurrence::NORMAL, ItemOccurrence::Side side = ItemOccurrence::RIGHT_SIDE);

		/* Update data */
		void updatePhysicData(float time, sf::RenderWindow& app);
		void updateGraphicData(sf::RenderWindow& app);

		void addNbSpritesForState(ItemOccurrence::State state, int nbSprites);
		void addFrameDelayForState(ItemOccurrence::State state, int frameDelay);

		/* Render all occurrences */
		void render(sf::RenderWindow& app);

		/* Serialize Data */
		void serialize(std::ofstream& file, const std::string& tabs);

		/* Destructor */
		virtual ~Item();

	private:
		Type _type;
		int _submission;
		sf::Vector2f _initialSpeed;
		std::vector<ItemOccurrence*> _itemOccurrences;
		std::map<ItemOccurrence::State, int> _nbSpritesByState;
		std::map<ItemOccurrence::State, int> _frameDelayByState;

		/* Loading Item */
		void loadItem();
	};
} // namespace

#endif // HPP_ITEM
