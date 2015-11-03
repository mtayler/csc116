#include "clock.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    std::cout << "-- Test 1" << std::endl;

    {
        // Curly braces define temporary scope.

        // Default constructed super_clock:
        super_clock c;

        for (int i = 0; i < 14; ++i)
        {
            std::cout << c.hour() << std::endl;
            c.advance_by_hours(1);
        }

        // Note that the super_clock destructor is
        // automatically called at end of scope.
    }

    std::cout << "-- Test 2" << std::endl;

    {
        // super_clock constructed with
        // an argument (starting hour):
        super_clock c(5);

        for (int i = 0; i < 14; ++i)
        {
            std::cout << c.hour() << std::endl;
            c.advance_by_hours(2);
        }
    }

    // TO DO: add tests for the new methods you added...
	
	std::cout << "-- Test 3" << std::endl;
	
	{
		super_clock c;

		for (int i=0; i < 14; i++) 
		{
			std::cout << c.hour() << ":" << std::setw(2) << std::setfill('0') <<
				c.minute() << std::endl;
			c.advance_by_minutes(15);
		}
	}
}
