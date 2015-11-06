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

		/* Place your code here.  At this point:
		 * - the input file has been read, the contents have been placed in the lines array
		 * - the turtle structure t has been initialized 
		 */
		for (int i=0; i < linecount; i++)
		{
			string line, command;

			line = lines[i];

			command = line.substr(0,line.find(" "));

			if (command.compare("pen") == 0)
			{
				if (line.substr(line.find(" "), -1).compare(" down") == 0)
				{
					turtle_pen_down(&t);
				}
				else
				{
					turtle_pen_up(&t);
				}
			}
			else if (command.compare("forward") == 0)
			{
				turtle_move_forward(&t, getValue(line, line.find(" ")));
			}
			else if (command.compare("left") == 0)
			{
				turtle_rotate_left(&t, getValue(line, line.find(" ")));
			}
			else
			{
				turtle_rotate_right(&t, getValue(line, line.find(" ")));
			}
		}

		turtle_end(&t);

		svg_file_end(&t.file);

	}
	else
	{
		cout << "Invalid file." << endl;
	}
	return 0;
}
