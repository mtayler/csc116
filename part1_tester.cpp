#include <iostream>
#include "turtle.h"

int testcount = 0;

/*
struct turtle {
	int x;
	int y;
	int angle;
	bool penDown;
	bool writeToFile;
	svg_file file;
};
*/

void display_result (string file, int line, int testnumber)
{
	cout << "Test " << testnumber << " failed at line: " << line << " in file: " << file << endl;
}

bool test_init ()
{
	cout << "Testing turtle_init:" << endl;
	turtle t;
	
	/* 
 	 * This code one of the problems with using structures.  Even though
	 * we want all the modification of the turtle structure to happen through
	 * our functions, the compiler will not prevent someone from changing
	 * the contents directly. 
	 * This is helpful for my test program, but bad in general.
	 */
	t.x = 99;
	t.y = 99;
	t.angle = 99;
	t.penDown = false;
	t.writeToFile = true;
	
	if (!turtle_init(&t, 500,500, NULL))
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}		
	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	if (t.x != 0 || t.y != 0 || t.angle != 0 || !t.penDown || t.writeToFile)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;	

	turtle_end(&t);
	cout << endl;
	return true;
}

bool test_pen ()
{
	cout << "Testing turtle_pen_up and turtle_pen_down:" << endl;
	turtle t;
	
	/* 
 	 * This code one of the problems with using structures.  Even though
	 * we want all the modification of the turtle structure to happen through
	 * our functions, the compiler will not prevent someone from changing
	 * the contents directly. 
	 * This is helpful for my test program, but bad in general.
	 */
	t.x = 99;
	t.y = 99;
	t.angle = 99;
	t.penDown = false;
	t.writeToFile = true;
	
	turtle_init(&t, 500,500, NULL);
	
	turtle_pen_up(&t);
	if (t.penDown)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	turtle_pen_down(&t);

	if (!t.penDown)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;	

	turtle_end(&t);
	cout << endl;
	return true;

}

bool test_rotate()
{
	cout << "Testing turtle_rotate_left and turtle_rotate_right:" << endl;
	turtle t;
	
	turtle_init(&t, 500,500, NULL);

	turtle_rotate_left(&t, 90);

	if (t.angle != 90)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	turtle_rotate_right(&t, 90);

	if (t.angle != 0)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	for (int i = 1; i <= 16; i++)
	{
		turtle_rotate_left(&t,45);
		int expected = (i*45) % 360;

		if (t.angle != expected)
		{
			display_result (__FILE__, __LINE__, testcount);
			return false;
		}
	}
	cout << "Test " << testcount << " passed." << endl;
	testcount++;


	for (int i = 1; i <= 16; i++)
	{
		turtle_rotate_right(&t,45);
		int expected = (360 - ((i*45) % 360)) % 360;
		if (t.angle != expected)
		{
			display_result (__FILE__, __LINE__, testcount);
			return false;
		}
	}

	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	cout << endl;
	turtle_end(&t);

	return true;
}

bool test_forward_and_rounding()
{
	cout << "Testing turtle_move_forward and rounding: " << endl;
	turtle t;

	turtle_init(&t, 500, 500, "");
	for (int i = 0; i < 10; i++)
	{
		turtle_rotate_left (&t, 33);
		turtle_move_forward(&t,10);
	}

	if (t.x != -10 || t.y != -1)
	{
		display_result (__FILE__, __LINE__, testcount);
		return false;
	}

	cout << "Test " << testcount << " passed." << endl;
	testcount++;

	turtle_end(&t);
	cout << endl;	
	return true;
}

bool test_svg_output()
{
	cout << "Testing svg output.  You need to validate this test by hand." << endl;

	turtle t;

	turtle_init(&t, 500, 500, "part1.svg");

	turtle_pen_down(&t);

	for (int i = 0; i < 5; i++)
	{
		turtle_move_forward(&t, 50);
		turtle_rotate_right (&t, 144);
	}

	turtle_end(&t);
	return true;
}

int main ()
{
	if (test_init())
	{
		if (test_pen())
		{
			if (test_rotate())
			{
				if (test_forward_and_rounding())
				{
					test_svg_output();
					cout << "View the file part1.svg.  It should contain a star." << endl;
				}
			}
		}
	}
	cout << endl << testcount << " tests passed." << endl;
	return 0;

}
