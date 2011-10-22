////////////////////////////////////////////////////////////////////////
// Perso.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Perso.hpp"
#include "InputState.hpp"
#include "Pipe.hpp"
#include <fstream>
#include <sstream>

using namespace SuperMarioProject;

namespace Collisions
{
	Perso::Perso(const string& textureName, Vector2f& position) : EntityMovable("textures\\persos\\" + textureName, position),
		_textureName("textures\\persos\\" + textureName),
		_environment(GROUND), 
		_transformation(SMALL_MARIO), 
		_state(STANDING),
		_hud(new HUD()),
		_canClimb(false), 
		_acceleration(Vector2f()), 
		_invincibleTime(0), 
		_invincibleStarTime(0), 
		_transformationTime(0), 
		_attackTime(0), 
		_specialAttackTime(0), 
		_throwShellTime(0), 
		_deathTime(0), 
		_finishTime(0), 
		_jumpTime(0),
		_animation(Animation<State>()),
		_broughtMonster(nullptr)
	{
		loadPerso(_textureName);

		/* Setting animation Data */
		_animation.setCurrentState(_state);
	}

	HUD* Perso::getHUD()
	{
		return _hud;
	}

	Perso::State Perso::getState()
	{
		return _state;
	}

	Perso::Environment Perso::getEnvironment()
	{
		return _environment;
	}

	Perso::Transformations Perso::getTransformation()
	{
		return _transformation;
	}

	bool Perso::getCanClimb()
	{
		return _canClimb;
	}

	Vector2f Perso::getAcceleration()
	{
		return _acceleration;
	}

	MonsterOccurrence* Perso::getBroughtMonster()
	{
		return _broughtMonster;
	}

	Pipe* Perso::getInsidePipe()
	{
		return _insidePipe;
	}

	Checkpoint* Perso::getCheckPointPassed()
	{
		return _checkpointPassed;
	}

	int Perso::getInvincibleTime()
	{
		return _invincibleTime;
	}

	int Perso::getInvincibleStarTime()
	{
		return _invincibleStarTime;
	}

	int Perso::getTransformationTime()
	{
		return _transformationTime;
	}

	int Perso::getAttackTime()
	{
		return _attackTime;
	}

	int Perso::getSpecialAttackTime()
	{
		return _specialAttackTime;
	}

	int Perso::getThrowShellTime()
	{
		return _throwShellTime;
	}

	int Perso::getDeathTime()
	{
		return _deathTime;
	}

	int Perso::getFinishTime()
	{
		return _finishTime;
	}

	int Perso::getJumpTime()
	{
		return _jumpTime;
	}

	void Perso::setState(Perso::State state)
	{
		_animation.setCurrentState(state);
		_state = state;
	}

	void Perso::setEnvironment(const Environment &environment)
	{
		_environment = environment;
	}

	void Perso::setTransformation(const Transformations &transformation)
	{
		_transformation = transformation;
	}

	void Perso::setCanClimb(bool canClimb)
	{
		_canClimb = canClimb;
	}

	void Perso::setBroughtMonster(MonsterOccurrence* monster)
	{
		_broughtMonster = monster;
	}

	void Perso::setInsidePipe(Pipe* pipe)
	{
		_insidePipe = pipe;
	}

	void Perso::setCheckPointPassed(Checkpoint* checkpoint)
	{
		_checkpointPassed = checkpoint;
	}

	void Perso::setInvincibleTime(int invincibleTime)
	{
		_invincibleTime = invincibleTime;
	}

	void Perso::setInvincibleStarTime(int invincibleStarTime)
	{
		_invincibleStarTime = invincibleStarTime;
	}

	void Perso::setTransformationTime(int transformationTime)
	{
		_transformationTime = transformationTime;
	}

	void Perso::setAttackTime(int attackTime)
	{
		_attackTime = attackTime;
	}

	void Perso::setSpecialAttackTime(int specialAttackTime)
	{
		_specialAttackTime = specialAttackTime;
	}

	void Perso::setThrowShellTime(int throwShellTime)
	{
		_throwShellTime = throwShellTime;
	}

	void Perso::setDeathTime(int deathTime)
	{
		_deathTime = deathTime;
	}

	void Perso::setFinishTime(int finishTime)
	{
		_finishTime = finishTime;
	}

	void Perso::setJumpTime(int jumpTime)
	{
		_jumpTime = jumpTime;
	}

	void Perso::update(RenderWindow& app)
	{
		/* NOTHING */
	}

