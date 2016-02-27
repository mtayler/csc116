#include "list.h"

/* Leave this as is for debug output */
#define DBG(s) s
/* Change to below for no debug output
 * #define DBG(s)
*/

list::list()
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
	m_size = 0;
}

list::~list()
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
}


	/*
	 * Purpose:
	 *   Add an element to the end of the list.
	 *
 	 * Pre-conditions:
	 *   None.
	 *
	 * Post-conditions:
	 *   val is added to the end of the list
         *   m_size is increased by 1
	 *
	 * Examples:
	 *   if l is {1,2,3} and l.add(9) is called then
	 *   l is {1,2,3,9}
	 */
void list::add (int val)
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
}


int  list::get (unsigned int pos)
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
	return -1;
}


unsigned int list::size ()
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
	return 9999999;
}


std::ostream & operator<< (std::ostream& s, const list& l)
{
	DBG(cout << __PRETTY_FUNCTION__ << endl;)
	s << "hello world";

	return s;
}
