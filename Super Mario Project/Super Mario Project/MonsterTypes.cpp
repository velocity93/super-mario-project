////////////////////////////////////////////////////////////////////////
// MonsterTypes.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MonsterTypes.hpp"
#include <fstream>
#include <sstream>

using namespace std;

namespace smp
{
	WalkingMonster::WalkingMonster(const string& textureName, bool canBeKilledByJump, bool canBeKilledByFire, bool canBeJumpedOn, bool stayOnPlateForm)
		: Monster(textureName, canBeKilledByJump, canBeKilledByFire, canBeJumpedOn), 
		_stayOnPlateForm(stayOnPlateForm)
	{
		loadWalkingMonster();
	}

	void WalkingMonster::serialize(ofstream& file, string& tabs)
	{
		file << tabs << "<walking_monster ";
		file << "name=\"" << shorterName() << "\"";

		if(_monsterOccurrences.size() > 0)
		{
			file << ">" << endl;
			tabs += '\t';
			for(vector<MonsterOccurrence*>::iterator itMonster = _monsterOccurrences.begin();
				itMonster < _monsterOccurrences.end(); ++itMonster)
			{
				file << tabs << "<occ_monster ";
				file << "positionX=\"" << (*itMonster)->getPosition().x << "\" ";
				file << "positionY=\"" << (*itMonster)->getPosition().y << "\"/>" << endl;
			}
			//tabs.pop_back();
			file << tabs << "</walking_monster>" << endl;
		}
		else
		{
			file << "/>" << endl;
		}
	}

