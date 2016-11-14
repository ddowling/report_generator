/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : TextProperty
 *
 * Author      : Denis Dowling
 * Created     : 7/12/2009
 *
 * Description : class to implement helper functions to get various properties on text
 */
#ifndef TEXT_PROPERTY_H
#define TEXT_PROPERTY_H

#include <string>

namespace report_generator
{
    std::string red(const std::string &s);
    std::string green(const std::string &s);
    std::string blue(const std::string &s);
    std::string bold(const std::string &s);
}

#endif
