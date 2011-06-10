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
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

namespace Collisions
{
	class Item
	{
	
	public:
		enum Type
		{
			COIN,
			MUSHROOM,
			FLOWER,
			ICE_FLOWER,
			MINI_MUSHROOM,
			POISON_MUSHROOM,
			STAR,
			LIFE_MUSHROOM
		};
	
		/* Constructors */
		Item() : _type(COIN), _submission(0) { }
		Item(Type type, int submission) : _type(type), _submission(submission) { }

		/* Item type */
		Type getType();

		/* Physic submission */
		int getSubmission();

		/* Initial Speed of Item */
		Vector2f getInitialSpeed();

		/* List of items occurrences */
		vector<ItemOccurrence*> getItemOccurrences();

		/* Add Item Occurrence */
		void addItemOccurrence(ItemOccurrence* item);
		
		/* Remove Item Occurrence */
		void removeItemOccurrence(ItemOccurrence* item);

		/* Update data */
		void update(RenderWindow& app);

		/* Render all occurrences */
		void Item::render(RenderWindow& App);

		/* Destructor */
		virtual ~Item();

	private:
		Type _type;
		int _submission;
		Vector2f _initialSpeed;
		vector<ItemOccurrence*> _itemOccurences;
	};
} // namespace

#endif // HPP_ITEM
