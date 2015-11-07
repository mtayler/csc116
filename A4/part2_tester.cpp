//
// part2 tester
//

#include "part2.h"


int railway0[] = {5,4,3,2,1};	//true
int railway1[] = {1,3,5,4,2};	//true
int railway2[] = {4,3,5,1,2};	//false  - cannot do with only one spur
int railway3[] = {1,4,4,2,3}; 	//false  - duplicate entry
int railway4[] = {1,5,2,3,6};	//false	 - wrong entry
int railway5[] = {5,4,7,8,6,3,2,1};  //true  - can do with one spur

vector<int> train0 (railway0, railway0 + sizeof(railway0) / sizeof(int) );
vector<int> train1 (railway1, railway1 + sizeof(railway1) / sizeof(int) );
vector<int> train2 (railway2, railway2 + sizeof(railway2) / sizeof(int) );
vector<int> train3 (railway3, railway3 + sizeof(railway3) / sizeof(int) );
vector<int> train4 (railway4, railway4 + sizeof(railway4) / sizeof(int) );
vector<int> train5 (railway5, railway5 + sizeof(railway5) / sizeof(int) );

string res0[] = {"in->spur","in->spur","in->spur","in->spur","in->out",
					"spur->out","spur->out","spur->out","spur->out"};
string res1[] = {"in->spur","in->spur","in->out","spur->out","in->out","spur->out",
					"in->out"};
string res5[] = {"in->spur","in->spur","in->spur","in->spur","in->out","in->out",
					"spur->out","in->spur","in->out","spur->out","spur->out",
					"spur->out","spur->out"};

list<string> result0(res0, res0+sizeof(res0)/sizeof(string));
list<string> result1(res1, res1+sizeof(res1)/sizeof(string));
list<string> result5(res5, res5+sizeof(res5)/sizeof(string));


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

void test_bracket_matching_one_type()
{
	char s0[] = "";
	char s1[] = "()";
	char s2[] = "())";
	char s3[] = "(()";
	char s4[] = "((()())())";	
	bool result;

	result = match_brackets(s0);
	
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);

	result = match_brackets(s1);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
	
	result = match_brackets(s2);
	//cout<< result << endl;
	if (result)
		throw part2_tester_exception(__func__,__LINE__);
	
	result = match_brackets(s3);
	if (result)
		throw part2_tester_exception(__func__,__LINE__);	
	
	result = match_brackets(s4);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
		
	cout << __func__ << " passed." << endl;	
}

void test_bracket_matching_multiple_types()
{
	char s0[] = "{}<>()";
	char s1[] = "{([])[]}";
	char s2[] = "({}(<{{}}>))";
	char s3[] = "(({[][]})([]{}))";
	char s4[] = "(({()()}())";	
	char s5[] = "((])";	
	char s6[] = "]";	
	
	bool result;
	
	result = match_brackets(s0);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);

	result = match_brackets(s1);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
	
	result = match_brackets(s2);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
	
	result = match_brackets(s3);
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);	
	
	result = match_brackets(s4);
	if (result)
		throw part2_tester_exception(__func__,__LINE__);

	result = match_brackets(s5);
	if (result)
		throw part2_tester_exception(__func__,__LINE__);	
	
	result = match_brackets(s6);
	if (result)
		throw part2_tester_exception(__func__,__LINE__);
				
	cout << __func__ << " passed." << endl;	
}


bool compare_instruction_lists(list<string> computed, list<string> reference){
	list<string>::iterator c = computed.begin();
	list<string>::iterator r = reference.begin();
	while(c != computed.end() && r != reference.end()){
		if (*r != *c){
			//Allow "in->out" to be expanded to the two instructions "in->spur" and "spur->out"
			if (*r == "in->out" && *c == "in->spur"){
				c++;
				if (c == computed.end() || *c != "spur->out")
					return false;
			}else{
				return false;
			}
		}
		r++;
		c++;
	}
	if (c != computed.end() || r != reference.end())
		return false;
	return true;
}

void test_railway_1()
{


	bool result;
	list<string> instructions;
	
	//Test trivial success case
	result = railway(train0, instructions);
	
	/* cout<<"RESULT 0 is: "<< result <<endl; */
	/* print_switch_ops(instructions); */
	
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
	
	if (!compare_instruction_lists(instructions,result0))
		throw part2_tester_exception(__func__,__LINE__);	
	
	//Test non-trivial success case
	instructions.clear();
	result = railway(train1, instructions);
	
	/* cout<<"RESULT 1 is: "<< result <<endl; */
	/* print_switch_ops(instructions); */
	
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);
		
	if (!compare_instruction_lists(instructions,result1))
		throw part2_tester_exception(__func__,__LINE__);	
		
	//Test non-success case -- impossible with one spur
	instructions.clear();
	result = railway(train2, instructions);
	
	/* cout<<"RESULT 2 is: "<< result <<endl; */
	/* print_switch_ops(instructions); */
	
	if (result)
		throw part2_tester_exception(__func__,__LINE__);

	if (!instructions.empty())
		throw part2_tester_exception(__func__,__LINE__);	
		
	cout << __func__ << " passed." << endl;
}

void test_railway_2()
{


	bool result;
	list<string> instructions;
		
	//Test non-success case -- duplicate entry
	instructions.clear();
	result = railway(train3, instructions);
	
	//cout<<"RESULT 3 is: "<< result <<endl;
	//print_switch_ops(instructions);
	
	if (result)
		throw part2_tester_exception(__func__,__LINE__);
		
	if (!instructions.empty())
		throw part2_tester_exception(__func__,__LINE__);
	
	//Test non success case - missing entry
	instructions.clear();
	result = railway(train4, instructions);
	
	//cout<<"RESULT 4 is: "<< result <<endl;
	//print_switch_ops(instructions);
	
	if (result)
		throw part2_tester_exception(__func__,__LINE__);

	if (!instructions.empty())
		throw part2_tester_exception(__func__,__LINE__);

	//Test non-success case
	instructions.clear();
	result = railway(train5, instructions);
	
	//cout<<"RESULT 5 is: "<< result <<endl;
	//print_switch_ops(instructions);
	
	if (!result)
		throw part2_tester_exception(__func__,__LINE__);

	if (!compare_instruction_lists(instructions,result5))
		throw part2_tester_exception(__func__,__LINE__);		
		
	cout << __func__ << " passed." << endl;
}


int main ()
{
	unsigned int tests_passed = 0;

	try
	{
		test_bracket_matching_one_type();
		tests_passed++;
		
		test_bracket_matching_multiple_types();
		tests_passed++;
		
		test_railway_1();
		tests_passed++;
		
		test_railway_2();
		tests_passed++;

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
	return 0;
}
