////////////////////////////////////////////////////////////////////////
// ResourceManager.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"

namespace SuperMarioProject
{
    std::map<std::string, Resource*> ResourceManager::_resources = std::map<std::string, Resource*>();
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


    Rendering::Texture *ResourceManager::getTexture(const std::string &name)
    {
        return get<Rendering::Texture>(name);
    }


    Collisions::Item *ResourceManager::getItem(const std::string &name)
    {
        return get<Collisions::Item>(name);
    }


    Collisions::Monster *ResourceManager::getMonster(const std::string &name)
    {
        return get<Collisions::Monster>(name);
    }


    Collisions::Projectile *ResourceManager::getProjectile(const std::string &name)
    {
        return get<Collisions::Projectile>(name);
    }


    void ResourceManager::remove(Resource *res)
    {
        string name = res->name();

        if(_resources.find(name) == _resources.end())
            // une exception serait pas mal ici
            std::cerr << "La ressource " + name + " n'est pas presente dans le gestionnaire: suppression impossible" << std::endl;
        else
            _resources.erase(name);

        delete res;
    }
} // namespace