	void Perso::updatePerso(RenderWindow& app, InputState& inputState)
	{
		gravity(_speed, app.GetFrameTime());

		/* Lateral movements management */
		lateral_move(app, inputState);

		/* Save actual position as previous position */
		_previousPosition = _position;

		/* Compute new position */
		if(_position.y + _hitboxSize.y >= 0) // Bidouillage
			this->setPosition(_position.x + app.GetFrameTime() * _speed.x, 
			_position.y + app.GetFrameTime() * _speed.y);
		else
			this->setPosition(_position.x + app.GetFrameTime() * _speed.x, 
							_hitboxSize.y);

		/* Update animation */
		_animation.update(app);
	}

	void Perso::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, _side == LEFT_SIDE);
	}

	void Perso::lateral_move(RenderWindow& app, InputState& inputState)
	{
		int time = app.GetFrameTime();

		if(_state != FINISH_CASTLE)
		{
			if(_state != FINISH)
			{
				if(inputState[KEY_BACKWARD] == KEY_STATE_PRESSED)
					_side = LEFT_SIDE;
				else
					_side = RIGHT_SIDE;

				if(inputState[KEY_FORWARD] == KEY_STATE_PRESSED)
				{
					if(inputState[KEY_DOWN] == KEY_STATE_RELEASED)
					{
						if(_speed.x < 0)
						{
							if(_environment != AIR && _broughtMonster == nullptr && _state != SKID)
							{
								setState(SKID);
								// play a sound here !
							}
							frictions(time);
						}
						else
						{
							if(_broughtMonster == nullptr)
							{
								if(_environment == GROUND)
								{
									if(_state != CLIMB_LADDER)
									{
										if(inputState[KEY_RUN] == KEY_STATE_PRESSED)
										{
											setState(RUN_1);
										}
										else
										{
											setState(WALK);
										}
										_hud->setNbMonstersKilled(0);
									}
								}
							}
							else
							{
								if(_environment == GROUND)
								{
									setState(WALK_SHELL);
								}
							}
						}
						_speed.x = _speed.x + _acceleration.x * time;
					}
				}
				else if(inputState[KEY_BACKWARD] == KEY_STATE_PRESSED)
				{
					if(inputState[KEY_DOWN] == KEY_STATE_RELEASED)
					{
						if(_speed.x > 0)
						{
							if(_environment != AIR && _broughtMonster == nullptr && _state != SKID)
							{
								setState(SKID);
								// play a sound here !
							}
							frictions(time);
						}
						else
						{
							if(_broughtMonster == nullptr)
							{
								if(_environment == GROUND)
								{
									if(_state != CLIMB_LADDER)
									{
										if(inputState[KEY_RUN] == KEY_STATE_PRESSED)
										{
											setState(RUN_1);
										}
										else
										{
											setState(WALK);
										}
										_hud->setNbMonstersKilled(0);
									}
								}
							}
							else
							{
								if(_environment == GROUND)
								{
									setState(WALK_SHELL);
								}
							}
						}
						_speed.x = _speed.x - _acceleration.x * time;
					}
				}
				else if(!_specialAttackTime && !_attackTime){

					if(_broughtMonster == nullptr) 
					{
						if(_state == CLIMB_LADDER)
						{
							if(inputState[KEY_DOWN] == KEY_STATE_PRESSED)
								_speed.y = _speed.y - _acceleration.y * time;
							else if(inputState[KEY_UP] == KEY_STATE_PRESSED)
								_speed.y = _speed.y + _acceleration.y * time;
							else
								_speed.y = 0;

						}
						else
						{
							if(_environment == GROUND)
							{
								if(inputState[KEY_BACKWARD] == KEY_STATE_PRESSED)
									setState(LOWERED_JUMP);
							}
							else
							{
								setState(STANDING);
								_hud->setNbMonstersKilled(0);
							}
						}
					}
					else
					{
						if(_environment == AIR)
						{
							if(inputState[KEY_BACKWARD] == KEY_STATE_PRESSED)
							setState(LOWERED_JUMP_SHELL);
						}
						else
						{
							setState(STANDING_SHELL);
							_hud->setNbMonstersKilled(0);
						}
					}
				}
			}

			if((inputState[KEY_FORWARD] == KEY_STATE_RELEASED && inputState[KEY_BACKWARD] == KEY_STATE_RELEASED)
				|| (inputState[KEY_DOWN] == KEY_STATE_PRESSED && _environment == GROUND))
				frictions(time);
		}
		else
		{
			/* Character walks to castle without control on him */
			_speed.x = _acceleration.x * time;
		}
	}

	void Perso::hurted()
	{
		if(_transformation >= FIRE_MARIO)
		{
			transform(SUPER_MARIO);
			/*p->tps_invincible = 2000;
			p->tps_transformation = 1000;
			FSOUND_PlaySound(FSOUND_FREE, p->sons[SND_TOUCHE]);*/
		}
		else if(_transformation == SMALL_MARIO)
		{
			transform(SUPER_MARIO);
			setState(DEAD);
			_speed.x = 0;
			_speed.y = EJECTION_SPEED_Y * 5;
			/*p->tps_mort = TPS_MORT;
			FSOUND_PlaySound(FSOUND_FREE, p->sons[SND_DIE]);
			FSOUND_Stream_Stop(n->musique);*/
		}
		else
		{
			transform(SMALL_MARIO);
			/*p->tps_invincible = 2000;
			p->tps_transformation = 1000;
			FSOUND_PlaySound(FSOUND_FREE, p->sons[SND_TOUCHE]);*/
		}
	}

	void Perso::transform(Transformations nextTransformation)
	{
		/* Selon le futur état du personnage,
		on charge la texture appropriée */
		switch(nextTransformation) {
		case SMALL_MARIO :
			loadPerso("small_mario");
			_transformation = SMALL_MARIO;

			/* Faire correspondre les deux coins bas_gauche de la hitbox */
			//p->position.x = p->position.x + (copy.abscisse_bas - p->texture_act->abscisse_bas);
			break;
		case SUPER_MARIO :
			loadPerso("super_mario");
			_transformation = SUPER_MARIO;

			/* Faire correspondre les deux coins bas_gauche de la hitbox */
			//p->position.x = p->position.x + (copy.abscisse_bas - p->texture_act->abscisse_bas);
			break;
		case FIRE_MARIO :
			loadPerso("fire_mario");
			_transformation = FIRE_MARIO;
			break;
		case ICE_MARIO :
			loadPerso("ice_mario");
			_transformation = ICE_MARIO;
			break;
		default : break;
		}
	}

	void Perso::frictions(float time)
	{
		float coeff;

		/* Frictions are different according to environment*/
		if(_environment == GROUND)
			coeff = CLASSIC_COEFF_FRICTION;
		else
			coeff = AIR_COEFF_FRICTION;

		if(time != 0)
		{
			_speed.x /= 1 + 5 * coeff * time * SLIDE_COEFF_FRICTION;
		}

		/* To avoid character moving suddenly of one pixel after a moment of immobility */
		if(_speed.x < SPEED_X_MIN && _speed.x > -SPEED_X_MIN)
			_speed.x = 0;
	}

	void Perso::updateInPipe()
	{
		switch(_insidePipe->getDirection())
		{
		case Pipe::TO_TOP:
			setState(GET_OUT_FROM_PIPE_VERTICAL);
			_position.x = _insidePipe->getPosition().x * BLOCK_WIDTH + BLOCK_WIDTH - _hitboxSize.x / 2;
			_position.y = _insidePipe->getPosition().y * BLOCK_WIDTH + (_insidePipe->getLenght() + 1) * BLOCK_WIDTH - _hitboxSize.y;
			break;

		case Pipe::TO_BOTTOM:
			setState(GET_OUT_FROM_PIPE_VERTICAL);
			_position.x = _insidePipe->getPosition().x * BLOCK_WIDTH + BLOCK_WIDTH - _hitboxSize.x / 2;
			_position.y = _insidePipe->getPosition().y * BLOCK_WIDTH;
			break;

		case Pipe::TO_LEFT:
			_side = RIGHT_SIDE;
			_state = GET_OUT_FROM_PIPE_HORIZONTAL;
			_position.x = (_insidePipe->getPosition().x + _insidePipe->getLenght()) * BLOCK_WIDTH, 
				_position.y = _insidePipe->getPosition().y * BLOCK_WIDTH;
			break;

		case Pipe::TO_RIGHT:
			_side = LEFT_SIDE;
			_state = GET_OUT_FROM_PIPE_HORIZONTAL;
			_position.x = _insidePipe->getPosition().x * BLOCK_WIDTH;
			_position.y = _insidePipe->getPosition().y * BLOCK_WIDTH;
			break;

		default :
			break;
		}
		// Play sound pipe here !
	}

	void Perso::loadPerso(const string& textureName)
	{
		int abscisse_bas = 0, ordonnee_haut = 0;

		string fileName = textureName + ".perso";
		ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				/* Main keywords */
				int found = word.find("abscisse_bas=");
				if(found != string::npos)
				{
					istringstream abscisseBas(word.substr(found + 13));
					abscisseBas >> abscisse_bas;
					continue;
				}
				
				found = word.find("ordonnee_haut=");
				if(found != string::npos)
				{
					istringstream ordonneeHaut(word.substr(found + 14));
					ordonneeHaut >> ordonnee_haut;
					continue;
				}

				{ /* 'nb_sprites_xxx' keyword */
					found = word.find("nb_sprites_standing=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbWalkingSpritesStream(word.substr(found + 20));
						nbWalkingSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::STANDING, nbSprites);
						continue;
					}


					found = word.find("nb_sprites_walk=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbWalkingSpritesStream(word.substr(found + 16));
						nbWalkingSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::WALK, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_run=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbRunningSpritesStream(word.substr(found + 15));
						nbRunningSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::RUN_1, nbSprites);
						_animation.addNbSpritesForGivenState(State::RUN_2, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_skid=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSkidSpritesStream(word.substr(found + 16));
						nbSkidSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::SKID, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_jump=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbJumpSpritesStream(word.substr(found + 16));
						nbJumpSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::JUMP, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_jump_falling=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbJumpSpritesStream(word.substr(found + 24));
						nbJumpSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::JUMP_FALLING, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_fly=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSwimmingSpritesStream(word.substr(found + 15));
						nbSwimmingSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::FLY, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_face=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbFaceSpritesStream(word.substr(found + 16));
						nbFaceSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::GET_IN_FROM_PIPE_VERTICAL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_back=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbBackSpritesStream(word.substr(found + 16));
						nbBackSpritesStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::BACK, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_look_top=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 20));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::LOOK_TOP, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_lowered=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 19));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::LOWERED, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_climb_ladder=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 24));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::CLIMB_LADDER, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_standing_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 26));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::STANDING_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_walk_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 22));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::WALK_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_push_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 22));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::PUSH_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_jump_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 22));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::JUMP_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_lowered_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 24));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::LOWERED_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_look_top_shell=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 26));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::LOOK_TOP_SHELL, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_dead=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 16));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::DEAD, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_attack=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 18));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::ATTACK, nbSprites);
						continue;
					}

					found = word.find("nb_sprites_special_attack=");
					if(found != string::npos)
					{
						int nbSprites = 0;
						istringstream nbSpriteStream(word.substr(found + 26));
						nbSpriteStream >> nbSprites;
						_animation.addNbSpritesForGivenState(State::SPECIAL_ATTACK, nbSprites);
					}
				}

				{ /* 'frame_delay_xxx' keyword */
					found = word.find("frame_delay_walk=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 17));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::WALK, frameDelay);
						continue;
					}

					found = word.find("frame_delay_run1=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 17));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::RUN_1, frameDelay);
						continue;
					}

					found = word.find("frame_delay_run2=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 17));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::RUN_2, frameDelay);
						continue;
					}


					found = word.find("frame_delay_skid=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 17));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::SKID, frameDelay);
						continue;
					}

					found = word.find("frame_delay_jump_falling=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 25));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::JUMP_FALLING, frameDelay);
						continue;
					}

					found = word.find("frame_delay_look_top=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 20));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::LOOK_TOP, frameDelay);
						continue;
					}

					found = word.find("frame_delay_climb_ladder=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 25));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::CLIMB_LADDER, frameDelay);
						continue;
					}

					found = word.find("frame_delay_walk_shell=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 23));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::WALK_SHELL, frameDelay);
						continue;
					}

					found = word.find("frame_delay_look_top_shell=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 27));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::LOOK_TOP_SHELL, frameDelay);
						continue;
					}

					found = word.find("frame_delay_dead=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 17));
						frameDelayStringStream >> frameDelay;
						_animation.addNbSpritesForGivenState(State::DEAD, frameDelay);
						continue;
					}

					found = word.find("frame_delay_attack=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 19));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::ATTACK, frameDelay);
						continue;
					}

					found = word.find("frame_delay_special_attack=");
					if(found != string::npos)
					{
						int frameDelay = 0;
						istringstream frameDelayStringStream(word.substr(found + 27));
						frameDelayStringStream >> frameDelay;
						_animation.addFrameDelayForGivenState(State::SPECIAL_ATTACK, frameDelay);
					}
				}
			}
			
			/* Compute Hitbox Size */
			_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax() - 2 * abscisse_bas;
			_hitboxSize.y = ordonnee_haut;
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}


	Perso::~Perso()
	{
		delete _hud;
	}
} // namespace
