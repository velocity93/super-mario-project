////////////////////////////////////////////////////////////////////////
// Pipe.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Pipe.hpp"

namespace Collisions
{
	Pipe::Direction Pipe::getDirection()
	{
		return _direction;
	}

	Monster* Pipe::getMonster()
	{
		return _monster;
	}

	int Pipe::getMonsterExitDuration()
	{
		return _monsterExitDuration;
	}

	void Pipe::setDirection(Pipe::Direction direction)
	{
		_direction = direction;
	}

	void Pipe::setMonster(Monster* monster)
	{
		_monster = monster;
	}

	void Pipe::setMonsterExitDuration(int monsterExitDuration)
	{
		_monsterExitDuration = monsterExitDuration;
	}

	void Pipe::update(float time)
    {
		if(_monster != nullptr)
		{
			if(_monsterExitDuration <= 0)
			{
				MonsterOccurrence* monster = nullptr;
				switch(_direction)
				{
				case TO_TOP:
					monster = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monster->setSpeed(0, MONSTER_EXIT_SPEED);
					monster->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_BOTTOM:
					monster = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monster->setSpeed(0, -MONSTER_EXIT_SPEED);
					monster->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_LEFT:
					monster = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monster->setSpeed(-MONSTER_EXIT_SPEED, 0);
					monster->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_RIGHT:
					monster = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monster->setSpeed(MONSTER_EXIT_SPEED, 0);
					monster->setSide(Collisions::MonsterOccurrence::Side::RIGHT_SIDE);
					break;

				default:
					break;
				}
				
				//occ_m->tps_sortie_tuyau = occ_m->type_monstre->tps_sortie_tuyau;
				monster->setState(MonsterOccurrence::State::M_GET_OUT_FROM_PIPE);
				_monster->getMonsterOccurrences().push_back(monster);
				_monsterExitDuration = MONSTER_EXIT_TIME;
			}
			else
			{
				_monsterExitDuration -= time;
			}
		}
    }

	void Pipe::render(RenderWindow& app)
    {
		{/* Body of pipe */
			Sprite sprite;
			sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
			sprite.SetImage(this->getTexture()->getImage());
			
			sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), 0));
			sprite.SetScaleY(this->_lenght);

			/* According to direction, we rotate the sprite */
			switch(_direction)
			{
			case TO_BOTTOM:
				sprite.FlipX(true);
				break;

			case TO_RIGHT:
				sprite.Rotate(90);
				break;

			case TO_LEFT:
				sprite.Rotate(270);
				break;

			default:
				break;
			}
			app.Draw(sprite);
		}

		{/* Top of pipe */
			Sprite sprite;
			sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, (this->getPosition().getY() + _lenght) * BLOCK_WIDTH);
			sprite.SetImage(this->getTexture()->getImage());

			sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight(), sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			/* According to direction, we rotate the sprite */
			switch(_direction)
			{
			case TO_BOTTOM:
				sprite.FlipX(true);
				break;

			case TO_RIGHT:
				sprite.Rotate(90);
				break;

			case TO_LEFT:
				sprite.Rotate(270);
				break;

			default:
				break;
			}
			app.Draw(sprite);
		}
    }

    Pipe::~Pipe()
    {
    }
} // namespace
