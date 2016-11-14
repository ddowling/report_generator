/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Paragraph
 *
 * Author      : Denis Dowling
 * Created     : 7/12/2009
 *
 * Description : class to implement a report Paragraph
 */
#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "Report.h"

namespace report_generator
{

class Paragraph : public ReportElement
{
 public:
    Paragraph();

    // The paragraph text
    void setText(const std::string &h);
    std::string getText() const;

    Table &addTable();
    List &addList();
    Image &addImage();

    virtual void traverse(ReportVisitor &report_visitor);

 protected:
    std::string text;
};

}
#endif
