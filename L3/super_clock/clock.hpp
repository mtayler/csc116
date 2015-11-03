
#ifndef SUPER_CLOCK_INCLUDED
#define SUPER_CLOCK_INCLUDED

#include <iostream>

/*
  Class super_clock:

  Attributes:
  - current time
  - current hour
  - current minute

  Behaviors:
  - advance by a number of hours
  - advance by a number of minutes
  - advance by a number of hours and minutes
*/

class super_clock
{

private:
    // -- State --
    // Represented by data fields (member variables):

    int current_hour;
	int current_minute;

public:
    // Default constructor (no parameters)

    super_clock()
    {
        current_hour = 0;
        std::cout << "Clock default-constructed." << std::endl;
    }

    // Constructor with a parameter

    super_clock( int hour )
    {
        current_hour = hour % 12;
        std::cout << "Clock constructed." << std::endl;
    }

    // Destructor

    ~super_clock()
    {
        std::cout << "Clock destroyed." << std::endl;
    }


    // -- Attributes --
    // Represented by methods (member functions)
    // that return information about the state:

    int hour() {
        return current_hour;
    }

	int minute() {
		return current_minute;
	}


    // -- Behaviors --
    // Represented by methods (member functions)
    // that modify the state:

    // Method 'advance_by_hours': Advance time by a number of hours.
    // When current hour reaches 12 or more, it is wrapped to 0.
    // (The method is only declared here, but defined in the file clock.cpp.)
    void advance_by_hours( int hours );

    // Add a method to advance time by a number of minutes.
    // When current minute reaches 60 or more, it is wrapped to 0,
    // and an hour is added.
	void advance_by_minutes( int minutes );

    // Add a method to advance time by
    // a number of hours and a number of minutes.
    // Implement by calling the methods that advance time
    // individually by hours and by minutes.
	void advance( int hours, int minutes );
};

#endif // SUPER_CLOCK_INCLUDED

