////////////////////////////////////////////////////////////////////////
// ResourceManager.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCEMANAGER
#define HPP_RESOURCEMANAGER

#include <map>
#include <string>

namespace smp
{
    // forward declaration
    class Resource;
    class Texture;
    class Item;
    class Monster;
    class Projectile;

    class ResourceManager
    {
    public:
        static ResourceManager* getResourceManager();
		static void killManager();

        static void remove(Resource *res);
        static Texture *getTexture(const std::string &name);
        static Item *getItem(const std::string &name);
        static Monster *getMonster(const std::string &name);
        static Projectile *getProjectile(const std::string &name);

    private:
		ResourceManager();
        ~ResourceManager();

        template <typename T>
        static T *get(const std::string &name);

        static std::map<std::string, Resource*> _resources;
		static ResourceManager* _manager;
    };

#include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
