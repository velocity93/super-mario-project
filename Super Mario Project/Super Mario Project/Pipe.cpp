////////////////////////////////////////////////////////////////////////
// Pipe.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Pipe.hpp"
#include "Monster.hpp"

namespace Collisions
{
	Pipe::Direction Pipe::getDirection()
	{
		return _direction;
	}

	int Pipe::getLenght()
	{
		return _lenght;
	}

	int Pipe::getState()
	{
		return _state;
	}

	string& Pipe::getLevelDestination()
	{
		return _levelDestination;
	}

	int Pipe::getPipeDestination()
	{
		return _indexDestination;
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

	void Pipe::setActivity(RenderWindow& app)
	{

	}

	void Pipe::updateGraphicData(RenderWindow&)
	{
		// NOTHING
	}

	void Pipe::updatePhysicData(RenderWindow& app)
    {
		if(_monster != nullptr)
		{
			if(_monsterExitDuration.GetElapsedTime() >= MONSTER_EXIT_TIME)
			{
				MonsterOccurrence* monsterOccurrence = nullptr;
				switch(_direction)
				{
				case TO_TOP:
                    _monster->addNewMonsterOccurrence(
						Vector2f(_position.x * BLOCK_WIDTH + BLOCK_WIDTH / 2, _position.y * BLOCK_WIDTH),
						Vector2f(0, MONSTER_EXIT_SPEED), 
						MonsterOccurrence::M_GET_OUT_FROM_PIPE, 
						Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_BOTTOM:
					 _monster->addNewMonsterOccurrence(
						 Vector2f(_position.x * BLOCK_WIDTH + BLOCK_WIDTH / 2, _position.y * BLOCK_WIDTH),
						 Vector2f(0, -MONSTER_EXIT_SPEED), 
						 MonsterOccurrence::M_GET_OUT_FROM_PIPE, 
						 Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_LEFT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x * BLOCK_WIDTH + BLOCK_WIDTH / 2, _position.y * BLOCK_WIDTH),
						Vector2f(-MONSTER_EXIT_SPEED, 0),
						MonsterOccurrence::M_GET_OUT_FROM_PIPE,
						Collisions::MonsterOccurrence::Side::LEFT_SIDE);
					break;

				case TO_RIGHT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x * BLOCK_WIDTH + BLOCK_WIDTH / 2, _position.y * BLOCK_WIDTH),
						Vector2f(MONSTER_EXIT_SPEED, 0),
						MonsterOccurrence::M_GET_OUT_FROM_PIPE,
						Collisions::MonsterOccurrence::RIGHT_SIDE);
					break;

				default:
					break;
				}
				
				//occ_m->tps_sortie_tuyau = occ_m->type_monstre->tps_sortie_tuyau;
				_monsterExitDuration.Reset();
			}
		}
    }

	void Pipe::render(RenderWindow& app)
    {
		Sprite sprite = _texture->getSprite();

		switch(_direction)
		{
		case TO_BOTTOM:
			sprite.FlipX(true);

			/* Body */
			for(int step = 0; step < _lenght; step++)
			{
				sprite.SetPosition(_position.x * BLOCK_WIDTH, (_position.y + step) * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}

			/* Top of pipe */
			sprite.SetPosition(_position.x * BLOCK_WIDTH, (_position.y + _lenght) * BLOCK_WIDTH);
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
				sprite.SetPosition((_position.x + step) * BLOCK_WIDTH, _position.y * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}

			/* Top of pipe */
			sprite.SetPosition((_position.x + _lenght) * BLOCK_WIDTH, _position.y * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);
			break;

		case TO_LEFT:
			sprite.SetCenter(sprite.GetImage()->GetWidth(), 0);
			sprite.Rotate(90);

			/* Top of pipe */
			sprite.SetPosition(_position.x * BLOCK_WIDTH, _position.y * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);

			/* Body */
			for(int step = 1; step <= _lenght; step++)
			{
				sprite.SetPosition((_position.x + step) * BLOCK_WIDTH, _position.y * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}
			break;

		default:
			/* Top of pipe */
			sprite.SetPosition(_position.x * BLOCK_WIDTH, _position.y * BLOCK_WIDTH);
			sprite.SetSubRect(sf::IntRect(0, 0, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight() / 2));

			app.Draw(sprite);

			/* Body */
			for(int step = 1; step <= _lenght; step++)
			{
				sprite.SetPosition(_position.x * BLOCK_WIDTH, (_position.y + step) * BLOCK_WIDTH);
				sprite.SetSubRect(sf::IntRect(0, sprite.GetImage()->GetHeight() / 2, sprite.GetImage()->GetWidth(), sprite.GetImage()->GetHeight()));
				app.Draw(sprite);
			}
			break;
		}
    }

	void Pipe::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<pipe ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\" ";
		file << "destination_pipe=\"" << _indexDestination << "\" ";
		file << "level_destination=\"" << _levelDestination << "\" ";
		file << "state=\"" << _state << "\" ";
		file << "length=\"" << _lenght << "\" ";
		file << "direction=\"" << _direction << "\" ";
		file << "monster=\"" << _monster->shorterName() << "\" />" << endl;
	}

    Pipe::~Pipe()
    {
    }
} // namespace
