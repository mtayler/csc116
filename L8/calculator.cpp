#include "calculator.hpp"

#include <stack>

using namespace std;

int calculator::compute( const vector<string> & expression )
{
	stack<int> calc;

	for (size_t i=0; i < expression.size(); i++) {
		/* Attempt to parse integer from current word and push to stack */
		try {
			calc.push( parse_integer(expression.at(i)) );
			continue;
		}
		catch (wrong_token_exception & e) {
			parse_operator(expression.at(i));		// If throws an exception, not a digit or an operator
													// Otherwise, word is an operator
		}

		/* If word isn't an integer, attempt calculation */

		if ( calc.size() < 2) {
			throw wrong_expression_exception("Too few operands");
		}
		int operand2 = calc.top(); calc.pop();
		int operand1 = calc.top(); calc.pop();
		switch ( parse_operator(expression.at(i)) ) {
			case add:
				calc.push(operand1+operand2);
				break;

			case subtract:
				calc.push(operand1-operand2);
				break;

			case multiply:
				calc.push(operand1*operand2);
				break;

			case divide:
				calc.push(operand1/operand2);
				break;

				/* Should be covered by parse_operator throwing exception if not one of above operators */
			default:
				break;
		}
	}
	if ( calc.size() > 1 ) {
		throw wrong_expression_exception("Too few operators.");
	}
	return calc.top();
}

