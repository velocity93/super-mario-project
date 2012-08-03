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
	Pipe::Pipe(const string& textureName) 
		: Collisionable("textures/pipes/" + textureName),
			_direction(TO_TOP), 
			_monster(nullptr), 
			_monsterExitDuration(Clock()), 
			_lenght(1) 
	{
		setPositionX(0);
		setPositionY(0);

		_hitboxSize.x = _texture->getSize().x;
		_hitboxSize.y = (_texture->getSize().y / 2 * _lenght) + _texture->getSize().y / 2;
	}

	Pipe::Pipe(const std::string& textureName,
			Vector2f& position,
			int indexPipeDestination, 
			const std::string& levelDestination, 
			State state, 
			int lenght, 
			Direction direction, 
			Monster* monster)
			: Collisionable("textures/pipes/" + textureName, position), 
			_indexDestination(indexPipeDestination), 
			_levelDestination(levelDestination), 
			_state(state), 
			_lenght(lenght), 
			_direction(direction), 
			_monster(monster),
			_monsterExitDuration(Clock())
	{
		_hitboxPosition.x = position.x;
		_hitboxPosition.y = position.y;

		setPositionX(position.x);
		setPositionY(position.y);

		_hitboxSize.x = _texture->getSize().x;
		_hitboxSize.y = (_texture->getSize().y / 2 * _lenght) + _texture->getSize().y / 2;
	}

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
		return _monsterExitDuration.getElapsedTime().asMilliseconds();
	}

	void Pipe::setDirection(Pipe::Direction direction)
	{
		_direction = direction;
	}

	void Pipe::setMonster(Monster* monster)
	{
		_monster = monster;
	}

	void Pipe::updateGraphicData(RenderWindow&)
	{
		// NOTHING
	}

	void Pipe::updatePhysicData(float, RenderWindow& app)
    {
		setActivity(app);

		if(_isActive && _monster != nullptr)
		{
			if(_monsterExitDuration.getElapsedTime().asMilliseconds() >= MONSTER_EXIT_TIME)
			{
				switch(_direction)
				{
				case TO_TOP:
                    _monster->addNewMonsterOccurrence(
						Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						Vector2f(0, MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y), 
						MonsterOccurrence::GET_OUT_FROM_PIPE, 
						Collisions::MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_BOTTOM:
					 _monster->addNewMonsterOccurrence(
						 Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						 Vector2f(0, -MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y), 
						 MonsterOccurrence::GET_OUT_FROM_PIPE, 
						 Collisions::MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_LEFT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						Vector2f(-MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y, 0),
						MonsterOccurrence::GET_OUT_FROM_PIPE,
						Collisions::MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_RIGHT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						Vector2f(MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y, 0),
						MonsterOccurrence::GET_OUT_FROM_PIPE,
						Collisions::MonsterOccurrence::RIGHT_SIDE);
					break;

				default:
					break;
				}
				
				//occ_m->tps_sortie_tuyau = occ_m->type_monstre->tps_sortie_tuyau;
				_monsterExitDuration.restart();
			}
		}
    }

	void Pipe::render(RenderWindow& app)
	{
		if(_isActive)
		{
			ReversedSprite& sprite = _texture->getSprite();

			switch(_direction)
			{
			case TO_BOTTOM:
				/* Body */
				for(int step = 0; step < _lenght; step++)
				{
					sprite.setPosition(_position.x, _position.y + (step * BLOCK_WIDTH));
					sprite.setTextureRect(sf::IntRect(0, sprite.getTexture()->getSize().y / 2, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
					app.draw(sprite);
				}

				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y + (_lenght * BLOCK_WIDTH));
				sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));

				app.draw(sprite);
				break;

			case TO_RIGHT:
				sprite.FlipX(true);
				sprite.setOrigin(0.0f, sprite.getTexture()->getSize().y / 2.0f);
				sprite.rotate(270);

				/* Body */
				for(int step = 0; step < _lenght; step++)
				{
					sprite.setPosition(_position.x + (step * BLOCK_WIDTH), _position.y);
					sprite.setTextureRect(sf::IntRect(0, sprite.getTexture()->getSize().y / 2, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
					app.draw(sprite);
				}

				/* Top of pipe */
				sprite.setPosition(_position.x + (_lenght * BLOCK_WIDTH), _position.y);
				sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));

				app.draw(sprite);
				break;

			case TO_LEFT:
				sprite.setOrigin((float)sprite.getTexture()->getSize().x, 0.0f);
				sprite.rotate(90);

				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y);
				sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));

				app.draw(sprite);

				/* Body */
				for(int step = 1; step <= _lenght; step++)
				{
					sprite.setPosition(_position.x + (step * BLOCK_WIDTH), _position.y);
					sprite.setTextureRect(sf::IntRect(0, sprite.getTexture()->getSize().y / 2, sprite.getTexture()->getSize().y, sprite.getTexture()->getSize().y));
					app.draw(sprite);
				}
				break;

			default:
				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y);
				sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));

				app.draw(sprite);

				/* Body */
				for(int step = 1; step <= _lenght; step++)
				{
					sprite.setPosition(_position.x, _position.y + (step * BLOCK_WIDTH));
					sprite.setTextureRect(sf::IntRect(0, sprite.getTexture()->getSize().y / 2, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
					app.draw(sprite);
				}
				break;
			}
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
