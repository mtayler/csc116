//
// part1_tester.cpp
//
// This program uses exceptions to handle error conditions.  We haven't
// covered them yet in class.  
//
#include <iostream>
#include <string>
#include <sstream>
#include "part1.h"

using namespace std;

class part1_tester_exception
{
	public:
		part1_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s;
			s << _line;

			return _msg + " line number: " + s.str(); 
		}
	private:
		part1_tester_exception();
		string _msg;
		unsigned int _line;
};

void test_vector()
{
	int ar1[] = {1,2,3,4};		// C++11 makes this easier
	vector<int> v1(ar1, ar1 + sizeof(ar1) / sizeof(int));

	if (vector_max(v1) != 4)
		throw part1_tester_exception(__func__,__LINE__);

	if (vector_min(v1) != 1)
		throw part1_tester_exception(__func__,__LINE__);

	if (vector_count_values(v1,2) != 1)
		throw part1_tester_exception(__func__,__LINE__);


	int ar2[] = {10,10,-3,11,2,10,50};
	vector<int> v2(ar2, ar2+ sizeof(ar2) / sizeof(int));

	if (vector_max(v2) != 50)
		throw part1_tester_exception(__func__,__LINE__);

	if (vector_min(v2) != -3)
		throw part1_tester_exception(__func__,__LINE__);

	if (vector_count_values(v2,10) != 3)
		throw part1_tester_exception(__func__,__LINE__);


	cout << __func__ << " passed." << endl;
}

void test_list()
{
	int ar1[] = {1,2,3,4};		// C++11 makes this easier
	list<int> l1(ar1, ar1 + sizeof(ar1) / sizeof(int));

	if (list_max(l1) != 4)
		throw part1_tester_exception(__func__,__LINE__);

	if (list_min(l1) != 1)
		throw part1_tester_exception(__func__,__LINE__);

	if (list_count_values(l1,2) != 1)
		throw part1_tester_exception(__func__,__LINE__);


	int ar2[] = {10,10,-3,11,2,10,50};
	list<int> l2(ar2, ar2+ sizeof(ar2) / sizeof(int));

	if (list_max(l2) != 50)
		throw part1_tester_exception(__func__,__LINE__);

	if (list_min(l2) != -3)
		throw part1_tester_exception(__func__,__LINE__);

	if (list_count_values(l2,10) != 3)
		throw part1_tester_exception(__func__,__LINE__);


	cout << __func__ << " passed." << endl;


}

int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_vector();
		tests_passed++;

		test_list();
		tests_passed++;
		
	}
	catch (part1_tester_exception const &e)
	{
		cout << "Failed test case: " << e.what() << std::endl;
	}
	catch (...)
	{
		cout << "Caught unhandled exception." << std::endl;
	}
	cout << "Passed: " << tests_passed << endl;

	return tests_passed;
}

