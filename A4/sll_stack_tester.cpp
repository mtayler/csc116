//
// sll_stack_tester.cc
//
// A test program for sll_sll_stack.h
// 
// This program uses exceptions to handle error conditions.  
//

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <vector>
#include "sll_stack.h"

using namespace std;

unsigned int input[] = {1,2,3,4,5,6,7,8};
std::vector<unsigned int> values (input, input + sizeof(input) / sizeof(unsigned int) );

class stack_tester_exception
{
	public:
		stack_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s; 
			s << _line; 
			return _msg + " line number: " + s.str(); 
		}
	private:
		stack_tester_exception();
		string _msg;
		unsigned int _line;
};

void test_push_empty_size()
{
	sll_stack<unsigned int> s;
	stringstream s1;
	
	if (!s.empty())
		throw stack_tester_exception(__func__,__LINE__);
		
	for (unsigned int i = 1; i <= 10; i++)
		s.push(i*10);

	if (s.empty())
		throw stack_tester_exception(__func__,__LINE__);

	if (s.size() != 10)
		throw stack_tester_exception(__func__,__LINE__);
	
	s1<<s;
	std::cout << "Printing s: " << s << std::endl;
	std::cout.flush();
	if (s1.str() != "{TOP_100,90,80,70,60,50,40,30,20,10}")
		throw stack_tester_exception(__func__,__LINE__);

	cout << __func__ << " passed." << endl;	
}

void test_pop_all_elements()
{
	stringstream s1;
	sll_stack<unsigned int> s(values);
	unsigned int expected = values.size();
	unsigned int popped = 0;	
	
	s1 << s;
	if (s1.str() != "{TOP_8,7,6,5,4,3,2,1}")
		throw stack_tester_exception(__func__,__LINE__);
			
	for (unsigned int i = values.size(); i>0; i--)
	{
		if (s.size() != i)
			throw stack_tester_exception(__func__,__LINE__);

		popped = s.pop();
		
		if (popped != expected)
			throw stack_tester_exception(__func__,__LINE__);

		expected--;
	}
	cout << __func__ << " passed." << endl;
}

void test_peek()
{
	sll_stack<unsigned int> s(values);
	unsigned int expected = values.size();
	unsigned int top = 0;	
			
	for (unsigned int i = 0; i < values.size(); i++)
	{
		top = s.peek();
		if (top != expected)
			throw stack_tester_exception(__func__,__LINE__);
		
		if (s.size() != 8)
			throw stack_tester_exception(__func__,__LINE__);
	
	}
	cout << __func__ << " passed." << endl;
}

void test_exceptions()
{

	sll_stack<unsigned int> s;
	
	try
	{
		unsigned int x = s.pop();
		// We shouldn't get here
		std::cout << x << std::endl;
		throw stack_tester_exception(__func__,__LINE__);
	}
	catch (stack_empty_exception & e)
	{
		std::cout << "exceptions working for pop"<< std::endl;
		// do nothing, this is the correct case
	}

	try
	{
		unsigned int x = s.peek();
		// We shouldn't get here
		std::cout << x << std::endl;
		throw stack_tester_exception(__func__,__LINE__);
	}
	catch (stack_empty_exception & e)
	{
		std::cout << "exceptions working for peek"<< std::endl;
		// do nothing, this is the correct case
	}


}

int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_push_empty_size();
		tests_passed++;

		test_pop_all_elements();
		tests_passed++;

		test_peek();
		tests_passed++;

		test_exceptions();
		tests_passed++;
	}
	catch (stack_tester_exception const &e)
	{
		cout << "Failed test case: " << e.what() << std::endl;
	}
	catch (...)
	{
		cout << "Caught unhandled exception." << std::endl;
	}
	cout << "Passed: " << tests_passed << endl;
	return 0;
}
