
// TODO: Change the "include guard" to reflect new class name

#ifndef UVIC_CSC116_LAB7_QUEUE_INCLUDED
#define UVIC_CSC116_LAB7_QUEUE_INCLUDED

#include <iostream>


// TODO: Add empty class "queue_empty_exception"


// TODO: Make class "node" a template with one parameter.

// Replace all occurrences of "int" that represent the stored value
// with the template parameter type.

class node
{
public:
    int value;
    node *prev;
    node *next;

    node()
    {
        value = 0;
        next = 0;
        prev = 0;
    }
    node(int desired_value, node *previous_node, node *next_node )
    {
        value = desired_value;
        prev = previous_node;
        next = next_node;
    }
};


// TODO: Rename class "int_queue" to "queue"
// and make it a template with one parameter.

// Replace all occurences of "int" that represent
// stored values with template parameter type.

// Replace all occurences of "node" with an instance of the node template.

class int_queue
{
private:
    node *m_head;
    node *m_tail;
    int m_size;

public:
    int_queue()
    {
        m_head = 0;
        m_tail = 0;
        m_size = 0;
    }

    ~int_queue()
    {
        while(m_head)
        {
            node *n = m_head;
            m_head = m_head->next;
            delete n;
        }
    }

    int size() const
    {
        return m_size;
    }

    int dequeue()
    {
        // TODO:
        // Throw an instance of class "queue_empty_exception" if queue empty.

        node *removed_node = m_head;

        m_head = m_head->next;

        if (m_head)
            m_head->prev = 0;
        else
            m_tail = 0;

        int removed_value = removed_node->value;
        delete removed_node;
        --m_size;

        return removed_value;
    }

    // NOTE: Use a const reference as type of method parameter
    // to avoid unnecessary copying of class instances.
    void enqueue( int value )
    {
        m_tail = new node(value, m_tail, 0);
        if (m_tail->prev)
            m_tail->prev->next = m_tail;
        if (!m_head)
            m_head = m_tail;
        ++m_size;
    }

    friend
    std::ostream & operator<< ( std::ostream & stream, const int_queue & q )
    {
        stream << "{";
        node *n = q.m_head;
        while(n)
        {
            stream << n->value;
            if (n->next)
                stream << ",";
            n = n->next;
        }
        stream << "}";
        return stream;
    }
};



#endif // UVIC_CSC116_LAB7_QUEUE_INCLUDED