	void WalkingMonster::loadWalkingMonster()
	{
		string fileName = name() + ".mstr";
        ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("stay_on_plateform=");
                if(found != string::npos)
                {
                    istringstream stayOnPlateform(word.substr(found + 18));
					stayOnPlateform >> _stayOnPlateForm;
                    continue;
                }

				found = word.find("nb_sprites_walk=");
                if(found != string::npos)
                {
					int nbWalkSprites;
                    istringstream nbWalkSpritesStream(word.substr(found + 16));
                    nbWalkSpritesStream >> nbWalkSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::WALK, nbWalkSprites));
                    continue;
                }

                found = word.find("nb_sprites_dead_by_jump=");
                if(found != string::npos)
                {
					int nbDeadSprites;
                    istringstream nbDeadSpritesStream(word.substr(found + 24));
                    nbDeadSpritesStream >> nbDeadSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::DEAD_BY_JUMP_ON, nbDeadSprites));
                    continue;
                }

				found = word.find("nb_sprites_dead_by_proj=");
                if(found != string::npos)
                {
					int nbDeadSprites;
                    istringstream nbDeadSpritesStream(word.substr(found + 24));
                    nbDeadSpritesStream >> nbDeadSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::DEAD_BY_PROJ, nbDeadSprites));
                    continue;
                }

				found = word.find("frame_delay_walk=");
                if(found != string::npos)
                {
					int vWalkAnim;
                    istringstream vWalkAnimStream(word.substr(found + 17));
                    vWalkAnimStream >> vWalkAnim;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::WALK, vWalkAnim));
                    continue;
                }

                found = word.find("frame_delay_dead_by_jump=");
                if(found != string::npos)
                {
					int vDeadAnim;
                    istringstream vDeadAnimStream(word.substr(found + 25));
                    vDeadAnimStream >> vDeadAnim;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::DEAD_BY_JUMP_ON, vDeadAnim));
                    continue;
                }

				found = word.find("frame_delay_dead_by_proj=");
                if(found != string::npos)
                {
					int vDeadAnim;
                    istringstream vDeadAnimStream(word.substr(found + 25));
                    vDeadAnimStream >> vDeadAnim;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::DEAD_BY_PROJ, vDeadAnim));
                }
			}
		}
		else
		{
			throw "Exception occured while opening " + fileName;
		}
	}

	/* SHELL MONSTER */

	ShellMonster::ShellMonster(const string& textureName, bool canBeKilledByFire, bool canBeJumpedOn, bool stayOnPlateForm)
		: WalkingMonster(textureName, false, canBeKilledByFire, canBeJumpedOn, stayOnPlateForm)
	{
		loadShellMonster();
	}

	void ShellMonster::serialize(ofstream& file, string& tabs)
	{
		file << tabs << "<shell_monster ";
		file << "name=\"" << shorterName() << "\"";

		if(_monsterOccurrences.size() > 0)
		{
			file << ">" << endl;
			tabs += '\t';
			for(vector<MonsterOccurrence*>::iterator itMonster = _monsterOccurrences.begin();
				itMonster < _monsterOccurrences.end(); ++itMonster)
			{
				file << tabs << "<occ_monster ";
				file << "positionX=\"" << (*itMonster)->getPosition().x << "\" ";
				file << "positionY=\"" << (*itMonster)->getPosition().y << "\"/>" << endl;
			}
			//tabs.pop_back();
			file << tabs << "</shell_monster>" << endl;
		}
		else
		{
			file << "/>" << endl;
		}
	}

	void ShellMonster::loadShellMonster()
	{
		string fileName = name() + ".mstr";
        ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("nb_sprites_retracted=");
                if(found != string::npos)
                {
					int nbShellSprites;
                    istringstream nbShellSpritesStream(word.substr(found + 21));
                    nbShellSpritesStream >> nbShellSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::RETRACTED, nbShellSprites));
                    continue;
                }

                found = word.find("nb_sprites_get_out_from_shell=");
                if(found != string::npos)
                {
					int nbShellSprites;
                    istringstream nbShellSpritesStream(word.substr(found + 30));
                    nbShellSpritesStream >> nbShellSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::GET_OUT_FROM_SHELL, nbShellSprites));
                    continue;
                }

				found = word.find("frame_delay_retracted=");
                if(found != string::npos)
                {
					int vShellAnim;
                    istringstream vShellAnimStream(word.substr(found + 22));
                    vShellAnimStream >> vShellAnim;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::RETRACTED, vShellAnim));
                    continue;
                }

				found = word.find("frame_delay_get_out_from_shell=");
                if(found != string::npos)
                {
					int vShellAnim;
                    istringstream vShellAnimStream(word.substr(found + 31));
                    vShellAnimStream >> vShellAnim;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::GET_OUT_FROM_SHELL, vShellAnim));
                    continue;
                }
			}
		}
		else
		{
			throw "Exception occured while opening " + fileName;
		}
	}

	/* FLYING MONSTER */

	FlyingMonster::FlyingMonster(const string& textureName, bool canBeKilledByJump, bool canBeKilledByFire, bool canBeJumpedOn)
		: Monster(textureName, canBeKilledByJump, canBeKilledByFire, canBeJumpedOn)
	{
		loadFlyingMonster();
	}

	void FlyingMonster::serialize(ofstream& file, string& tabs)
	{
		file << tabs << "<flyng_monster ";
		file << "name=\"" << shorterName() << "\"";

		if(_monsterOccurrences.size() > 0)
		{
			file << ">" << endl;
			tabs += '\t';
			for(vector<MonsterOccurrence*>::iterator itMonster = _monsterOccurrences.begin();
				itMonster < _monsterOccurrences.end(); ++itMonster)
			{
				file << tabs << "<occ_monster ";
				file << "positionX=\"" << (*itMonster)->getPosition().x << "\" ";
				file << "positionY=\"" << (*itMonster)->getPosition().y << "\"/>" << endl;
			}
			//tabs.pop_back();
			file << tabs << "</flyng_monster>" << endl;
		}
		else
		{
			file << "/>" << endl;
		}
	}

	void FlyingMonster::loadFlyingMonster()
	{
		string fileName = name() + ".mstr";
        //int abscisse_bas = 0;
        ifstream stream(fileName.c_str());

        if(stream)
        {
			//TO DO
		}
        else
        {
            throw "Exception occured while opening " + fileName;
        }
	}
}
