/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : String
 *
 * Author      : Denis Dowling
 * Created     : 6/5/2009
 *
 * Description : String helper functions
 */
#include "String.h"
#include <algorithm>

namespace report_generator
{

std::vector<std::string> split_string(const std::string &str,
                                      const std::string &sep)
{
    std::vector<std::string> ret;

    size_t p = 0;
    while(true)
    {
        size_t i = str.find_first_of(sep, p);
	if (i == std::string::npos)
	    break;

	std::string token = str.substr(p, i - p);
	ret.push_back(token);
	p = i + 1;
    }

    if (p < str.size())
    {
	std::string token = str.substr(p);
	ret.push_back(token);
    }

    return ret;
}

std::string trim_right(const std::string &source , const std::string& t)
{
    std::string str = source;
    return str.erase( str.find_last_not_of(t) + 1);
}

std::string trim_left( const std::string& source, const std::string& t)
{
    std::string str = source;
    return str.erase(0 , source.find_first_not_of(t) );
}

std::string trim(const std::string& source, const std::string& t)
{
    std::string str = source;
    return trim_left( trim_right( str , t) , t );
}

void to_upper(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), toupper);
}

std::string upper(const std::string &source)
{
    std::string str = source;
    to_upper(str);
    return str;
}

void to_lower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), tolower);
}

std::string lower(const std::string &source)
{
    std::string str = source;
    to_lower(str);
    return str;
}

// Repeat the supplied string n times
std::string repeat(const std::string &str, int n)
{
    std::string ret;

    for(int i = 0; i < n; i++)
	ret += str;

    return ret;
}

}
