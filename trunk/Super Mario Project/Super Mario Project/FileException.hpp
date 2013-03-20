////////////////////////////////////////////////////////////////////////
// FileException.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_FILE_EXCEPTION
#define HPP_FILE_EXCEPTION

#include <exception>
#include <string>

using namespace std;

namespace SuperMarioProject
{
	class FileException : exception
	{
	public :
		FileException(string const& msg="") throw()
			:message(msg)
		{}

		virtual const char* what() const throw()
		{
			return message.c_str();
		}

		virtual FileException() throw()
		{}

	private:
		string message;            // Description de l'erreur
	}
}

#endif