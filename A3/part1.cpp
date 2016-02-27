#include "part1.h"

int vector_max (vector<int> &theList)
{
	int max = INT_MIN;
	for (unsigned int i=0; i < theList.size(); i++) {
		if (theList[i] > max) {
			max = theList[i];
		}
	}
	return max;
}

int vector_min (vector<int> &theList)
{
	int min = INT_MAX;
	for (unsigned int i=0; i < theList.size(); i++) {
		if (theList[i] < min) {
			min = theList[i];
		}
	}
	return min;
}

int vector_count_values (vector<int> &theList, int value)
{
	unsigned int count = 0;

	for (unsigned int i=0; i < theList.size(); i++) {
		if (theList[i] == value) {
			count++;
		}
	}
	return count;
}


int list_max (list<int> &theList)
{
	int max = INT_MIN;
	list<int>::iterator i = theList.begin();

	while (i != theList.end()) {
		if (*i > max) {
			max = *i;
		}
		i++;
	}
	return max;
}

int list_min (list<int> &theList)
{
	int min = INT_MAX;
	list<int>::iterator i = theList.begin();

	while (i != theList.end()) {
		if (*i < min) {
			min = *i;
		}
		i++;
	}
	return min;
}

int list_count_values (list<int> &theList, int value)
{
	unsigned int count = 0;
	list<int>::iterator i = theList.begin();

	while (i != theList.end()) {
		if (*i == value) {
			count++;
		}
		i++;
	}
	return count;
}



