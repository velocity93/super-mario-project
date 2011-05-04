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
#include <SFML\Graphics.hpp>
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
	
		/* Constructor */
		Item() : _type(COIN), _submission(0) { }

		/* Getters and setters */
		Type getType();
		int getSubmission();
		vector<ItemOccurrence*> getItemOccurrences();
		void setType(Type type);
		void setSubmission(int submission);

		/* Methods */
		void update(float time);
		void render(RenderWindow &App);

		/* Destructor */
		virtual ~Item();

	private:
		Type _type;
		int _submission;
		vector<ItemOccurrence*> _itemOccurences;
	};
} // namespace

#endif // HPP_ITEM
