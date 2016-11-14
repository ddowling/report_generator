/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Image
 *
 * Author      : Denis Dowling
 * Created     : 14/12/2009
 *
 * Description : A Image that can be rendered into a number of different formats
 */
#include "Image.h"
#include "Base64.h"
#include "File.h"

Image::Image()
{
}

void Image::setImage(const std::string &file_)
{
    file = file_;
}

void Image::setAlternateText(const std::string &text_)
{
    text = text_;
}

void Image::traverse(ReportVisitor &report_visitor)
{
    report_visitor.visitImage(*this);
}

std::string Image::renderAsASCII()
{
    return text;
}

std::string Image::renderAsHTML()
{
    bool include_in_html = true;

    std::string s = "<IMG SRC=";

    if (include_in_html)
    {
	std::string s = File::readToString(file);
	std::string image_type = File::getExtension(file);

	std::string b64 = Base64::encode(s);

	s += "\"data:image/" + image_type + ";base64," + b64 + "\"";
    }
    else
	s += "\"" + file + "\"";

    if (text.size() != 0)
	s += " ALT=\"" + text + "\"";
    s += ">";

    return s;
}

std::string Image::renderAsXML()
{
    return renderAsHTML();
}
