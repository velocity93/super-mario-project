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

	void QuadTree::buildTree(vector<Collisions::BlockOccurrence*>& obj)
	{
		sf::Vector2i size;
		sf::Vector2f center;

		if(obj.size() < MAX_TREE && _depth < MAX_DEPTH)
		{
			size.x = _size.x / 2;
			size.y = _size.y / 2;

			if(size.x > MIN_SIZE)

			{
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
				std::vector<Collisions::BlockOccurrence*> subTab1, subTab2, subTab3, subTab4;
				center = _center;

				for(vector<Collisions::BlockOccurrence*>::iterator itObj = obj.begin(); itObj != obj.end(); ++itObj)
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
	}

	vector<Collisions::BlockOccurrence*>& QuadTree::getBlocks(sf::Vector2f& position, sf::Vector2i& size)
	{
		vector<Collisions::BlockOccurrence*> blocks;

		if(position.x >= this->_center.x - _size.x / 2 && position.x + size.x <= this->_center.x + _size.x / 2
			&& position.y >= this->_center.y - _size.y / 2 && position.y + size.y <= this->_center.y + _size.y / 2)
		{
			blocks = _elements;
			vector<Collisions::BlockOccurrence*> blocksSubTree1;
			vector<Collisions::BlockOccurrence*> blocksSubTree2;
			vector<Collisions::BlockOccurrence*> blocksSubTree3;
			vector<Collisions::BlockOccurrence*> blocksSubTree4;

			if(_subTree1 != NULL)
			{
				blocksSubTree1 = _subTree1->getBlocks(position, size);
				blocks.insert(blocks.end(), blocksSubTree1.begin(), blocksSubTree1.end());
			}

			if(_subTree2 != NULL)
			{
				blocksSubTree2 = _subTree2->getBlocks(position, size);
				blocks.insert(blocks.end(), blocksSubTree2.begin(), blocksSubTree2.end());
			}

			if(_subTree3 != NULL)
			{
				blocksSubTree3 = _subTree3->getBlocks(position, size);
				blocks.insert(blocks.end(), blocksSubTree3.begin(), blocksSubTree3.end());
			}

			if(_subTree4 != NULL)
			{
				blocksSubTree4 = _subTree4->getBlocks(position, size);
				blocks.insert(blocks.end(), blocksSubTree4.begin(), blocksSubTree4.end());
			}
		}
		return blocks;
	}

	void QuadTree::render()
	{
		Vector2f pointBL, pointHL, pointHR, pointBR;

		pointBL.x = _center.x - _size.x / 2;
		pointBL.y = _center.y - _size.y / 2;

		pointHL.x = _center.x - _size.x / 2;
		pointHL.y = _center.y + _size.y / 2;
		
		pointBR.x = _center.x + _size.x / 2;
		pointBR.y = _center.y - _size.y / 2;

		pointHR.x = _center.x + _size.x / 2;
		pointHR.y = _center.y + _size.y / 2;

		glLineWidth(1.0f);
		glBegin(GL_LINE_LOOP);

		glVertex2f(pointBL.x, pointBL.y);
		glVertex2f(pointHL.x, pointHL.y);
		glVertex2f(pointBR.x, pointBR.y);
		glVertex2f(pointHR.x, pointHR.y);

		glEnd();

		/*if(_subTree1 != nullptr)
			_subTree1->render();

		if(_subTree2 != nullptr)
			_subTree2->render();

		if(_subTree3 != nullptr)
			_subTree3->render();

		if(_subTree4 != nullptr)
			_subTree4->render();*/
	}

	QuadTree::~QuadTree()
	{
		delete _subTree1, _subTree2, _subTree3, _subTree4;
	}
}