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
#include "Paragraph.h"
#include "Table.h"
#include "List.h"
#include "Image.h"

using namespace report_generator;

Paragraph::Paragraph()
{
}

// The paragraph test
void Paragraph::setText(const std::string &t)
{
    text = t;
}

std::string Paragraph::getText() const
{
    return text;
}

Table & Paragraph::addTable()
{
    Table *t = new Table;

    ReportElement::ReportElementPtr tp(t);
    appendChild(tp);

    return *t;
}

List & Paragraph::addList()
{
    List *l = new List;

    ReportElement::ReportElementPtr lp(l);
    appendChild(lp);

    return *l;
}

Image & Paragraph::addImage()
{
    Image *i = new Image;

    ReportElement::ReportElementPtr ip(i);
    appendChild(ip);

    return *i;
}

void Paragraph::traverse(ReportVisitor &report_visitor)
{
    report_visitor.enterParagraph(*this);

    ReportElement::traverse(report_visitor);

    report_visitor.exitParagraph(*this);
}
