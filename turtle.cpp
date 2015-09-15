#include <iostream>
#include <sstream>
#include <cmath>
#include "turtle.h"

using namespace std;

bool turtle_init ( turtle *t, int height, int width, const char *filename )
{
	try
	{
		t->x = 0;
		t->y = 0;
		t->angle = 0;
		t->penDown = true;

		if (filename == NULL)
		{
			t->writeToFile = false;
		}
		else
		{
			t->writeToFile = true;
			svg_file_init(&t->file, height, width, filename);
		}

		return true;
	}
	catch(...)
	{
		return false;
	}
}

void turtle_end ( turtle *t )
{
	if (t->writeToFile == true)
	{
		svg_file_end(&t->file);
	}

	t = new turtle;
	delete t;
	t = nullptr;
}

void turtle_pen_up (turtle *t)
{
	t->penDown = false;
}

void turtle_pen_down( turtle *t)
{
	t->penDown = true;
}

void turtle_rotate_left (turtle *t, int degrees)
{
	t->angle = (t->angle + degrees) % 360;
}

void turtle_rotate_right(turtle *t, int degrees)
{
	t->angle = (t->angle - degrees);

	if (t->angle < 0)
	{
		t->angle = (360 + t->angle);
	}

	t->angle = t->angle % 360;
}

void turtle_move_forward (turtle *t, int dist)
{
	double dx, dy;
	int x0, y0;

	x0 = t->x;
	y0 = t->y;

	dx = dist * cos(t->angle * (M_PI/180));
	dy = dist * sin(t->angle * (M_PI/180));
	t->x += round(dx);
	t->y += round(dy);

	if (t->writeToFile == true && t->penDown == true)
	{
		svg_file_line(&t->file, x0, y0, t->x, t->y);
	}
}
