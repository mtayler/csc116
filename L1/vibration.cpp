#include <iostream>
#include <iomanip>

using namespace std;

double acceleration(double force, double mass)
{
    return force / mass;
}

double acceleration_spring(double k, double* position)
{
	return -k*(*position);
}

void update(double * velocity, double * position, double duration, 
            double k, double mass)
{
    double a = acceleration_spring(k, position);
    *velocity = *velocity + a * duration;
    *position = *position + *velocity * duration;
}


int main(int argc, const char * argv[])
{
    double k = 0.3, mass = 1.0;
    double velocity = 0.0, position = 10.0;

    int i = 0;
    while (i < 100)
    {
        update(&velocity, &position, 0.5, k, mass);

        cout << "position: " << left << setw(12) << position
            << "velocity: " << velocity << endl;

        i++;
    }

    return 0;
}
