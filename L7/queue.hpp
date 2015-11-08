
// TODO: Change the "include guard" to reflect new class name

#ifndef UVIC_CSC116_LAB7_QUEUE_INCLUDED
#define UVIC_CSC116_LAB7_QUEUE_INCLUDED

#include <iostream>

class queue_empty_exception {};

template <typename T>
class node
{
public:
    T value;
    node<T>  *prev;
    node<T>  *next;

    node<T> ()
    {
        value = 0;
        next = 0;
        prev = 0;
    }
    node<T> (T desired_value, node<T>  *previous_node, node<T>  *next_node )
    {
        value = desired_value;
        prev = previous_node;
        next = next_node;
    }
};


template <typename T>
class queue
{
private:
    node<T>  *m_head;
    node<T>  *m_tail;
    int m_size;

public:
    queue()
    {
        m_head = 0;
        m_tail = 0;
        m_size = 0;
    }

    ~queue()
    {
        while(m_head)
        {
            node<T>  *n = m_head;
            m_head = m_head->next;
            delete n;
        }
    }

    int size() const
    {
        return m_size;
    }

    T dequeue()
    {
        // Throw an instance of class "queue_empty_exception" if queue empty.
		if (this->size() == 0) {
			throw queue_empty_exception();
		}

        node<T>  *removed_node = m_head;

        m_head = m_head->next;

        if (m_head)
            m_head->prev = 0;
        else
            m_tail = 0;

        T removed_value = removed_node->value;
        delete removed_node;
        --m_size;

        return removed_value;
    }

    // NOTE: Use a const reference as type of method parameter
    // to avoid unnecessary copying of class instances.
    void enqueue( T value )
    {
        m_tail = new node<T> (value, m_tail, 0);
        if (m_tail->prev)
            m_tail->prev->next = m_tail;
        if (!m_head)
            m_head = m_tail;
        ++m_size;
    }

    friend
    std::ostream & operator<< ( std::ostream & stream, const queue & q )
    {
        stream << "{";
        node<T>  *n = q.m_head;
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
