////////////////////////////////////////////////////////////////////////
// Resource.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
T *ResourceManager::get(const std::string &name)
{
    T *res; // deux qui la tiennent....

    if(_resources.find(name) == _resources.end())
    {
        res = new T(name);
        _resources[name] = res;
    }
    else
        res = static_cast<T *>(_resources[name]);

    res->addRef();

    return res;
}
