#ifndef UVIC_CSC116_LAB8_CALCULATOR_INCLUDED
#define UVIC_CSC116_LAB8_CALCULATOR_INCLUDED

#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

enum operation
{
    add,
    subtract,
    multiply,
    divide
};

class wrong_token_exception
{
public:
    wrong_token_exception(const string & reason): reason(reason) {}
    string reason;
};

class wrong_expression_exception
{
public:
    wrong_expression_exception(const string & reason): reason(reason) {}
    string reason;
};

class calculator
{
public:
    int compute( const vector<string> & expression );

private:
    int parse_integer( const string & token )
    {
        using namespace std;

        istringstream stream(token);
        int value;
        stream >> value;
        if (stream)
        {
            // Cause end-of-stream to be detected:
            istringstream::sentry(stream, false);
            if (stream.eof())
                return value;
        }
        throw wrong_token_exception(token);
    }

    operation parse_operator( const string & token )
    {
        using namespace std;

        if (token == "+")
            return add;
        else if (token == "-")
            return subtract;
        else if (token == "x")
            return multiply;
        else if (token == "/")
            return divide;
        else
            throw wrong_token_exception(token);
    }
};

#endif // UVIC_CSC116_LAB8_CALCULATOR_INCLUDED
