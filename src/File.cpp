/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : File
 *
 * Author      : Denis Dowling
 * Created     : 14/12/2009
 *
 * Description : Helper functions for working with files
 */
#include "File.h"
#include "String.h"
#include <fstream>
#include <boost/foreach.hpp>

using namespace report_generator;

std::string File::findOnPath(const std::string &colon_path,
                             const std::string &file)
{
    std::vector<std::string> path = split_string(colon_path, ":");

    return findOnPath(path, file);
}

std::string File::findOnPath(const std::vector<std::string> &path,
                             const std::string &file)
{
    BOOST_FOREACH(const std::string &pp, path)
    {
	std::string p = pp + "/" + file;

	FILE *fd = fopen(p.c_str(), "r");

	if (fd != 0)
	{
	    fclose(fd);
	    return p;
	}
    }

    return "";
}

size_t File::getSize(const std::string &filename)
{
    std::ifstream file(filename.c_str(),
		       std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open())
        return file.tellg();
    else
    	return 0;
}

std::string File::readToString(const std::string &filename)
{
    std::ifstream file (filename.c_str(),
			std::ios::in |
			std::ios::binary |
			std::ios::ate);
    if (file.is_open())
    {
        size_t len = file.tellg();

	std::string s;
	s.resize(len);

	file.seekg (0, std::ios::beg);
	// FIXME What is the clean way to do this?
	file.read((char *)s.data(), len);
	file.close();

	return s;
    }
    else
    {
        // FIXME exception
        "";
    }
}

std::string File::getExtension(const std::string &filename)
{
    size_t p = filename.rfind('.');
    if (p == std::string::npos)
        return "";
    else
    	return filename.substr(p+1);
}
