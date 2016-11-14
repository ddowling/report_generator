/* $Id$
 *
 * Copyright   : (c) 2009 by Open Source Solutions Pty Ltd. All Rights Reserved
 * Project     : report_generator
 * File        : Table.h
 *
 * Author      : Denis Dowling
 * Created     : 7/12/2009
 *
 * Description : Helper functions to wrap blocks of text
 */
#include "WordWrap.h"
#include "String.h"

namespace report_generator
{

std::vector<std::string> wordWrap(const std::string &str, int max_width)
{
    std::vector<std::string> res;

    std::vector<std::string> lines = split_string(str, "\n");

    if (max_width < 0)
	return lines;

    int num_lines = lines.size();

    for(int i = 0; i < num_lines; i++)
    {
	std::string line;

        std::vector<std::string> words = split_string(lines[i], " \t");

	int num_words = words.size();
	for(int j = 0; j < num_words; j++)
	{
	    std::string word = words[j];
	    if ((int)line.size() + (int) word.size() < max_width)
	    {
		if (line.size() != 0)
		    line += " ";

		line += word;
	    }
	    else
	    {
		if (line.size() != 0)
		{
		    res.push_back(line);
		    line = "";
		}

		line = word;

		// Keep splitting the current line until it fits
		while ((int)line.size() > max_width)
		{
		    res.push_back(line.substr(0, max_width));

		    line = line.substr(max_width);
		}
	    }
	}
	if (line.size() > 0)
	    res.push_back(line);
    }

    return res;
}

// Perform the initial word wrap and then keep reducing the columns until
// the line count goes up. In this way we use first minimum lines and then
// the minimum columns for this number of lines
std::vector<std::string> wordWrapOptimum(const std::string &str, int max_width)
{
    std::vector<std::string> ww = wordWrap(str, max_width);
    int num_lines = ww.size();
    if (num_lines <= 1)
	return ww;

    int width = max_width - 1;
    while(width > 0)
    {
	ww = wordWrap(str, width);
	if ((int)ww.size() > num_lines)
	    break;

	width--;
    }

    width++;
    return wordWrap(str, width);
}

int lines(const std::vector<std::string> &sv)
{
    return sv.size();
}

int columns(const std::vector<std::string> &sv)
{
    size_t c = 0;
    for (size_t i = 0; i < sv.size(); i++)
    {
	if (sv[i].size() > c)
	    c = sv[i].size();
    }

    return c;
}

}
