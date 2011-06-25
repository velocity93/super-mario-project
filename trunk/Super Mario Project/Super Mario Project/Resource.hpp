////////////////////////////////////////////////////////////////////////
// Resource.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCE
#define HPP_RESOURCE

#include <string>

namespace SuperMarioProject
{
    class ResourceManager;

    class Resource
    {
    public:
        Resource(std::string name);
        virtual ~Resource() = 0;
        const std::string &name() const;
		void addRef();
        void release();

    private:
        std::string _name;
        int _refCount;
    };
} // namespace

#endif // HPP_RESOURCE
