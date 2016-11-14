/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : List
 *
 * Author      : Denis Dowling
 * Created     : 14/12/2009
 *
 * Description : A List that can be rendered into a number of different formats
 */
#include "List.h"
#include <sstream>

using namespace report_generator;

List::List()
    : orderedList(false), definitionList(false)
{
}

void List::setOrderedList(bool b)
{
    orderedList = b;
}

bool List::getOrderedList()
{
    return orderedList;
}

void List::setDefinitionList(bool b)
{
    definitionList = b;
}

bool List::getDefinitionList()
{
    return definitionList;
}

// Add an item to the list
void List::addItem(std::string text)
{
    ListItem li;
    li.text = text;

    listItems.push_back(li);
}

void List::addItem(std::string definition, std::string text)
{
    ListItem li;
    li.definition = definition;
    li.text = text;

    listItems.push_back(li);
}

void List::traverse(ReportVisitor &report_visitor)
{
    report_visitor.enterList(*this);

    ReportElement::traverse(report_visitor);

    report_visitor.exitList(*this);
}

std::string List::renderAsASCII()
{
    std::ostringstream ss;
    ListItemVector::iterator iter;
    int n = 0;

    // FIXME wordwrap and indent in this function

    for(iter = listItems.begin(); iter != listItems.end(); ++iter)
    {
	ListItem &li = *iter;
	if (orderedList)
	{
	    n++;
	    ss << n << ". " << li.text << "\n";
	}
	else if (definitionList)
	{
	    ss << "  " << li.definition << "\n";
	    ss << "    " << li.text << "\n";
	}
	else
	    ss << "- " << li.text << "\n";
    }

    return ss.str();
}

std::string List::renderAsHTML()
{
    std::string lt;
    if (orderedList)
	lt = "ol";
    else if (definitionList)
	lt = "dl";
    else
	lt = "ul";

    std::ostringstream ss;

    ss << "<" << lt << ">\n";

    ListItemVector::iterator iter;

    for(iter = listItems.begin(); iter != listItems.end(); ++iter)
    {
	ListItem &li = *iter;
	if (definitionList)
	    ss << "<dt>" << li.text << "</dt>\n";
	else
	    ss << "<dd>" << li.text << "</dd>\n";
    }

    ss << "</" << lt << ">\n";

    return ss.str();
}

std::string List::renderAsXML()
{
    return renderAsHTML();
}
