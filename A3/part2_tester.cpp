//
// part2 tester
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "part2.h"

using namespace std;

unsigned int tests_passed = 0;

class part2_tester_exception
{
	public:
		part2_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s;
			s << _line;

			return _msg + " line number: " + s.str(); 
		}
	private:
		part2_tester_exception();
		string _msg;
		unsigned int _line;
};

void print_list(list<int> &l)
{
	cout << "{";
	for (list<int>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << *i << ",";
	}
	cout << "}" << endl;
}

void print_vector(vector<int> &v)
{
	cout << "{";

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ",";
	}
	cout << "}" << endl;
}

void fill_list(list<int> &l, unsigned int count)
{
	srand(time(0));

	for (unsigned int i = 0; i < count ; i++ )
	{
		l.push_back(rand() & 10000);
	}
}

void fill_vector(vector<int> &v, unsigned int count)
{
	srand(time(0));

	for (unsigned int i = 0; i < count ; i++ )
	{
		v.push_back(rand() & 10000);
	}
}

bool isAscending (vector<int> &v) 
{
	for (unsigned int i = 0; i < v.size()-1; i++)
	{
		if (v[i] > v[i+1])
			return false;
	}
	return true;
}

bool isAscending (list<int> &v)
{
	list<int>::iterator i = v.begin();
	list<int>::iterator j = v.begin();
	j++;

	while (j != v.end())
	{
		if (*i > *j)
			return false;
		i++; j++;
	}
	return true;
}

void test_vector_bubblesort()
{
	vector<int> v1;

	// There is a very, very small chance that
	// randomly generated lists will already be 
	// in ascending order...	
	do {
		v1.clear();
		fill_vector(v1, 20);
	} while (isAscending(v1));

	bubble_sort(v1);

	if (!isAscending(v1))
		throw part2_tester_exception(__func__,__LINE__);

	tests_passed++;

	vector<int> v2;
	do {
		v2.clear();
		fill_vector(v2, 5000);
	} while (isAscending(v2));

	bubble_sort(v2);
	if (!isAscending(v2))
		throw part2_tester_exception(__func__,__LINE__);

	tests_passed++;
	cout << __func__ << " passed." << endl;
}

void test_list_bubblesort()
{
	list<int> v1;

	// There is a very, very small chance that
	// randomly generated lists will already be 
	// in ascending order...	
	do {
		v1.clear();
		fill_list(v1, 20);
	} while (isAscending(v1));

	bubble_sort(v1);
	if (!isAscending(v1))
		throw part2_tester_exception(__func__,__LINE__);

	tests_passed++;

	list<int> v2;
	do {
		v2.clear();
		fill_list(v2, 5000);
	} while (isAscending(v2));

	bubble_sort(v2);
	if (!isAscending(v2))
		throw part2_tester_exception(__func__,__LINE__);

	tests_passed++;
	cout << __func__ << " passed." << endl;

}

int main ()
{
	try
	{
		test_vector_bubblesort();
		test_list_bubblesort();
	}
	catch (part2_tester_exception const &e)
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

