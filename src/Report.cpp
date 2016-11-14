/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Report
 *
 * Author      : Denis Dowling
 * Created     : 8 May 2009
 *
 * Description : classes to implement the Report Composite pattern
 */
#include "Report.h"
#include "Section.h"
#include <stdexcept>

using namespace report_generator;

// ********
// Visitor pattern for the Report class. It will be called when we traverse
// the Report composite pattern
ReportVisitor::~ReportVisitor()
{
}

void ReportVisitor::enterReport(Report &r)
{
}

void ReportVisitor::exitReport(Report &r)
{
}

void ReportVisitor::enterSection(Section &s)
{
}

void ReportVisitor::exitSection(Section &s)
{
}

void ReportVisitor::enterParagraph(Paragraph &p)
{
}

void ReportVisitor::exitParagraph(Paragraph &p)
{
}

void ReportVisitor::enterTable(Table &t)
{
}

void ReportVisitor::exitTable(Table &t)
{
}

// ********
// Base class for elements of a report
ReportElement::ReportElement()
    : parent(0)
{
}

ReportElement::~ReportElement()
{
}

void ReportElement::appendChild(ReportElementPtr child)
{
    if (child->parent != 0)
        throw std::invalid_argument("Already added");

    child->parent = this;
    children.push_back(child);
}

void ReportElement::traverse(ReportVisitor &report_visitor)
{
    ReportElementVector::iterator iter;

    for(iter = children.begin(); iter != children.end(); ++iter)
    {
	ReportElementPtr p = *iter;

	p->traverse(report_visitor);
    }
}


// ********
Report::Report()
{
}

// The title of the report
void Report::setTitle(const std::string &title_)
{
    title = title_;
}

std::string Report::getTitle() const
{
    return title;
}

// The author of the report
void Report::setAuthor(const std::string &author_)
{
    author = author_;
}

std::string Report::getAuthor() const
{
    return author;
}

Section & Report::addSection()
{
    Section *s = new Section;

    ReportElement::ReportElementPtr sp(s);
    appendChild(sp);

    return *s;
}

void Report::traverse(ReportVisitor &report_visitor)
{
    report_visitor.enterReport(*this);

    ReportElement::traverse(report_visitor);

    report_visitor.exitReport(*this);
}

