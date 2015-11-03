#include <iostream>

using namespace std;

bool primality(long prime, long divisor = 2);

int main() {
	long prime, divisor, max;

	cout << "Enter upper limit of test: ";
	cin >> max;

	for (prime=0; prime < max; prime++) {
		if (primality(prime)) {
			cout << prime << endl;
		}
	}

	return 0;
}

bool primality(long prime, long divisor) {
	if (prime == 2) {		// know 2 is prime
		return true;
	}
	if (prime % divisor == 0 || divisor > prime) {
		return false;
	}
	else if (divisor == prime - 1) {
		return true;
	}
	else {
		return primality(prime, divisor+1);
	}
}
