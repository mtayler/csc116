//
// part2.h
//

#ifndef CSC116_A2_PART2_H_
#define CSC116_A2_PART2_H_

#include <iostream>
#include <list>
#include <vector>
#include "vector_stack.h"

using namespace std;

/*
 * Traverses a string to check for properly matched brackets.
 * The function will return true if it contains
 * properly matched brackets and false otherwise.
 * Brackets considered are: {}, <>, () and []
 * 
 *
 * Pre-conditions:
 *	none
 *
 * Examples:  
 * 	if str is "()" returns true
 * 	if str is "{}<>()" returns true
 * 	if str is "({}(<{{}}>))" returns true
 * 	if str is "]" returns false	
 * 	if str is ""((])" returns false
 * 	if str is "(({()()}())" returns false	
 *
 */
bool match_brackets (char* str);

/*
 * Given a vector<int> holding the order in which the train cars are entering the station, 
 * this function decides whether it is possible to reorder the cars into
 * ascending order using only one spur.  
 * If it is possible the function will store the operations required to be performed
 * to reorder the cars in the list<string> provided by the caller and return true.
 * If it is NOT possible the function will leave the list<string> provided by the 
 * caller unchanged and return false.
 *
 * Pre-conditions:
 *	none
 *
 * Examples:
 * 	if v is {1,3,5,4,2} returns true and moves is {"in->spur","in->spur","in->out",
 * 	 	"spur->out","in->out","spur->out","in->out","in->spur","in->spur",
 * 		"in->spur","in->spur","in->out","spur->out","spur->out","spur->out","spur->out"}
 * 		
 *	if v is {4,3,5,1,2} returns false and moves is {} (cannot be done with only one spur)
 *
 * 	if v is {1,4,4,2,3} returns false and moves is {} (duplicate car number)
 */
bool railway (vector<int> v, list<string> &moves);

/*
 * Given a list<string> holding a set of switching operation instructions,
 * print the operations in order to cout.  
 * 
 * Pre-conditions:
 *	none
 *
 * Examples:
 * 	if ops is {"in->spur","in->out","spur->out"} the function will print:
 *		in->spur
 * 		in->out
 * 		spur->out
 *
 */
void print_switch_ops (list<string> &ops);

#endif

