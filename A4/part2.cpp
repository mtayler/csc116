//
// part2.cpp
//
// implement the following two functions using stacks
//

#include "part2.h"
#include <stack>

bool match_brackets (char* str)
{
	stack<char> stk;
	unsigned int i=0;
	while (str[i] != '\0') {
		switch (str[i++]) {
			case '(':
				stk.push('(');
				break;
			case '{':
				stk.push('{');
				break;
			case '[':
				stk.push('[');
				break;
			case '<':
				stk.push('<');
				break;
			case '>':
				if (stk.top() != '<' || stk.size() == 0)
					return false;
				stk.pop();
				break;
			case ']':
				if (stk.size() == 0 || stk.top() != '[')
					return false;
				stk.pop();
				break;
			case '}':
				if (stk.size() == 0 || stk.top() != '{')
					return false;
				stk.pop();
				break;
			case ')':
				if (stk.size() == 0 || stk.top() != '(')
					return false;
				stk.pop();
				break;
			default:
				return false;
		}
	}
	if (stk.size() == 0)
		return true;
	else
		return false;
}

bool railway (vector<int> cars, list<string> &moves)
{
	int search_value = cars.size();

	stack<int> in;
	stack<int> out;
	stack<int> spur;

	for (unsigned int i=0; i < cars.size(); i++) {
		in.push(cars.at(i));
	}

	while (in.size() > 0  || spur.size() > 0) {
		if (in.size() > 0 && in.top() == search_value) {
			out.push(in.top());
			moves.push_back("in->out");
			in.pop();
			search_value--;
		}
		else if (spur.size() > 0 && spur.top() == search_value) {
			out.push(spur.top());
			moves.push_back("spur->out");
			spur.pop();
			search_value--;
		}
		else if (in.size() > 0) {
			spur.push(in.top());
			moves.push_back("in->spur");
			in.pop();
		}
		else {
			moves.clear();
			return false;
		}
	}
	return true;
}

void print_switch_ops (list<string> &ops) {
	list<string>::iterator i = ops.begin();

	while (i != ops.end()) {
		cout << *i << endl;
		i++;
	}
}
