/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Section
 *
 * Author      : Denis Dowling
 * Created     : 7/12/2009
 *
 * Description : class to implement a report Section
 */
#ifndef SECTION_H
#define SECTION_H

#include "Report.h"

namespace report_generator
{

class Section : public ReportElement
{
 public:
    Section();

    // The section heading
    void setHeading(const std::string &h);
    std::string getHeading() const;

    Paragraph &addParagraph();

    virtual void traverse(ReportVisitor &report_visitor);

 protected:
    std::string heading;
};

}
#endif
