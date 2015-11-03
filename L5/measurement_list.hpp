#ifndef UVIC_CSC116_LAB5_MEASUREMENT_LIST_INCLUDED
#define UVIC_CSC116_LAB5_MEASUREMENT_LIST_INCLUDED

#include <iostream>

class measurement
{
public:
    // Method: Default constructor
    // Purpose: Default-initialize data fields.
    measurement();

    // Method: Another constructor
    // Purpose: Initialize data fields with given arguments.
    measurement(float time, float value);

    float time;
    float value;
};

// Method: "operator<<"
// Purpose: Print measurement "m" onto "stream"
// in the following format: "time: value".
std::ostream & operator<< (std::ostream & stream, const measurement & m);


class node
{
public:
    // Default constructor
    // Member "data" is implicitly default-constructed.
    node()
    {
        next=0;
    }

    // Alternative constructor
    // Member "data" is constructed as a copy of "m".
    // Member "next" is initialized to "n".
    node( const measurement & m, node *n ) 
    {
        data = m;
        next = n;
    }

    // An instance of "measurement":
    measurement data;
    // Pointer to following node (if any).
    node *next;
};


class measurement_list
{
public:
    // Method: Default constructor
    // Purpose: Initialize data fields so that this list is empty.
    measurement_list();

    // Method: Destructor
    // Purpose: Deallocate all memory (nodes) allocated by this class.
    ~measurement_list();

    // Method: size
    // Purpose: Return number of measurements stored in the list.
    int size();

    // Method: insert
    // Purpose: Insert measurement "m" after all measurements with
    // earlier time and before all measurements with later time.
    void insert( const measurement & m );

    // Method: find
    // Purpose: Find measurement with given time.
    measurement * find ( float time ) const;

    // Method: remove_earlier_than
    // Purpose: Remove all measurements with time earlier than the argument.
    void remove_earlier_than( float time );

    // Method: remove_smaller_than
    // Purpose: Remove all measurements with value smaller than the argument.
    void remove_smaller_than( float value );

    // Method: operator<<
    // Purpose: Print contents of "list" onto "stream,
    // each element on a new line.
    // Use the operator<<(std::ostream &, const measurement &)
    // to print each element.
    friend std::ostream & operator<< (std::ostream & stream,
                                      const measurement_list & list);

private:
    // Default copy constructor and assignment operator do not
    // make sense for measurement list, so make them inaccessible:
    measurement_list(const measurement_list & other);
    measurement_list & operator= (measurement_list & other);

    // Pointer to first node (if any).
    node *m_head;

    // Number of elements (nodes).
    int m_size;
};

#endif // UVIC_CSC116_LAB5_MEASUREMENT_LIST_INCLUDED
