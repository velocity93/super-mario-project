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

namespace Collisions
{
	WalkingMonster::WalkingMonster(const string& textureName, bool canBeKilledByJump, bool canBeKilledByFire, bool canBeJumpedOn, bool stayOnPlateForm)
		: Monster(textureName, canBeKilledByJump, canBeKilledByFire, canBeJumpedOn, stayOnPlateForm)
	{
		loadWalkingMonster();
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
				int found = word.find("nb_sprites_marche=");
                if(found != string::npos)
                {
					int nbWalkSprites;
                    istringstream nbWalkSpritesStream(word.substr(found + 18));
                    nbWalkSpritesStream >> nbWalkSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_WALK, nbWalkSprites));
                    continue;
                }

                found = word.find("nb_sprites_mort_par_saut=");
                if(found != string::npos)
                {
					int nbDeadSprites;
                    istringstream nbDeadSpritesStream(word.substr(found + 25));
                    nbDeadSpritesStream >> nbDeadSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_JUMP_ON, nbDeadSprites));
                    continue;
                }

				found = word.find("nb_sprites_mort_par_proj=");
                if(found != string::npos)
                {
					int nbDeadSprites;
                    istringstream nbDeadSpritesStream(word.substr(found + 25));
                    nbDeadSpritesStream >> nbDeadSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_PROJ, nbDeadSprites));
                    continue;
                }

				found = word.find("v_anim_marche=");
                if(found != string::npos)
                {
					int vWalkAnim;
                    istringstream vWalkAnimStream(word.substr(found + 14));
                    vWalkAnimStream >> vWalkAnim;
					_vAnimByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_WALK, vWalkAnim));
                    continue;
                }

                found = word.find("v_anim_mort_par_saut=");
                if(found != string::npos)
                {
					int vDeadAnim;
                    istringstream vDeadAnimStream(word.substr(found + 25));
                    vDeadAnimStream >> vDeadAnim;
					_vAnimByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_JUMP_ON, vDeadAnim));
                    continue;
                }

				found = word.find("v_anim_mort_par_proj=");
                if(found != string::npos)
                {
					int vDeadAnim;
                    istringstream vDeadAnimStream(word.substr(found + 25));
                    vDeadAnimStream >> vDeadAnim;
					_vAnimByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_PROJ, vDeadAnim));
                }
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}


	ShellMonster::ShellMonster(const string& textureName, bool canBeKilledByJump, bool canBeKilledByFire, bool canBeJumpedOn, bool stayOnPlateForm)
		: WalkingMonster(textureName, false, canBeKilledByFire, canBeJumpedOn, stayOnPlateForm)
	{
		loadShellMonster();
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
				int found = word.find("nb_sprites_carapace=");
                if(found != string::npos)
                {
					int nbShellSprites;
                    istringstream nbShellSpritesStream(word.substr(found + 20));
                    nbShellSpritesStream >> nbShellSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_RETRACTED, nbShellSprites));
                    continue;
                }

                found = word.find("nb_sprites_sortie_carapace=");
                if(found != string::npos)
                {
					int nbShellSprites;
                    istringstream nbShellSpritesStream(word.substr(found + 28));
                    nbShellSpritesStream >> nbShellSprites;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_GET_OUT_FROM_SHELL, nbShellSprites));
                    continue;
                }

				found = word.find("v_anim_carapace=");
                if(found != string::npos)
                {
					int vShellAnim;
                    istringstream vShellAnimStream(word.substr(found + 16));
                    vShellAnimStream >> vShellAnim;
					_vAnimByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_RETRACTED, vShellAnim));
                    continue;
                }

				found = word.find("v_anim_sortie_carapace=");
                if(found != string::npos)
                {
					int vShellAnim;
                    istringstream vShellAnimStream(word.substr(found + 23));
                    vShellAnimStream >> vShellAnim;
					_vAnimByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_GET_OUT_FROM_SHELL, vShellAnim));
                    continue;
                }
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

	FlyingMonster::FlyingMonster(const string& textureName, bool canBeKilledByJump, bool canBeKilledByFire, bool canBeJumpedOn, bool stayOnPlateForm)
		: Monster(textureName, canBeKilledByJump, canBeKilledByFire, canBeJumpedOn, stayOnPlateForm)
	{
		loadFlyingMonster();
	}

	void FlyingMonster::loadFlyingMonster()
	{
		string fileName = name() + ".mstr";
        int abscisse_bas = 0;
        ifstream stream(fileName.c_str());

        if(stream)
        {

		}
        else
        {
            string exceptionName = "Exception occured while opening " + fileName;
            throw exception(exceptionName.c_str());
        }
	}
}