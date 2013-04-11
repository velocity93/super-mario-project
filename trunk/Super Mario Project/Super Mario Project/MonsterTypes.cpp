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
	WalkingMonster::WalkingMonster(const string& textureName)
		: Monster(textureName)
	{
		
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

	/* SHELL MONSTER */

	ShellMonster::ShellMonster(const string& textureName)
		: WalkingMonster(textureName)
	{
		
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

	/* FLYING MONSTER */

	FlyingMonster::FlyingMonster(const string& textureName)
		: Monster(textureName)
	{
		
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
}
