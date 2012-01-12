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
#include "Collisionable.hpp"

namespace SuperMarioProject
{
	class QuadTree
	{
	public :
		static const int MAX_TREE = 100;
		static const int MAX_DEPTH = 10;
		QuadTree(sf::Vector2f& center, sf::Vector2i& size, int depth) :
				_size(size), _center(center), _nbElementsInside(0), _depth(depth),
				_subTree1(nullptr), _subTree2(nullptr), _subTree3(nullptr), _subTree4(nullptr)
				{ }

		void buildTree(vector<Collisions::Collisionable*>& obj);

		bool isLeaf();
		virtual ~QuadTree();

	private :
		int _depth;
		Vector2f _center;
		Vector2i _size;
		int _nbElementsInside;
		QuadTree* _subTree1;
		QuadTree* _subTree2;
		QuadTree* _subTree3;
		QuadTree* _subTree4;
		vector<Collisions::Collisionable*> _elements;

	};
}

#endif // HPP_QUADTREE