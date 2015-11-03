#include "decryption.hpp"

#include <string>
#include <iostream>

using namespace std;

bool test(string name, string (*f)(string in),
          string in, string ref)
{

    size_t len = in.length();

    string out = f(in);

    int cmp = ref.compare(out);
    bool is_empty = out.empty();

    bool ok = cmp == 0 && !is_empty;

    cout << "-- Testing '" << name << "':" << endl;
    if (ok)
    {
        cout << ">> OK." << endl;
    }
    else
    {
        out[len] = 0;
        cout << ">> FAILED:" << endl;
        cout << ">> Input: " << in << endl;
        cout << ">> Expected output: " << ref << endl;
        cout << ">> Actual output: " << out << endl;
        if (is_empty)
            cout << "\tResult is empty" << endl;
    }
    cout << endl;

    return ok;
}

void test_decrypt(string msg, string ref)
{
    size_t len = ref.length();

    cout << "-- Testing 'decrypt':" << endl;
    string out = decrypt(msg);

    if (out.empty())
    {
        cout << ">> FAILED: Returned string is empty." << endl;
        return;
    }

    if (out.length() != len)
    {
        cout << ">> FAILED: Length of returned array different than"
             << " length of message." << endl;
        return;
    }

    if (out.compare(ref) != 0)
    {
        cout << ">> FAILED:" << endl;
        cout << ">> Expected message: \"" << ref << "\"" << endl;
        cout << ">> Actual message: \"" << out << "\"" << endl;
        return;
    }

    cout << ">> OK" << endl;
}

int main()
{
    test("reverse", &reverse, "abcde", "edcba");
    test("swap_halves", &swap_halves, "123456789", "567891234");
    test("reverse_five_by_five", &reverse_five_by_five,
         "_1234_1234_12", "4321_4321_21_");
    test("warp", &warp, "r@>AFE6CO$4:6?46", "Computer Science");

    test_decrypt("63O656G6:sO\\O]5=2?@:GCtOF?zO?9E=2O?pE:C@8F>O>963OED?66DO3O@EO=",
                 "An algorithm must be seen to be believed. - Donald Ervin Knuth");
}
