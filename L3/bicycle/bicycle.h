#ifndef BICYCLE_INCLUDED
#define BICYCLE_INCLUDED

#define ROTATIONS_TO_SPEED 0.05

struct Gear {
	int front;
	int rear;
};

class bicycle {

private:
	// -- State --
	// Crankshaft speed
	float m_cadence;

	// Available gears on the bike
	Gear gears;

	// Which gear the bike is currently in
	Gear current_gear;


public:
	// Default constructor
	bicycle();

	// Constructor with parameters
	bicycle(int front_gears, int rear_gears, int current_front_gear=1, int current_rear_gear=1, float cadence=0);


	// Destructor
	~bicycle();

	// -- Attributes --
	// Returns the front and rear gear currently engaged
	Gear gear();
	
	// Returns the number of front and rear gears available
	Gear available_gears();

	// Retuns the currently set cadence
	float cadence();

	// Returns speed as calculated by cadence and gear
	float speed();


	// -- Behaviours --
	
	// Select front gear to be engaged
	// If selected gear is not within the available gears no change occurs
	void change_front_gear(int gear);

	// Select rear gear to be engaged
	// If selected gear is not within the available gears no change occurs
	void change_rear_gear(int gear);

	// Set cadence
	void set_cadence(float cadence);

};
#endif // BICYCLE_INCLUDED
