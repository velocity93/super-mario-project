////////////////////////////////////////////////////////////////////////
// XMLWriter.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLWriter.hpp"
#include "World.hpp"
#include "Level.hpp"
#include <iostream>
#include <cstdarg>

using namespace std;

namespace SuperMarioProject
{
	int XMLWriter::_tabs = 0;
	
	void XMLWriter::openElement(ofstream& file, const string& name)
	{
		for(int i = 0; i < _tabs; i++)
			file << '\t';

		_tabs++;
		file << "<" << name;
	}

	void XMLWriter::endElement(ofstream& file)
	{
		file << ">" << endl;
	}


	void XMLWriter::closeElement(ofstream& file, const string& name)
	{
		_tabs--;

		for(int i = 0; i < _tabs; i++)
			file << '\t';

		file << "</" << name << ">" << endl;
	}


	void XMLWriter::closeShortElement(ofstream& file)
	{
		_tabs--;

		file << "/>" << endl;
	}


	void XMLWriter::addAttribute(ofstream& file, const string& name, const string& format, ...)
	{
		va_list va;
		char value[256];

		va_start(va, format);
		vsnprintf(value, 256, format.c_str(), va);
		//value = va_arg(va, string);
		va_end(va);

		file << " " << name << "=\"" << value << "\"";
	}

	void XMLWriter::saveLevel(const string& fileName, Level* level)
	{
		ofstream file(fileName.c_str());
		
		if(file)
		{
			/* Header */
			file << "<?xml version=\"1.0\" ?>" << endl;

			/* Level */
			openElement(file, "level");
			addAttribute(file, "name", "%s", level->getName());
			addAttribute(file, "size", "%d:%d", level->getSize().x, level->getSize().y);
			addAttribute(file, "music", "%s", level->getMusicTitle());
			
			// For schema valdiation
			file << "xmlns_xsi=\"http_//www.w3.org/2001/XMLSchema-instance\" xsi_noNamespaceSchemaLocation=\"level.xsd\"";
			endElement(file);

			/* Spawn */
			openElement(file, "spawn");
			addAttribute(file, "positionX", "%d", level->getSpawn().x);
			addAttribute(file, "positionY", "%d", level->getSpawn().y);
			closeShortElement(file);

			/* Checkpoints */
			openElement(file, "checkpoints");
			if(level->getCheckpoints().size() > 0)
			{
				endElement(file);
				for(vector<Checkpoint*>::iterator itCheckpoint = level->getCheckpoints().begin();
					itCheckpoint < level->getCheckpoints().end(); itCheckpoint++)
				{
					openElement(file, "checkpoint");
					addAttribute(file, "img", "%s", (*itCheckpoint)->getTexture()->mainName());
					addAttribute(file, "positionX", "%d", (*itCheckpoint)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itCheckpoint)->getPosition().y);
					closeShortElement(file);
				}
				closeElement(file, "checkpoints");
			}
			else
			{
				closeShortElement(file);
			}

			/* Backgrounds */
			openElement(file, "backgrounds");
			if(level->getBackgrounds().size() > 0)
			{
				endElement(file);
				for(vector<Background*>::iterator itBackground = level->getBackgrounds().begin();
					itBackground < level->getBackgrounds().end(); itBackground++)
				{
					openElement(file, "background");
					addAttribute(file, "img", "%s", (*itBackground)->getTexture()->mainName());
					addAttribute(file, "positionX", "%d", (*itBackground)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itBackground)->getPosition().y);
					closeShortElement(file);
				}
				closeElement(file, "backgrounds");
			}
			else
			{
				closeShortElement(file);
			}

