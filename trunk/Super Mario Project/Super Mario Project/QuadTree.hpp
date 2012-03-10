////////////////////////////////////////////////////////////////////////
// QuadTree.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_QUADTREE
#define HPP_QUADTREE

#include <SFML\Graphics.hpp>
#include "BlockOccurrence.hpp"

namespace SuperMarioProject
{
	class QuadTree
	{
	public :
		static const int MAX_TREE = 100;
		static const int MAX_DEPTH = 10;
		static const int MIN_SIZE = 2;
		QuadTree(sf::Vector2f& center, sf::Vector2i& size, int depth) :
				_size(size), _center(center), _depth(depth),
				_subTree1(nullptr), _subTree2(nullptr), _subTree3(nullptr), _subTree4(nullptr)
				{ }

		void buildTree(vector<Collisions::BlockOccurrence*>& obj);
		vector<Collisions::BlockOccurrence*>& getBlocks(sf::Vector2f& position, sf::Vector2i& size);

		bool isLeaf();
		void render();
		virtual ~QuadTree();

	private :
		int _depth;
		Vector2f _center;
		Vector2i _size;
		vector<Collisions::BlockOccurrence*> _elements;

		/* Sub Tree Disposition (C=Center)
		 * 			 ----- -----
		 * 			|     |     |
		 * 			| ST1 | ST2 |
		 * 			|     |     |
		 * 			 -----C-----
		 * 			|     |     |
		 * 			| ST3 | ST4 |
		 * 			|     |     |
		 * 			 ----- -----
		 */

		QuadTree* _subTree1;
		QuadTree* _subTree2;
		QuadTree* _subTree3;
		QuadTree* _subTree4;

	};
}

#endif // HPP_QUADTREE