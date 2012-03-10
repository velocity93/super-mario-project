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

		if(!obj.empty() && _depth < MAX_DEPTH)
		{
			size.x = _size.x / 2;
			size.y = _size.y / 2;

			if(size.x >= 2 * obj.front()->getHitboxSize().x
				&& size.y >= 2 * obj.front()->getHitboxSize().y)
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

					if(point_HR.x <= center.x)
					{
						if(point_HR.y <= center.y)
						{
							subTab3.push_back(*itObj);
						}
						else if(point_BL.y >= center.y)
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
						if(point_HR.y <= center.y)
						{
							subTab4.push_back(*itObj);
						}
						else if(point_BL.y >= center.y)
						{
							subTab2.push_back(*itObj);
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
			else
			{
				/* We store blocks */
				_elements.insert(_elements.end(), obj.begin(), obj.end());
			}
		}
	}

	vector<Collisions::BlockOccurrence*>& QuadTree::getBlocks(sf::Vector2f& position, sf::Vector2i& size)
	{
		if(position.x >= _center.x - _size.x / 2 && position.x + size.x <= _center.x
			&& position.y >= _center.y && position.y + size.y <= _center.y + _size.y / 2
			&& _subTree1 != NULL)
		{
			return _subTree1->getBlocks(position, size);
		}
		else if(position.x >= _center.x && position.x + size.x <= _center.x + _size.x / 2
			&& position.y >= _center.y && position.y <= _center.y + _size.y / 2
			&& _subTree2 != NULL)
		{
			return _subTree2->getBlocks(position, size);
		}
		else if(position.x >= _center.x - _size.x / 2 && position.x + size.x <= _center.x
			&& position.y <= _center.y && position.y >= _center.y - _size.y / 2
			&& _subTree3 != NULL)
		{
			return _subTree3->getBlocks(position, size);
		}
		else if(position.x >= _center.x && position.x + size.x <= _center.x + _size.x / 2
			&& position.y <= _center.y && position.y >= _center.y - _size.y / 2
			&& _subTree4 != NULL)
		{
			return _subTree4->getBlocks(position, size);
		}
		else
		{
			/* Return all blocks in actual quad */
			return _elements;
		}
	}

	void QuadTree::render(RenderWindow& app)
	{
		Vector2f pointBL, pointHL, pointHR, pointBR;

		pointBL.x = _center.x - _size.x / 2;
		pointBL.y = _center.y - _size.y / 2;

		pointHR.x = _center.x + _size.x / 2;
		pointHR.y = _center.y + _size.y / 2;

		app.Draw(sf::Shape::Rectangle(pointBL.x, pointBL.y, pointHR.x, pointHR.y, sf::Color(0, 0, 0, 0), 0.5F, sf::Color::Red));

		if(_subTree1 != nullptr)
			_subTree1->render(app);

		if(_subTree2 != nullptr)
			_subTree2->render(app);

		if(_subTree3 != nullptr)
			_subTree3->render(app);

		if(_subTree4 != nullptr)
			_subTree4->render(app);
	}

	QuadTree::~QuadTree()
	{
		delete _subTree1, _subTree2, _subTree3, _subTree4;
	}
}