			/* Foregrounds */
			openElement(file, "foregrounds");
			if(level->getForegrounds().size() > 0)
			{
				endElement(file);
				for(vector<Foreground*>::iterator itForeground = level->getForegrounds().begin();
					itForeground < level->getForegrounds().end(); itForeground++)
				{
					openElement(file, "foreground");
					addAttribute(file, "img", "%s", (*itForeground)->getTexture()->mainName());
					addAttribute(file, "positionX", "%d", (*itForeground)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itForeground)->getPosition().y);
					closeShortElement(file);
				}
				closeElement(file, "foregrounds");
			}
			else
			{
				closeShortElement(file);
			}

			/* Objects */
			openElement(file, "objects");
			if(level->getObjects().size() > 0)
			{
				endElement(file);
				for(vector<Object*>::iterator itObject = level->getObjects().begin();
					itObject < level->getObjects().end(); itObject++)
				{
					openElement(file, "object");
					addAttribute(file, "img", "%s", (*itObject)->getTexture()->mainName());
					addAttribute(file, "positionX", "%d", (*itObject)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itObject)->getPosition().y);
					closeShortElement(file);
				}
				closeElement(file, "objects"); 
			}
			else
			{
				closeShortElement(file);
			}

			/* Finish */
			openElement(file, "finishes");
			if(level->getFinishes().size() > 0)
			{
				endElement(file);
				for(vector<Finish*>::iterator itFinish = level->getFinishes().begin();
					itFinish < level->getFinishes().end(); itFinish++)
				{
					openElement(file, "object");
					addAttribute(file, "img", "%s", (*itFinish)->getTexture()->mainName());
					addAttribute(file, "positionX", "%d", (*itFinish)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itFinish)->getPosition().y);
					closeShortElement(file);
				}
				closeElement(file, "objects"); 
			}
			else
			{
				closeShortElement(file);
			}

			/* Projectiles */
			openElement(file, "projectiles");
			if(level->getProjectiles().size() > 0)
			{
				endElement(file);
				for(vector<Projectile*>::iterator itProjectile = level->getProjectiles().begin();
					itProjectile < level->getProjectiles().end(); itProjectile++)
				{
					openElement(file, "projectile");
					addAttribute(file, "img", "%s", (*itProjectile)->mainName());
					closeShortElement(file);
				}
				closeElement(file, "projectiles");
			}
			else
			{
				closeShortElement(file);
			}

			/* Items */
			openElement(file, "items");
			if(level->getItems().size() > 0)
			{
				endElement(file);
				for(int index = 0; index < level->getItems().size(); ++index)
				{
					Item* item = level->getItems().at(index);

					openElement(file, "item");
					addAttribute(file, "img", "%s", item->mainName());
					addAttribute(file, "type", "%d", item->getType());

					if(item->getItemOccurrences().size() > 0)
					{
						endElement(file);
						for(vector<ItemOccurrence*>::iterator itItem = item->getItemOccurrences().begin();
							itItem < item->getItemOccurrences().end(); ++itItem)
						{
							openElement(file, "occ_item");
							addAttribute(file, "positionX", "%d", (*itItem)->getPosition().x);
							addAttribute(file, "positionY", "%d", (*itItem)->getPosition().y);
							closeShortElement(file);
						}
						closeElement(file, "item");
					}
					else
					{
						closeShortElement(file);
					}
				}
				closeElement(file, "items");
			}
			else
			{
				closeShortElement(file);
			}

			/* Monsters */
			openElement(file, "monsters");
			if(level->getMonsters().size() > 0)
			{
				endElement(file);
				for(int index = 0; index < level->getMonsters().size(); ++index)
				{
					Monster* monster = level->getMonsters().at(index);

					openElement(file, "monster");
					addAttribute(file, "img", "%s", monster->mainName());
					endElement(file);

					if(monster->getMonsterOccurrences().size() > 0)
					{
						for(vector<MonsterOccurrence*>::iterator itMonster = monster->getMonsterOccurrences().begin();
							itMonster < monster->getMonsterOccurrences().end(); ++itMonster)
						{
							openElement(file, "occ_monster");
							addAttribute(file, "positionX", "%d", (*itMonster)->getPosition().x);
							addAttribute(file, "positionY", "%d", (*itMonster)->getPosition().y);
							closeShortElement(file);
						}
						closeElement(file, "monster");
					}
					else
					{
						closeShortElement(file);
					}
				}
				closeElement(file, "monsters");
			}
			else
			{
				closeShortElement(file);
			}

			/* Pipes */
			openElement(file, "pipes");
			if(level->getPipes().size() > 0)
			{
				endElement(file);
				
				for(vector<Pipe*>::iterator itPipe = level->getPipes().begin();
					itPipe < level->getPipes().end(); ++itPipe)
				{
					
					openElement(file, "pipe");
					addAttribute(file, "img", "%s", (*itPipe)->getTexture()->mainName());
					addAttribute(file, "sens", "%d", (*itPipe)->getDirection());
					addAttribute(file, "length", "%d", (*itPipe)->getLenght());
					addAttribute(file, "positionX", "%d", (*itPipe)->getPosition().x);
					addAttribute(file, "positionY", "%d", (*itPipe)->getPosition().y);
					addAttribute(file, "state", "%d", (*itPipe)->getState());
					addAttribute(file, "destination_pipe", "%d",  (*itPipe)->getPipeDestination());
					addAttribute(file, "level_destination", "%s", (*itPipe)->getLevelDestination());

					//addAttribute(file, "monster", "%d", get);

					closeShortElement(file);
				}
				closeElement(file, "pipes");
			}
			else
			{
				closeShortElement(file);
			}







		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}
}