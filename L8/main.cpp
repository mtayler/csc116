#include "calculator.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main( int argc, char **argv )
{
    vector<string> expression;
    for (int argi = 1; argi < argc; ++argi)
        expression.push_back(argv[argi]);

    calculator calc;

    int result;
    try
    {
        result = calc.compute(expression);
    }
    catch (wrong_expression_exception & e)
    {
        cout << "Invalid expression: " << e.reason << endl;
        return 1;
    }
    catch (wrong_token_exception & e)
    {
        cout << "Invalid token: " << e.reason << endl;
        return 1;
    }

    cout << "= " << result << endl;
    return 0;
}
