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
#ifndef WORD_WRAP_H
#define WORD_WRAP_H

#include <string>
#include <vector>

std::vector<std::string> wordWrap(const std::string &str,
                                  int max_width);

// Perform the initial word wrap and then keep reducing the columns until
// the line count goes up. In this way we use first minimum lines and then
// the minimum columns for this number of lines
std::vector<std::string> wordWrapOptimum(const std::string &str,
                                         int max_width);

int lines(const std::vector<std::string> &sv);
int columns(const std::vector<std::string> &sv);

#endif
