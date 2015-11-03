#include <iostream>
#include "bicycle.h"

int main(void) {
	
	std::cout << "-- Test contructor --" << std::endl;

	std::cout << std::endl;

	// Test default constructor
	{
		std::cout << "Testing default constructor..." << std::endl;
		bicycle b;
		
		std::cout << "Available gears: " << std::endl;
		std::cout << "\tFront: " << b.available_gears().front << std::endl;
		std::cout << "\tRear: " << b.available_gears().rear << std::endl;
		std::cout << "Current gear: " << std::endl;
		std::cout << "\tFront: " << b.gear().front << std::endl;
		std::cout << "\tRear: " << b.gear().rear << std::endl;
		std::cout << "Cadence: " << b.cadence() << std::endl;
		std::cout << "Speed: " << b.speed() << std::endl;

		std::cout << "Done testing default constructor." << std::endl;
	}

	std::cout << std::endl;

	// Test constructor with values & defaults
	{
		const int front = 5;
		const int rear = 10; 
		
		std::cout << "Testing constructor with parameters [5, 10]..." << std::endl;
		bicycle b(front, rear);

		std::cout << "Available gears: " << std::endl;
		std::cout << "\tFront: " << b.available_gears().front << std::endl;
		std::cout << "\tRear: " << b.available_gears().rear << std::endl;
		std::cout << "Current gear: " << std::endl;
		std::cout << "\tFront: " << b.gear().front << std::endl;
		std::cout << "\tRear: " << b.gear().rear << std::endl;
		std::cout << "Cadence: " << b.cadence() << std::endl;
		std::cout << "Speed: " << b.speed() << std::endl;

		std::cout << "Done testing with 2 parameters." << std::endl;
	}

	std::cout << std::endl;

	// Test cosntructor with all parameters
	{
		const int front = 5;
		const int rear = 9; 
		const int cur_front = 2;
		const int cur_rear = 4;
		const float cadence = 55.3;

		std::cout << "Testing constructor with parameters [3, 9, 2, 4, 55.3]..." << std::endl;
		bicycle b(front, rear, cur_front, cur_rear, cadence);

		std::cout << "Available gears: " << std::endl;
		std::cout << "\tFront: " << b.available_gears().front << std::endl;
		std::cout << "\tRear: " << b.available_gears().rear << std::endl;
		std::cout << "Current gear: " << std::endl;
		std::cout << "\tFront: " << b.gear().front << std::endl;
		std::cout << "\tRear: " << b.gear().rear << std::endl;
		std::cout << "Cadence: " << b.cadence() << std::endl;
		std::cout << "Speed: " << b.speed() << std::endl;

		std::cout << "Done testing with 4 parameters." << std::endl;

	}

	std::cout << std::endl;
	std::cout << "-- Testing methods --" << std::endl;

	// Test methods
	{
		bicycle b;

		std::cout << "Setting cadence to 40." << std::endl;
		b.set_cadence(40);
		std::cout << "\tCadence: " << b.cadence() << std::endl;

		std::cout << "Setting first gear to 3." << std::endl;
		b.change_front_gear(3);
		std::cout << "\tGears: " << b.gear().front << "," << b.gear().rear << std::endl;

		std::cout << "Attempting to set first gear out of bounds value 5." << std::endl;
		b.change_front_gear(5);
		std::cout << "\tGears: " << b.gear().front << "," << b.gear().rear << std::endl;
			
		std::cout << "Setting rear gear to 4." << std::endl;
		b.change_rear_gear(4);
		std::cout << "\tGears: " << b.gear().front << "," << b.gear().rear << std::endl;

		std::cout << "Attempting to set first gear to out of bounds value 12." << std::endl;
		b.change_rear_gear(12);
		std::cout << "\tGears: " << b.gear().front << "," << b.gear().rear << std::endl;

		std::cout << "Done testing methods." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-- Testing behaviour --" << std::endl;
	
	// Test behaviour
	{
		bicycle b;

		std::cout << "Going through gears, speed, at cadence 60..." << std::endl;
		b.set_cadence(60);
		for (int i=1; i <= 3; i++) {
			b.change_front_gear(i);
			for (int j=1; j <= 8; j += 2) {
				b.change_rear_gear(j);
				std::cout << "Gear: " << b.gear().front << "," << b.gear().rear << " Speed: " << b.speed() << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "Going through cadence, speed, at gear 2,5..." << std::endl;
		for (int i=0; i < 10; i++) {
			b.set_cadence(i*10);
			std::cout << "Cadence: " << b.cadence() << " Speed: " << b.speed() << std::endl;
		}

		std::cout << "Done testing behaviour." << std::endl;
	}

	
	return EXIT_SUCCESS;
}
