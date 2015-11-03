#include "decryption.hpp"
#include <string>
#include <iostream>

using namespace std;

string reverse(string in)
{
    string out;
	
	for (int i=in.length()-1; i >= 0; i--) {
		out += in[i];
	}

    return out;
}

string warp(string in)
{
    string out;
	for (int i=0; i < in.length(); i++) {
		out += (in[i] < 79 ? in[i]-32+79 : in[i]-79+32);
	}
    return out;
}

string swap_halves(string in)
{
    string out;

	out += in.substr((int)in.length()/2);
	out += in.substr(0, in.length()/2);

    return out;
}


string reverse_five_by_five(string in)
{
    string out;

	for (int i=0; i < in.length(); i += 5) {
		out += reverse(in.substr(i, 5));
	}
    return out;
}


string decrypt(string msg)
{
    string out;
	
	out = warp(reverse_five_by_five(swap_halves(msg)));

    return out;
}
