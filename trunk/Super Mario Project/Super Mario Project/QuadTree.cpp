////////////////////////////////////////////////////////////////////////
// QuadTree.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "QuadTree.hpp"


namespace SuperMarioProject
{

	bool QuadTree::isLeaf()
	{
		return _subTree1 == nullptr &&
			_subTree2 == nullptr &&
			_subTree3 == nullptr &&
			_subTree4 == nullptr;
	}

	void QuadTree::buildTree(vector<Collisions::Collisionable*>& obj)
	{
		sf::Vector2i size;
		sf::Vector2f center;

		if(obj.size() > MAX_TREE && _depth < MAX_DEPTH)
		{
			size.x = _size.x / 2;
			size.y = _size.y / 2;

			/* create sub trees */
			center.x = _center.x - _size.x / 4;
			center.y = _center.y + _size.y / 4;
			_subTree1 = new QuadTree(center, size, _depth + 1);

			center.x +=  _size.x / 2;
			_subTree2 = new QuadTree(center, size, _depth + 1);

			center.x = _center.x - _size.x / 4;
			center.y -= _size.y / 2;
			_subTree3 = new QuadTree(center, size, _depth + 1);

			center.x += _size.x / 2;
			_subTree4 = new QuadTree(center, size, _depth + 1);

			/* create subvector */
			std::vector<Collisions::Collisionable*> subTab1, subTab2, subTab3, subTab4;
			center = _center;

			for(vector<Collisions::Collisionable*>::iterator itObj = obj.begin(); itObj != obj.end(); itObj++)
			{
				Vector2f point_BL = (*itObj)->getHitboxPosition();
				Vector2f point_HR = Vector2f((*itObj)->getHitboxPosition().x + (*itObj)->getHitboxSize().x,
											(*itObj)->getHitboxPosition().y + (*itObj)->getHitboxSize().y);

				if(point_HR.x < center.x)
				{
					if(point_HR.y < center.y)
					{
						subTab3.push_back(*itObj);
					}
					else if(point_BL.y > center.y)
					{
						subTab1.push_back(*itObj);
					}
					else
					{
						_elements.push_back(*itObj);
					}
				}
				else
				{
					if(point_HR.y < center.y)
					{
						subTab2.push_back(*itObj);
					}
					else if(point_BL.y > center.y)
					{
						subTab4.push_back(*itObj);
					}
					else
					{
						_elements.push_back(*itObj);
					}
				}
			}

			 /* build subTrees */
			_subTree1->buildTree(subTab1);
			_subTree2->buildTree(subTab2);
			_subTree3->buildTree(subTab3);
			_subTree4->buildTree(subTab4);
		}
	}

	QuadTree::~QuadTree()
	{
		delete _subTree1, _subTree2, _subTree3, _subTree4;
	}
}