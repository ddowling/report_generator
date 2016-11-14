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
#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>

namespace report_generator
{
    // Some helper functions missing from std::string
    const std::string white_space = " \t\r\n";

    std::vector<std::string> split_string(const std::string &str,
                                          const std::string &sep = white_space);

    std::string trim_right(const std::string &source,
                           const std::string& t = white_space);

    std::string trim_left(const std::string& source,
                          const std::string& t = white_space);

    std::string trim(const std::string& source,
                     const std::string& t = white_space);

    void to_upper(std::string &str);
    std::string upper(const std::string &source);
    void to_lower(std::string &str);
    std::string lower(const std::string &source);

    // Repeat the supplied string n times
    std::string repeat(const std::string &str, int n);
}
#endif
