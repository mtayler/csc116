#include "message_simulation.hpp"

#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <chrono>
#include <thread>
using namespace chrono;
#endif

vector<string> & operator<< (vector<string> & v, const string & elem)
{
    v.push_back(elem);
    return v;
}

simulation::simulation()
{
    subjects << "cat"
             << "mouse"
             << "dog"
             << "snail"
             << "chameleon"
             << "witch"
                ;

    objects << "cheese"
            << "home"
            << "beer"
            << "poison"
            << "computer"
            << "coffee"
               ;


    adjectives << "tiny"
               << "huge"
               << "crazy"
               << "boring"
               << "lazy"
               << "funny"
               << "party"
                  ;

    verbs << "needs"
          << "bakes"
          << "brews"
          << "plays with"
          << "hides under"
             ;


    // Seed random number generator with current time:
    std::srand(std::time(0));
}

void simulation::run()
{
    long time = 0;

    long next_production = 0;
    long next_consumption = 2000;

    while(true)
    {
        if (time >= next_production)
        {
            produce();
            double delay_fraction = (rand() % 1000) / 1000.0;
            long delay = delay_fraction * delay_fraction * 3000 + 400;
            next_production += delay;
        }
        if (time >= next_consumption)
        {
            filter(in, out);
            consume();
            next_consumption = next_consumption + 2000;
        }

        long sleep_ms = std::min( next_production - time,
                                  next_consumption - time);

#ifdef _WIN32
        Sleep((DWORD) sleep_ms);
#else
        milliseconds sleep_time(sleep_ms);
        this_thread::sleep_for(sleep_time);
#endif
        time += sleep_ms;
    }
}

void simulation::produce()
{
    string subject = subjects[rand() % subjects.size()];
    string subject_kind = adjectives[rand() % adjectives.size()];
    string object = objects[rand() % objects.size()];
    string object_kind = adjectives[rand() % adjectives.size()];
    string verb = verbs[rand() % verbs.size()];

    ostringstream text;
    text << "A " << subject_kind << " " << subject
         << " " << verb
         << " a " << object_kind << " " << object
         << ".";

    cout << "IN --> " << text.str() << endl;

    in.enqueue(message(text.str()));
}

void simulation::consume()
{
    while(true)
    {
        try
        {
            filtered_message msg = out.dequeue();
            cout << "       OUT --> ";
            if (!msg.ok)
                cout << "MARKED: ";
            cout << msg.text << endl;
        }
        catch (queue_empty_exception)
        {
            break;
        }
    }
}
