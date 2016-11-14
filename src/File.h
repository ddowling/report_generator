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
#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

namespace report_generator
{

class File
{
 public:
    // Return the full path name of a file on the given path. If file cannot be
    // found then return the empty string
    static std::string findOnPath(const std::string &colon_path, const std::string &file);
    static std::string findOnPath(const std::vector<std::string> &path,
                                  const std::string &file);

    static size_t getSize(const std::string &filename);

    static std::string readToString(const std::string &filename);
    static std::string getExtension(const std::string &filename);
};

}
#endif
