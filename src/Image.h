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
#ifndef IMAGE_H
#define IMAGE_H

#include "Report.h"

namespace report_generator
{

class Image : public ReportElement
{
 public:
    Image();

    void setImage(const std::string &file);

    void setAlternateText(const std::string &text);

    virtual void traverse(ReportVisitor &report_visitor);

    std::string renderAsASCII();
    std::string renderAsHTML();
    std::string renderAsXML();

 protected:
    std::string file;
    std::string text;
};

}
#endif
