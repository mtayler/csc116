#ifndef UVIC_CSC116_LAB7_MESSAGE_SIMULATION_INCLUDED
#define UVIC_CSC116_LAB7_MESSAGE_SIMULATION_INCLUDED

#include "queue.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class message
{
public:
    message() {}
    message( const string & t ){
        text = t;
    }

    string text; // original text
};

class filtered_message
{
public:
    filtered_message(){
        ok = true
    }
    filtered_message( const string & t, bool b_ok ) {
        text = t;
        ok = b_ok;
    }

    string text; // possibly modified text
    bool ok; // whether original text was accepted
};

class simulation
{
    queue<message> in;
    queue<filtered_message> out;

public:
    simulation();
    void run();

private:
    void produce();
    void consume();
    vector<string> subjects;
    vector<string> verbs;
    vector<string> adjectives;
    vector<string> objects;
};

void filter( queue<message> & in, queue<filtered_message> & out );

#endif // UVIC_CSC116_LAB7_MESSAGE_SIMULATION_INCLUDED
