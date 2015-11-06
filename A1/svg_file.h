#ifndef __CSC116__SVG_FILE_H__
#define __CSC116__SVG_FILE_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct svg_file {
	int 		height;
	int 		width;
	ofstream	file;
	string 		name;
};

/*
 * Purpose:
 * 
 * Initialize a svg_file structure subsequent use.  This function must
 * be called before any other functions in this file are used.
 *
 * Pre-conditions:
 * 
 * None.
 *
 * Post-conditions:
 *
 * If svg_file_init returns true:
 * 	a file has been created whos name is the parameter name
 *      an appropriate SVG header has been written to the file
 *
 * Returns:
 *
 * true if all components of f are initialized
 * false otherwise
 *
 * Examples:
 *	svg_file_init(&theFile, 500, 500, "bar.svg");
 */
bool svg_file_init ( svg_file *f, int height, int width, const char * name);

/*
 * Purpose:
 *
 * Cause an SVG line directive to be written to the current svg file 
 *
 * Pre-conditions:
 *
 * svg_file_init has been called on f and returned true.
 * svg_file_end has not been called on f.
 *
 * Post-conditions:
 *
 * The following SVG directive will have been written to the file:
 * 
 * <line x1="x1" y1="y1" x2="x2" y2="y2" style="stroke:rgb(0,0,0);stroke-width:2" />
 * 
 * Where x1, y1, x2, y2 in quotation marks are replaced with the values of
 * the parameters of the same name.
 * 
 * Examples:
 *
 * svg_file_line (&theSVGFile, 0, 0, 100, 100) would write to the file:
 *
 * <line x1="0" y1="0" x2="100" y2="100" style="stroke:rgb(0,0,0);stroke-width:2" />
 */
void svg_file_line ( svg_file *f, int x0, int y0, int x1, int y1);


/*
 * Purpose:
 *
 * Clean up the svg_file structure because it will no longer be used.
 *
 * Pre-conditions:
 *
 * svg_file_init has been called on f and returned true.
 * svg_file_end has not been called on f.
 *
 * Post-conditions:
 * f is now unusable for any further svg_file functions
 * an appropriate SVG footer has been written to the file
 * the SVG file has been closed.
 *
 */
void svg_file_end  ( svg_file *f);

#endif

