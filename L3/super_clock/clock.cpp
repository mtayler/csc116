#include "clock.hpp"

// Implementation of method 'advance_by_hours' in class 'super_clock':
// When current hour reaches 12 or more, it is wrapped to 0.
void super_clock::advance_by_hours( int hours )
{
    current_hour = (current_hour + hours) % 12;
}


// Add a method to advance by a number of minutes
// When current minute reaches 60 or more, it is wrapped to 0,
// and an hour is added.
void super_clock::advance_by_minutes( int minutes ) 
{
	int new_time = ( current_minute + minutes ) % 60;
	if (new_time < current_minute + minutes) {
		advance_by_hours(1);
	}
	current_minute = new_time;
}

void super_clock::advance( int hours, int minutes ) {
	advance_by_minutes( minutes );
	advance_by_hours( hours );
}

// Add a method to advance by
// a number of hours and a number of minutes.
// Implement by calling the methods that advance time
// individually by hours and by minutes.
