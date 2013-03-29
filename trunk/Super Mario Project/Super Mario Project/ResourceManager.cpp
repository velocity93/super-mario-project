////////////////////////////////////////////////////////////////////////
// ResourceManager.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "Projectile.hpp"
#include "ResourceManager.hpp"
#include "Resource.hpp"
#include <iostream>

using namespace std;

namespace smp
{
    map<std::string, Resource*> ResourceManager::_resources = map<std::string, Resource*>();
	ResourceManager* ResourceManager::_manager = NULL;

	ResourceManager* ResourceManager::getResourceManager()
	{
		if(_manager == NULL)
		{
			_manager = new ResourceManager();
		}

		return _manager;
	}

	void ResourceManager::killManager()
	{
		if(_manager != NULL)
			delete _manager;
	}

    ResourceManager::ResourceManager()
    {
    }


    ResourceManager::~ResourceManager()
    {
    }


    Texture *ResourceManager::getTexture(const string &name)
    {
        return get<Texture>(name);
    }


    Item *ResourceManager::getItem(const string &name)
    {
        return get<Item>(name);
    }


    Monster *ResourceManager::getMonster(const string &name)
    {
        return get<Monster>(name);
    }


    Projectile *ResourceManager::getProjectile(const string &name)
    {
        return get<Projectile>(name);
    }


    void ResourceManager::remove(Resource *res)
    {
        string name = res->name();

        if(_resources.find(name) == _resources.end())
            // une exception serait pas mal ici
            cerr << "La ressource " + name + " n'est pas presente dans le gestionnaire: suppression impossible" << std::endl;
        else
            _resources.erase(name);

        delete res;
    }
} // namespace
