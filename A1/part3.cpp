/*
 * part2.cpp
 *
 * Complete this file so that the program uses your implementation of
 * turtle graphics to create the diagram specified by the 
 * input file.
 *
 * See the assignment PDF for input file specifications.
 * A reminder that you may assume that the input files are 
 * valid and that they do not exceed 5000 lines.
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "turtle.h"

using namespace std;

/* We will only handle input files up to 5000 lines long */
const int MAXLINES = 5000;

/* This is the total number of lines in the file */
int	linecount = 0;

/* Each line of the file is placed in this array
 * The first line of the file is in lines[0]
 * The second line of the file is in lines[1]
 * ...
 * The last line of the file is in lines[linecount-1]
 */
string	lines[MAXLINES];

/*
 * This function reads the input file into the lines array
 */
bool read_file (string filename)
{
	ifstream f;

	f.open(filename.c_str());
	if (!f.is_open())
	{
		cout << "Can't open: " << filename << endl;
		return false;
	}
	linecount = 0;

	while (linecount < MAXLINES )
	{
		getline(f,lines[linecount]);
		if (f.eof())
			break;

		linecount++;
	}
	return true;
}

int getValue (string s, int pos)
{
	return atoi(s.substr(pos).c_str());
}

void execute(turtle *t, string line)
{
	string command;

	command = line.substr(0,line.find(" "));

	if (command.compare("pen") == 0)
	{
		if (line.substr(line.find(" "), -1).compare(" down") == 0)
		{
			turtle_pen_down(t);
		}
		else
		{
			turtle_pen_up(t);
		}
	}
	else if (command.compare("forward") == 0)
	{
		turtle_move_forward(t, getValue(line, line.find(" ")));
	}
	else if (command.compare("left") == 0)
	{
		turtle_rotate_left(t, getValue(line, line.find(" ")));
	}
	else if (command.compare("right") == 0)
	{
		turtle_rotate_right(t, getValue(line, line.find(" ")));
	}
}

/*
 * Essentially a wrapper to handle repeats. Once called with the original data, the function will
 * recursively call itself to handle repeats.
 */
void parse_lines(turtle *t, string lines[], short start, short end)
{
	bool capture=0;   	// becomes true if repeat is encountered and lines need to be remembered
	uint8_t reps;		// number of times to repeat code
	short scope=0;		// method of tracking which braces belong together
	short next_start;
	string line;
	//string* rep_lines = new string[MAXLINES];	// storage for lines to be repeated
	short num_rep_lines;						// tracks number of lines stored

	for (short i=start; i < end; i++)
	{
		line = lines[i];

		if (line.substr(0, line.find(" ")).compare("repeat") == 0)
		{
			if (scope < 1)
			{
				reps = getValue(line, line.find(" "));
				num_rep_lines = 0;
				capture = true;
				continue;		// current command dealt with, and doesn't need to be captured: thus jump to next line
			}
		}

		if (capture)
		{
			if (line.compare("{") == 0)		// on opening curly brace, scope goes down 1 level
			{
				scope++;

				if (scope <= 1) {
					next_start = i+1;		// don't read curly brace, part of current lines
				}
				else if (scope > 1)
				{
					//rep_lines[num_rep_lines] = line;
					num_rep_lines++;
				}
			}
			else if (line.compare("}") == 0)	// on closing brace, scope goes up 1 level
			{
				scope--;

				if (scope < 1)			// if scope < 1, done capturing. Move to parsing captured lines
				{
					capture = false;
					for (char r=0; r < reps; r++)
					{
						parse_lines(t, lines, next_start, next_start+num_rep_lines);
					}
					//delete rep_lines;
				}
				else
				{
					//rep_lines[num_rep_lines] = line;
					num_rep_lines++;
				}
			}
			else
			{	
				//rep_lines[num_rep_lines] = line;
				num_rep_lines++;
			}
		}
		else if (!capture) 		// if not capturing, just run
		{
			execute(t, line);
		}
	}
}

int main (int argc, char **argv)
{
	string filename;

	if (argc != 2)
	{
		filename = "ex1.txt";
	}
	else
	{
		filename = argv[1];
	}

	if (read_file(filename))
	{
		/*
		 * For the purposes of this assignment, the width and heigh of the
		 * canvas will be 500.
		 */
		turtle t;
		turtle_init (&t, 500, 500, (filename + ".svg").c_str());

		/* essentially a wrapper to deal with repeats. Recursively calls in the event of a repeat, otherwise passes
		 * current line to `execute` to execute given command */
		parse_lines(&t, lines, 0, linecount);

		turtle_end(&t);

		svg_file_end(&t.file);

	}
	else
	{
		cout << "Invalid file." << endl;
	}
	return 0;
}
