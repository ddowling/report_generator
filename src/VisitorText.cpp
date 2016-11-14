/* $Id$
 *
 * Copyright   : (c) 2015 Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : VisitorText
 *
 * Author      : Denis Dowling
 * Created     : 8/5/2009
 *
 * Description : Render a report in Text
 */
#include "VisitorText.h"
#include "Section.h"
#include "Paragraph.h"
#include "Table.h"
#include "WordWrap.h"
#include "BoxDrawingCharacters.h"
#include "List.h"
#include "Image.h"
#include <boost/foreach.hpp>

using namespace report_generator;

VisitorText::VisitorText(bool use_colour)
    : sectionLevel(0), useColour(use_colour)
{
}

std::string VisitorText::getText() const
{
    return ss.str();
}

void VisitorText::enterReport(Report &r)
{
}

void VisitorText::exitReport(Report &r)
{
}

void VisitorText::enterSection(Section &s)
{
    sectionLevel++;

    ss << s.getHeading() << "\n";
    std::string rule = getLineStr(B_DOUBLE_HORIZONTAL,
                                  s.getHeading().size());
    ss << rule << "\n\n";
}

void VisitorText::exitSection(Section &s)
{
    sectionLevel--;
}

void VisitorText::enterParagraph(Paragraph &p)
{
    // FIXME Where does the width come from
    std::vector<std::string> sv = wordWrap(p.getText(), 80);
    BOOST_FOREACH(const std::string &s, sv)
	ss << s << "\n";
}

void VisitorText::exitParagraph(Paragraph &p)
{
    ss << "\n";
}

void VisitorText::enterTable(Table &t)
{
    ss << t.renderAsASCII(useColour);
}

void VisitorText::exitTable(Table &t)
{
    // Nothing to do
}

void VisitorText::enterList(List &l)
{
    ss << l.renderAsASCII();
}

void VisitorText::exitList(List &l)
{
    // Nothing to do
}

void VisitorText::visitImage(Image &i)
{
    ss << i.renderAsASCII();
}
