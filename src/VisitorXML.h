/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : VisitorXML
 *
 * Author      : Denis Dowling
 * Created     : 13/12/2009
 *
 * Description : Render a report in XML. This output can then be converted
 *               to other formats using XSL
 */
#ifndef VISITOR_XML_H
#define VISITOR_XML_H

#include "Report.h"
#include <sstream>

namespace report_generator
{

class VisitorXML : public ReportVisitor
{
 public:
    VisitorXML();

    std::string getXML() const;

 protected:
    std::ostringstream ss;

    virtual void enterReport(Report &r);
    virtual void exitReport(Report &r);

    virtual void enterSection(Section &s);
    virtual void exitSection(Section &s);

    virtual void enterParagraph(Paragraph &p);
    virtual void exitParagraph(Paragraph &p);

    virtual void enterTable(Table &t);
    virtual void exitTable(Table &t);

    virtual void enterList(List &t);
    virtual void exitList(List &t);

    virtual void visitImage(Image &i);
};

}
#endif
