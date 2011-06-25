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
#include "Resource.hpp"
#include "Texture.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "Projectile.hpp"

namespace SuperMarioProject
{
    class ResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();

        static void remove(Resource *res);
        static Rendering::Texture *getTexture(const std::string &name);
        static Collisions::Item *getItem(const std::string &name);
        static Collisions::Monster *getMonster(const std::string &name);
        static Collisions::Projectile *getProjectile(const std::string &name);

    private:
        template <typename T>
        static T *get(const std::string &name);

        static std::map<std::string, Resource*> _resources;
    };

#include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
