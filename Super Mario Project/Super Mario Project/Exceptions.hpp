////////////////////////////////////////////////////////////////////////
// Exceptions.hpp
// Super Mario Project
// Copyright (C) 2011 
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_EXCEPTIONS
#define HPP_EXCEPTIONS

#include <exception>
#include <sstream>

namespace smp
{
	class FileException: public std::exception
	{
	protected:
		const std::string _fileName;

	public:
		FileException(const std::string &fileName) : _fileName(fileName) {}
		virtual const char* what() { return ("Error occured while loading file: " + _fileName).c_str(); }
	};

	class FileNotFoundException: public FileException
	{
	public:
		FileNotFoundException(const std::string &fileName) : FileException(fileName) {}
		virtual const char* what() { return ("File not found: " + _fileName).c_str(); }
	};

	class FileParseException: public FileException
	{
	protected:
		const int _line;

	public:
		FileParseException(const std::string &fileName, int line = -1) : FileException(fileName), _line(line) {}
		virtual const char* what() { std::stringstream ss; ss << _line; return ("Error while loading file " + _fileName + ":" + ss.str()).c_str(); }
	};
} // namespace

#endif // HPP_EXCEPTIONS
