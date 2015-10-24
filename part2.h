//
// part2.h
//
#ifndef CSC116_A3_PART2_H_
#define CSC116_A3_PART2_H_

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// In C++, you can have multiple functions of the same name
// provided that the number and type of arguments are different.

/*
 * Perform an in-place sort of the list l using the 
 * bubble sort algorithm.
 *
 * Pre-conditions:
 *	l.size() >= 1
 *
 * Examples:
 * if l is {2,1,4}, after bubble_sort(l), l is {1,2,4}
 * if l is {1}, after bubble_sort(l), l is {1}
 */
void bubble_sort (list<int> &l);

/*
 * Perform an in-place sort of the vector v using the 
 * bubble sort algorithm.
 *
 * Pre-conditions:
 *	v.size() >= 1
 *
 * Examples:
 * if v is {2,1,4}, after bubble_sort(v), v is {1,2,4}
 * if v is {1}, after bubble_sort(v), v is {1}
 */
void bubble_sort (vector<int> &v);

#endif

