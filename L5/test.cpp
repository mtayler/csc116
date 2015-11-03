#include <iostream>
#include "measurement_list.hpp"

using namespace std;

int main(void) {
	measurement *meas;

	cout << "===== Testing measurement class =====" << endl;
	cout << "Testing constructor/deconstructor: ";
	{
		meas = new measurement;

		if (meas->time != 0 || meas->value != 0) {
			cout << "TEST FAILED: Default value constructor" << endl;
			return 1;
		}

		delete meas;
	}
	{
		const float time = 4;
		const float value = 8;

		meas = new measurement(time, value);

		if (meas->time != time || meas->value != value) {
			cout << "TEST FALIED: Provided value constructor" << endl;
		}

		delete meas;
	}

	cout << "TEST SUCCESS" << endl;

	cout << "Testing measument prfloating: ";
	{
		const float time = 5;
		const float value = 10;

		measurement meas(time, value);

		cout << endl << "\tExpected value:\t5: 10" << endl;
		cout << "\tActual value:\t" << meas << endl;
	}

	cout << "===== Testing measurement complete =====" << endl << endl;

	cout << "===== Testing measurement_list class =====" << endl;
	cout << "Testing constructor/destructor and size: ";
	{
		measurement_list measlist;
		if (measlist.size() != 0) {
			cout << "TEST FAILED: Constructor" << endl;
		}
	}
	cout << "TEST SUCCESS" << endl;

	cout << "Testing insert: ";
	{
		measurement_list measlist;
		measlist.insert(measurement(0, 5));

		cout << endl << "\tExpected value:\t{0: 5}" << endl;
		cout << "\tActual value:\t" << measlist << endl;

		measlist.insert(measurement(4, 10));
		cout << endl << "\tExpected value:\t{0: 5, 4: 10}" << endl;
		cout << "\tActual value:\t" << measlist << endl;

		measlist.insert(measurement(0, 2));
		cout << endl << "\tExpected value:\t{0: 5, 0: 2, 4: 10}" << endl;
		cout << "\tActual value:\t" << measlist << endl;
	}
	return 0;
}
