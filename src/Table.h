/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Table.h
 *
 * Author      : Denis Dowling
 * Created     : 6/5/2009
 *
 * Description : A Table that can be rendered into a number of different formats
 */
#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Report.h"
#include "Colour.h"

namespace report_generator
{

class Table : public ReportElement
{
 public:
    Table();

    // Add a caption to the table
    void addCaption(const std::string &caption);

    // Add a heading row to a table
    void addHeadingRow();

    // Add a new row to a table
    void addRow();

    void addCell(const std::string &contents);

    void setCellColour(Colour c);

    virtual void traverse(ReportVisitor &report_visitor);

    std::string renderAsASCII(bool use_colour);
    std::string renderAsHTML();
    std::string renderAsXML();

 protected:
    std::string caption;
    std::string tableClass;

    struct Cell
    {
	std::string contents;
	Colour colour;
        std::vector<std::string> wrappedContents;
    };
    typedef std::vector<Cell> CellVector;

    struct Row
    {
	bool isHeading;
	CellVector cells;
	int height;
    };
    typedef std::vector<Row> RowVector;

    RowVector rows;

    typedef std::vector<int> IntVector;
    IntVector colWidths;

    std::string addHRule(const Row &r, bool top, bool bottom);
    void determineColumnWidths();
    void determineRowHeights();
    void wrapCells();

    std::string fmtHTMLCell(const Cell &c);
};

}
#endif
