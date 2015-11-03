#include <iostream>
#include "bicycle.h"

bicycle::bicycle() {
	gears.front = 3;
	gears.rear = 8;

	current_gear.front = 1;
	current_gear.rear = 1;

	m_cadence = 0;
}

bicycle::bicycle(int front_gears, int rear_gears, int current_front_gear, int current_rear_gear, float cadence) {
	gears.front = front_gears;
	gears.rear = rear_gears;

	current_gear.front = current_front_gear;
	current_gear.rear = current_rear_gear;

	m_cadence = cadence;
}

bicycle::~bicycle() {
	std::cout << "Destroying bicycle" << std::endl;
}

Gear bicycle::gear() {
	return current_gear;
}

Gear bicycle::available_gears() {
	return gears;
}

float bicycle::cadence() {
	return m_cadence;
}

float bicycle::speed() {
	return (current_gear.rear / (float)(gears.front / current_gear.front) )
		* m_cadence * ROTATIONS_TO_SPEED;
}

void bicycle::change_front_gear(int gear) {
	if (gear <= available_gears().front) {
		current_gear.front = gear;
	}
}

void bicycle::change_rear_gear(int gear) {
	if (gear <= available_gears().rear) {
		current_gear.rear = gear;
	}
}

void bicycle::set_cadence(float cadence) {
	m_cadence = cadence;
}
