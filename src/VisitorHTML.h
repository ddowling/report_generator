/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : VisitorHTML
 *
 * Author      : Denis Dowling
 * Created     : 8/5/2009
 *
 * Description : Render a report in HTML
 */
#ifndef VISITOR_HTML_H
#define VISITOR_HTML_H

#include "Report.h"
#include <sstream>

namespace report_generator
{

class VisitorHTML : public ReportVisitor
{
 public:
    VisitorHTML();

    std::string getHTML() const;

 protected:
    int sectionLevel;
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
