/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Colour.h
 *
 * Author      : Denis Dowling
 * Created     : 9/12/2009
 *
 * Description : Colour definitions
 */
#ifndef COLOUR_H
#define COLOUR_H

#include <string>

namespace report_generator
{

enum Colour
{
    COL_DEFAULT,
    COL_RED,
    COL_GREEN,
    COL_BLUE,
    COL_YELLOW
};

// Control if ANSI colour support is to be enabled
void setANSIColour(bool s);

std::string setTextColour(Colour c, const std::string &str);
std::string setHTMLColour(Colour c, const std::string &str);

}
#endif
