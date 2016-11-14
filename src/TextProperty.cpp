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
#include "TextProperty.h"

namespace report_generator
{

std::string red(const std::string &s)
{
    return "<red>" + s + "</red>";
}

std::string green(const std::string &s)
{
    return "<green>" + s + "</green>";
}

std::string blue(const std::string &s)
{
    return "<blue>" + s + "</blue>";
}

std::string bold(const std::string &s)
{
    return "<b>" + s + "</b>";
}

}
