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

#include <SFML/Graphics.hpp>

namespace smp
{
	// forward declaration
	class BlockOccurrence;

	class QuadTree
	{
	public :
		static const int MAX_TREE = 100;
		static const int MAX_DEPTH = 10;
		static const int MIN_SIZE = 2;
		QuadTree(const sf::Vector2f& center, const sf::Vector2i& size, int depth) :
				_size(size), _center(center), _depth(depth),
				_subTree1(nullptr), _subTree2(nullptr), _subTree3(nullptr), _subTree4(nullptr)
				{ }

		void buildTree(std::vector<BlockOccurrence*>& obj);
		void getBlocks(sf::Vector2f& position, sf::Vector2i& size, std::vector<BlockOccurrence*>* blocks);

		bool isLeaf();
		void render(sf::RenderWindow& app);
		virtual ~QuadTree();

	private :
		int _depth;
		sf::Vector2f _center;
		sf::Vector2i _size;
		std::vector<BlockOccurrence*> _elements;

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