#ifndef __CSC116__TURTLE_H__
#define __CSC116__TURTLE_H__

#include "svg_file.h"

struct turtle {
	int x;
	int y;
	int angle;
	bool penDown;
	bool writeToFile;
	svg_file file;
};
/*
 * Purpose:
 * 
 * Initialize a turtle structure subsequent use.  This function must
 * be called before any other functions in this file are used.
 *
 * Pre-conditions:
 *
 * None.
 *
 * Post-conditions:
 *
 * Turtle structure t is initialized so that:
 *	t.x = 0
 *	t.y = 0
 *	t.angle = 0
 *	t.penDown = true
 *
 *	if filename == NULL :
 *		t.writeToFile = false
 *		t.svg_file is undefined
 *	else
 *		t.writeToFile = true
 *		t.svg_file is initilized with parameters height, width and filename
 *
 * Returns:
 *
 * true if all components of t are initialized
 * false otherwise
 *
 * Examples:
 *	turtle_init(&theTurtle, 500, 500, NULL);
 *	turtle_init(&foo, 1000,1000, "foo.svg");
 */
bool turtle_init ( turtle *t, int height, int width, const char *filename);

/*
 * Purpose:
 *
 * Clean up the turtle structure because it will no longer be used.
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 * t is now unusable for any further turtle functions
 * if t.writeToFile is true:
 *	svg_end has been called on t.file 
 * 
 */
void turtle_end (turtle *t);


/*
 * Purpose:
 *
 * Set the turtle pen to be up.  When the pen is up, calling turtle_move_forward 
 * will not draw a line. 
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true.  
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 *
 *	t.penDown = false
 */
void turtle_pen_up (turtle *t);

/*
 * Purpose:
 *
 * Set the turtle pen to be down.  When the pen is down, calling turtle_move_forward 
 * will draw a line. 
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true.  
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 *
 *	t.penDown = true
 */
void turtle_pen_down( turtle *t);

/*
 * Purpose:
 *
 * Rotate the direction of the turtle d degrees to the left (i.e., counterclockwise).
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true.  
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 *
 * t.angle is moved d degrees to the left.  t.angle >= 0 and t.angle < 360
 */
void turtle_rotate_left (turtle *t, int d);

/*
 * Purpose:
 *
 * Rotate the direction of the turtle d degrees to the right (i.e., clockwise).  
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true.  
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 *
 * t.angle is moved d degrees to the right.  t.angle >= 0 and t.angle < 360
 */
void turtle_rotate_right(turtle *t, int d);

/*
 * Purpose:
 *
 * Move the turtle foward dist units along the current heading.
 *
 * Pre-conditions:
 *
 * turtle_init has been called on t, and returned true.  
 * turtle_end has not been called on t.
 *
 * Post-conditions:
 *
 * The turtle is moved forward along the current heading.
 *
 * The new position is given by:
 *
 * dx = dist * cos (t.angle * (pi/180))
 * dy = dist * sin (t.angle * (pi/180))
 * t.x += dx
 * t.y += dy
 *
 * If t.writeToFile is true and t.penDown is true:
 *	invoke svg_draw_line to draw a line from the old (x,y) to 
 *	the new (x,y)
 *
 * NOTE:
 * The turtle class stores integer values for x and y, but the math functions in C++ require
 * double values.  You should perform all calculations shown above in using double values
 * and when you have the new x and y as doubles, you should round them to the nearest 
 * integer.  (NB: *round* them -- not cast them)
 */

void turtle_move_forward (turtle *t, int dist);

#endif

