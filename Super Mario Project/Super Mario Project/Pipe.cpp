////////////////////////////////////////////////////////////////////////
// Pipe.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Pipe.hpp"
#include "Monster.hpp"

using namespace std;
using namespace sf;

namespace smp
{
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
						MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_BOTTOM:
					 _monster->addNewMonsterOccurrence(
						 Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						 Vector2f(0, -MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y), 
						 MonsterOccurrence::GET_OUT_FROM_PIPE, 
						 MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_LEFT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						Vector2f(-MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y, 0),
						MonsterOccurrence::GET_OUT_FROM_PIPE,
						MonsterOccurrence::LEFT_SIDE);
					break;

				case TO_RIGHT:
					_monster->addNewMonsterOccurrence(
						Vector2f(_position.x + BLOCK_WIDTH / 2, _position.y),
						Vector2f(MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y, 0),
						MonsterOccurrence::GET_OUT_FROM_PIPE,
						MonsterOccurrence::RIGHT_SIDE);
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
			Sprite sprite(*_texture);

			switch(_direction)
			{
			case TO_BOTTOM:
				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y);
				sprite.setTextureRect(sf::IntRect(0, sprite.getTexture()->getSize().y / 2, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));
				sprite.setScale(1, -1); // FlipY
				sprite.draw(false);
				
				/* Body */
				for(int step = 1; step <= _lenght; step++)
				{
					sprite.setPosition(_position.x, _position.y + (step * BLOCK_WIDTH));
					sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 2));
					sprite.draw(false);
				}

				break;

			case TO_RIGHT:
				sprite.setScale(-1, 1); // FlipX
				sprite.setOrigin(0.0f, _texture->getSize().y / 2.0f);

				/* Body */
				for(int step = 1; step <= _lenght; step++)
				{
					sprite.setPosition(_position.x + (step * BLOCK_WIDTH), _position.y);
					sprite.setTextureRect(sf::IntRect(0, 0, _texture->getSize().x, _texture->getSize().y / 2));					
					sprite.rotate(270);
					sprite.draw(false);
					sprite.rotate(90); // to replace the right rotation
				}

				/* Top of pipe */
				sprite.setPosition(_position.x + ((_lenght + 1) * BLOCK_WIDTH), _position.y);
				sprite.setTextureRect(sf::IntRect(0, _texture->getSize().y / 2, _texture->getSize().x, _texture->getSize().y / 2));

				sprite.rotate(270);
				//app.draw(sprite);
				sprite.draw(false);
				sprite.rotate(90);
				break;

			case TO_LEFT:
				sprite.setOrigin(0.0f, sprite.getTexture()->getSize().y / 2.0f);

				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y);
				sprite.setTextureRect(sf::IntRect(0, _texture->getSize().y / 2, _texture->getSize().y, _texture->getSize().y / 2));				
				sprite.rotate(90);
				/*app.draw(sprite);*/
				sprite.draw(false);
				sprite.rotate(270); // to replace the right rotation

				/* Body */
				for(int step = 1; step <= _lenght; step++)
				{
					sprite.setPosition(_position.x + (step * BLOCK_WIDTH), _position.y);
					sprite.setTextureRect(sf::IntRect(0, 0, _texture->getSize().x, _texture->getSize().y / 2));
					sprite.rotate(90);
					sprite.draw(false);
					sprite.rotate(270);
				}
				break;

			default:
				/* Body */
				sprite.setTextureRect(sf::IntRect(0, 0, _texture->getSize().x, _texture->getSize().y / 2));

				for(int step = 0; step < _lenght; ++step)
				{
					sprite.setPosition(_position.x, _position.y + (step * BLOCK_WIDTH));
					sprite.draw(false);
				}

				/* Top of pipe */
				sprite.setPosition(_position.x, _position.y + (_lenght * BLOCK_WIDTH));
				sprite.setTextureRect(sf::IntRect(0, _texture->getSize().y / 2, _texture->getSize().x, _texture->getSize().y / 2));

				sprite.draw(false);
				break;
			}
		}
		#ifdef _RELEASE
		/* Drawing HitBox */
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(_hitboxSize.x, _hitboxSize.y));
		rect.setPosition(_hitboxPosition.x, _hitboxPosition.y);
		rect.setFillColor(sf::Color(255, 0, 0, 122));

		app.draw(rect);
		#endif
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
