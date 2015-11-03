#include <iostream>
#include <cfloat>

using namespace std;

int main() {
	float start, ratio;

    cout << "Enter start and ratio values: ";
    cin >> start >> ratio;

    float x = start;
    int i = 0;
    while(x < FLT_MAX)
    {
        cout << x << endl;
        x = x * ratio;
        i++;
    }
	return 0;
}

