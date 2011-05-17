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

	float Pipe::getMonsterExitDuration()
	{
		return _monsterExitDuration.GetElapsedTime();
	}

	void Pipe::setDirection(Pipe::Direction direction)
	{
		_direction = direction;
	}

	void Pipe::setMonster(Monster* monster)
	{
		_monster = monster;
	}

	void Pipe::update(RenderWindow& app)
    {
		if(_monster != nullptr)
		{
			if(_monsterExitDuration.GetElapsedTime() >= MONSTER_EXIT_TIME)
			{
				MonsterOccurrence* monsterOccurrence = nullptr;
				switch(_direction)
				{
				case TO_TOP:
					monsterOccurrence = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monsterOccurrence->setSpeed(0, MONSTER_EXIT_SPEED);
					monsterOccurrence->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_BOTTOM:
					monsterOccurrence = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monsterOccurrence->setSpeed(0, -MONSTER_EXIT_SPEED);
					monsterOccurrence->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_LEFT:
					monsterOccurrence = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monsterOccurrence->setSpeed(-MONSTER_EXIT_SPEED, 0);
					monsterOccurrence->setSide(Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_RIGHT:
					monsterOccurrence = new MonsterOccurrence(_monster->getMonsterOccurrences().front()->getTexture()->getName(), Coord<float>(this->getPosition().getX() * BLOCK_WIDTH + BLOCK_WIDTH / 2, this->getPosition().getY() * BLOCK_WIDTH));
					monsterOccurrence->setSpeed(MONSTER_EXIT_SPEED, 0);
					monsterOccurrence->setSide(Collisions::MonsterOccurrence::Side::RIGHT_SIDE);
					break;

				default:
					break;
				}
				
				//occ_m->tps_sortie_tuyau = occ_m->type_monstre->tps_sortie_tuyau;
				monsterOccurrence->setState(MonsterOccurrence::State::M_GET_OUT_FROM_PIPE);
				_monster->addMonsterOccurrence(monsterOccurrence);
				_monsterExitDuration.Reset();
			}
		}
    }

	void Pipe::render(RenderWindow& app)
    {
		Sprite sprite = this->getTexture()->getSprite();

		switch(_direction)
		{
		case TO_BOTTOM:
			sprite.FlipX(true);

			/* Body */
			for(int step = 0; step < _lenght; step++)
			{
				sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, (this->getPosition().getY() + step) * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}

			/* Top of pipe */
			sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, (this->getPosition().getY() + _lenght) * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);
			break;

		case TO_RIGHT:
			sprite.FlipX(true);
			sprite.SetCenter(0, sprite.GetImage()->GetHeight() / 2);
			sprite.Rotate(270);

			/* Body */
			for(int step = 0; step < _lenght; step++)
			{
				sprite.SetPosition((this->getPosition().getX() + step) * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}

			/* Top of pipe */
			sprite.SetPosition((this->getPosition().getX() + _lenght) * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);
			break;

		case TO_LEFT:
			sprite.SetCenter(sprite.GetImage()->GetWidth(), 0);
			sprite.Rotate(90);

			/* Top of pipe */
			sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);

			/* Body */
			for(int step = 1; step <= _lenght; step++)
			{
				sprite.SetPosition((this->getPosition().getX() + step) * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}
			break;

		default:
			/* Top of pipe */
			sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, this->getPosition().getY() * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);

			/* Body */
			for(int step = 1; step <= _lenght; step++)
			{
				sprite.SetPosition(this->getPosition().getX() * BLOCK_WIDTH, (this->getPosition().getY() + step) * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}
			break;
		}
    }

    Pipe::~Pipe()
    {
    }
} // namespace
