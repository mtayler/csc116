/* linked_list_tester.cpp

   CSC 116 Assignment 2 (Fall 2015)

   Tester for the linked_list class.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <ctime>


#include "linked_list.h"

using namespace std;

class list_tester_exception
{
	public:
		list_tester_exception (const string & msg, unsigned int line) : _msg(msg), _line(line) {}
		string what() const 
		{ 
			ostringstream s; 
			s << _line; 
			return _msg + " line number: " + s.str(); 
		}
	private:
		list_tester_exception();
		string _msg;
		unsigned int _line;
};

string remove_whitespace(string s)
{
	string result;
	for(unsigned int i = 0; i < s.length(); i++)
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			result += s[i];
	return result;
}

string convert_to_string(linked_list &l)
{
	stringstream s;
	s << l;
	return remove_whitespace(s.str());
}


void test_constructor()
{
	linked_list l;

	if (l.size() !=0 || !l.is_empty())
		throw list_tester_exception(__func__,__LINE__);
	
	cout << __func__ << " passed." << endl;
}

void test_insert_and_output_and_get()
{
	linked_list l;
	unsigned int val1, val2, val3;

	if (convert_to_string(l) != "{}")
 		throw list_tester_exception(__func__,__LINE__);

	l.insert_front(1);

	
	cout<<l<<endl;
	if (convert_to_string(l) != "{1}")
 		throw list_tester_exception(__func__,__LINE__);
 		
 	val1 = l.get(0);
 	if (val1 != 1)
 		throw list_tester_exception(__func__,__LINE__);	

	l.insert_front(2);
	l.insert_end(3);
	l.insert_end(4);
	
	cout<<l<<endl;
	if (convert_to_string(l) != "{2,1,3,4}")
 		throw list_tester_exception(__func__,__LINE__);
 		
 	val2 = l.get(2);
 	if (val2 != 3)
 		throw list_tester_exception(__func__,__LINE__);	
 		
 	l.insert(6, 1);
 	
	cout<<l<<endl;
 	if (convert_to_string(l) != "{2,6,1,3,4}")
 		throw list_tester_exception(__func__,__LINE__);
 	
 	val3 = l.get(2);
 	if (val3 != 1)
 		throw list_tester_exception(__func__,__LINE__);	
 	
 	l.insert_front(5);
 	
	cout<<l<<endl;
 	if (convert_to_string(l) != "{5,2,6,1,3,4}")
 		throw list_tester_exception(__func__,__LINE__);

	cout << __func__ << " passed." << endl;
}




void test_in_list_and_size()
{
	linked_list l;

	unsigned int expected_size = 0;
	
	for (unsigned int i=0;i<50;i += 3)
	{
		l.insert_end(i);
		expected_size++;
		if (l.size() != expected_size)
			throw list_tester_exception(__func__,__LINE__);			
	}
	
	for (unsigned int i=0;i<50;i++)
	{
		if (i % 3 == 0)	{
			if (!l.in_list(i))
				throw list_tester_exception(__func__,__LINE__);	
		}else{
			if (l.in_list(i))
				throw list_tester_exception(__func__,__LINE__);	
		}
	}
	cout << __func__ << " passed." << endl;
}



void test_remove_and_empty()
{
	linked_list l;
	
	l.insert_end(6);
	if (convert_to_string(l) != "{6}")
 		throw list_tester_exception(__func__,__LINE__);
	if (l.remove_end() != 6)
 		throw list_tester_exception(__func__,__LINE__);
	if (l.size() != 0)
 		throw list_tester_exception(__func__,__LINE__);
	l.insert_front(10);
	if (convert_to_string(l) != "{10}")
 		throw list_tester_exception(__func__,__LINE__);
	if (l.remove_end() != 10)
 		throw list_tester_exception(__func__,__LINE__);
	if (l.size() != 0)
 		throw list_tester_exception(__func__,__LINE__);
	
	
	for (unsigned int i=0;i<10;i++)
	{
		l.insert_end(i);
		if (l.size() != i+1)
			throw list_tester_exception(__func__,__LINE__);			
	}

	//cout << l << endl;
	if ( l.is_empty() )
		throw list_tester_exception(__func__,__LINE__);	

	for (unsigned int i=0;i<10;i++)
	{

		if (l.size() != 10 - i)
			throw list_tester_exception(__func__,__LINE__);	
		
		if (l.get(l.size()-1) != 9-(int)i )
			throw list_tester_exception(__func__,__LINE__);		
		
		if (l.remove_end() != 9-(int)i)
			throw list_tester_exception(__func__,__LINE__);	
	}
	
	if ( (l.size() != 0)  && (!l.is_empty()) )
		throw list_tester_exception(__func__,__LINE__);	
	
	if (l.in_list(0))
		throw list_tester_exception(__func__,__LINE__);
	
	if (l.in_list(6))
		throw list_tester_exception(__func__,__LINE__);
	
	if (l.in_list(10))
		throw list_tester_exception(__func__,__LINE__);
		

	for (unsigned int i=0;i<10;i++)
	{
		l.insert_end(i);
		if (l.size() != i+1)
			throw list_tester_exception(__func__,__LINE__);			
	}

	if ( l.is_empty() )
		throw list_tester_exception(__func__,__LINE__);	

	for (unsigned int i=0;i<10;i++)
	{

		if (l.size() != 10 - i)
			throw list_tester_exception(__func__,__LINE__);	
		
		if (l.get(0) != (int)i )
			throw list_tester_exception(__func__,__LINE__);		
		
		if (l.remove_front() != (int)i)
			throw list_tester_exception(__func__,__LINE__);		
	}
		
	cout << __func__ << " passed." << endl;
}





void test_remove_value()
{
	linked_list l;
	stringstream s1, s2, s3, s4;
	
	for (unsigned int i=0;i<8;i++)
	{
		l.insert_end(i+100);		
	}

	l.remove(0);

	cout << l << endl;
 	if (convert_to_string(l) != "{101,102,103,104,105,106,107}")
 		throw list_tester_exception(__func__,__LINE__);
 	
	if(l.get(0) != 101) 
		throw list_tester_exception(__func__,__LINE__);
	
	if (l.size() != 7)
		throw list_tester_exception(__func__,__LINE__);
		
	l.insert_end(2);
	l.insert_end(8);
	
	//cout << l << endl;
 	if (convert_to_string(l) != "{101,102,103,104,105,106,107,2,8}")
 		throw list_tester_exception(__func__,__LINE__);
 		
 	if (l.remove(2) != 103)
		throw list_tester_exception(__func__,__LINE__);
 	
 	if (l.in_list(103)) 
		throw list_tester_exception(__func__,__LINE__);
 		
 	if (convert_to_string(l) != "{101,102,104,105,106,107,2,8}")
 		throw list_tester_exception(__func__,__LINE__);
 	
 	if (l.get(0) != 101) 
		throw list_tester_exception(__func__,__LINE__);
	
	if (l.size() != 8)
		throw list_tester_exception(__func__,__LINE__);
	
	if (l.remove(6) != 2)
		throw list_tester_exception(__func__,__LINE__);
 	
 	
 	if (convert_to_string(l) != "{101,102,104,105,106,107,8}")
 		throw list_tester_exception(__func__,__LINE__);
 			
	if (l.size() != 7)
		throw list_tester_exception(__func__,__LINE__);
		
	if (l.in_list(2))
		throw list_tester_exception(__func__,__LINE__);
	
	cout << __func__ << " passed." << endl;
}




void test_clear()
{
	linked_list l;
	
	for (unsigned int i=0;i<8;i++)
	{
		l.insert_end(i);		
	}

	if (l.size() != 8)
		throw list_tester_exception(__func__,__LINE__);

	l.clear();

	if (!l.is_empty() || l.size() != 0)
		throw list_tester_exception(__func__,__LINE__);

	for (unsigned int i=0;i<8;i++)
	{
		if(l.in_list(i)) 
			throw list_tester_exception(__func__,__LINE__);		
	}		

	cout << __func__ << " passed." << endl;
}


void stress_test()
{

	linked_list l;

	for (unsigned int i=0;i<10000;i++)
	{
			l.insert_end(i);
			l.insert_front(i);

	}
	if (l.size() != 20000)
		throw list_tester_exception(__func__,__LINE__);

	for (unsigned int i = 0;i<10000;i++)
	{
		
		if (l.get(10000-i-1) != (int)i)
			throw list_tester_exception(__func__,__LINE__);
		
		if (l.get(10000+i) != (int)i)
			throw list_tester_exception(__func__,__LINE__);	
	}
	
	for (unsigned int i=0;i<5000;i++)
	{
		l.remove_front();
		l.remove_end();
	}
	
	if (l.size() != 10000 || l.is_empty())
			throw list_tester_exception(__func__,__LINE__);
			
	for (unsigned int i=0;i<10000;i++)
	{
		l.remove_front();
	}
	if (l.size() != 0 || !l.is_empty())
			throw list_tester_exception(__func__,__LINE__);
		
	cout << __func__ << " passed." << endl;
}


bool check_sorted(linked_list& l){
	if (l.size() == 0)
		return true;
	int previous = l.get(0);
	for (unsigned int i = 1; i < l.size(); i++)
	{
		int next = l.get(i);
		if (next < previous)
			return false;
		previous = next;
	}
	return true;
}


float clock_seconds(){
	clock_t t = clock();
	return t/(float)CLOCKS_PER_SEC;
}

void sort_test(){

	linked_list l;

	int last_val = 5679;
	for (unsigned int i=0;i<10;i++)
	{
			int next_val = ((i+1)*last_val)%10000;
			l.insert_end(next_val - 5000);
			last_val = next_val+1;

	}
	if (l.size() != 10)
		throw list_tester_exception(__func__,__LINE__);
	
	cout << "Attempting to sort the list " << l << endl;
	
	l.bubble_sort();
	
	if (!check_sorted(l))
		throw list_tester_exception(__func__,__LINE__);
		
		
	cout << "Sort successful." << endl;
	
	
	l.clear();
	last_val = 5679;
	for (unsigned int i=0;i<10000;i++)
	{
			int next_val = ((i+1)*last_val)%10000;
			l.insert_end(next_val - 5000);
			last_val = next_val+1;

	}
	if (l.size() != 10000)
		throw list_tester_exception(__func__,__LINE__);

	cout << "Attempting to sort a list of 10000 elements" << endl;
	
	float start_time = clock_seconds();
	l.bubble_sort();
	float total_time = clock_seconds() - start_time;
	
	if (!check_sorted(l))
		throw list_tester_exception(__func__,__LINE__);
	
	cout << "Sort successful. Total time: " << total_time << " seconds";
	if (total_time > 30){
		cout << " (sorting is too slow)" << endl;
		throw list_tester_exception(__func__,__LINE__);
	} else {
		cout << endl;
	}
	
		
	cout << __func__ << " passed." << endl;
}



int main ()
{
	unsigned int tests_passed = 0;

	bool complete = false;
	try
	{
		test_constructor();
		tests_passed++;

		test_insert_and_output_and_get();
		tests_passed++;
		
		test_in_list_and_size();
		tests_passed++;
	
		test_remove_and_empty();
		tests_passed++;

		test_remove_value();
		tests_passed++;

		test_clear();
		tests_passed++;	

		stress_test();
		tests_passed++;
		
		cout << endl;
		cout << "Part II complete" << endl;
		cout << "Starting Part III tests" << endl;
		cout << endl;
		
		sort_test();
		tests_passed++;
		complete = true;
	}
	catch (list_tester_exception const &e)
	{
		cout << "Failed test case: " << e.what() << std::endl;
	}
	catch (...)
	{
		cout << "Caught unhandled exception." << std::endl;
	}
	cout << "Passed: " << tests_passed << endl;
	if (complete)
		cout << "Part III complete." << endl;
	return 0;
}
