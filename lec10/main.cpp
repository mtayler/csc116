#include "list.h"

int main ()
{
	list l;

	l.add(10);
	l.add(11);

	cout << "l.size() is: " << l.size() << endl;
	cout << "l.get(0) is: " << l.get(0) << endl;

	cout << l << endl;

	return 0;
}
