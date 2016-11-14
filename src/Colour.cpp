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
#include "Colour.h"

static bool ansiColour = false;

// Control if ANSI colour support is to be enabled
void setANSIColour(bool s)
{
    ansiColour = s;
}

std::string setTextColour(Colour c, const std::string &str)
{
    if (!ansiColour)
        return str;

    // ANSI Escape sequences
    const char *c_reset = "[0m";
    const char *c_red = "[31m";
    const char *c_green = "[32m";
    const char *c_yellow = "[33m"; // Actually shows up brown in VGA pallet
    const char *c_blue = "[34m";

    std::string ret;
    switch(c)
    {
    case COL_RED:
	ret = c_red;
	break;
    case COL_GREEN:
	ret = c_green;
	break;
    case COL_BLUE:
	ret = c_blue;
	break;
    case COL_YELLOW:
	ret = c_yellow;
	break;
    default:
	return str;
    }

    ret += str + c_reset;

    return ret;
}

std::string setHTMLColour(Colour c, const std::string &str)
{
    const char *colour_code;
    switch(c)
    {
    case COL_RED:
	colour_code = "#FF0000";
	break;
    case COL_GREEN:
	colour_code = "#00FF00";
	break;
    case COL_BLUE:
	colour_code = "#0000FF";
	break;
    case COL_YELLOW:
	colour_code = "#FFFF00";
	break;
    default:
	return str;
    }

    std::string ret = std::string("<font color=\"") + colour_code + "\">";
    ret += str;
    ret += "</font>";

    return ret;
}
