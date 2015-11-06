#include "int_queue.hpp"

using namespace std;

struct gizmo
{
    gizmo(): value(0) {}
    explicit gizmo(int v): value(v) {}
    int value;
};

ostream & operator<<(ostream & stream, const gizmo & g)
{
    stream << g.value;
    return stream;
}

bool test_enqueue_dequeue()
{
    bool all_ok = true;

    queue<gizmo> q;

    cout << q << endl;
    for (int i = 1; i <= 5; ++i)
    {
        gizmo element(i*2);

        q.enqueue(element);

        cout << q  << "[" << q.size() << "]" << " <- " << element.value << endl;

        bool size_ok = q.size() == i;
        if (!size_ok)
            cout << "wrong queue size!" << endl;

        all_ok = all_ok && size_ok;
    }
    for (int i = 1; i <= 5; ++i)
    {
        gizmo element = q.dequeue();

        cout << element.value << " <- " << q << "[" << q.size() << "]" << endl;

        bool size_ok = q.size() == 5 - i;
        if (!size_ok)
            cout << "wrong queue size!" << endl;

        bool value_ok = element.value == i*2;
        if (!value_ok)
            cout << "wrong value dequeued!" << endl;

        all_ok = all_ok && value_ok && size_ok;
    }

    cout << "adding 5 values..." << endl;
    for (int i = 1; i <= 5; ++i)
    {
        q.enqueue(gizmo(i));
    }
    cout << "destroying..." << endl;

    return all_ok;
}

bool test_exception()
{
    queue<gizmo> q;

    try {
        q.dequeue();
    } catch (queue_empty_exception) {
        return true;
    }

    return false;
}

int main()
{
    bool all_ok = true;

    {
        cout << "** Test 1: enqueue, dequeue: " << endl;
        bool ok = test_enqueue_dequeue();
        cout << "== " << (ok ? "PASS" : "FAIL") << endl;
        ok = all_ok && ok;
    }

    cout << endl;

    {
        cout << "** Test 2: queue_empty_exception: " << endl;
        bool ok = test_exception();
        cout << "== "<< (ok ? "PASS" : "FAIL") << endl;
        ok = all_ok && ok;
    }

    return all_ok ? 0 : 1;
}
