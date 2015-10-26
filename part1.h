#ifndef CSC116_A3_PART1_H_
#define CSC116_A3_PART1_H_

#include <list>
#include <vector>

using namespace std;

/*
 * return the maximum value in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 *
 * Returns:
 *	the maximum value in the list
 */
int vector_max (vector<int> &theList);

/*
 * return the minimum value in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 *
 * Returns:
 *	the minimum value in the list
 */
int vector_min (vector<int> &theList);

/*
 * return the number of times value occurs in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 */
int vector_count_values (vector<int> &theList, int value);


/*
 * return the maximum value in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 *
 * Returns:
 *	the maximum value in the list
 */
int list_max (list<int> &theList);

/*
 * return the minimum value in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 *
 * Returns:
 *	the minimum value in the list
 */
int list_min (list<int> &theList);

/*
 * return the number of times value occurs in theList
 *
 * Pre-conditions:
 *
 * 	theList.size() >= 1
 */
int list_count_values (list<int> &theList, int value);


#endif

