/* linked_list.cpp

   CSC 116 Assignment 2 (Fall 2015)

   Implementation of methods defined in linked_list.h
*/

#include <iostream>
#include "linked_list.h"

// The node class is used to represent the nodes of the linked list.
// Each node contains an integer value and pointers to the elements
// which appear before and after it in the list.
//
// Since node objects are only used inside this file and are designed as
// a collection of plain data, the contents of each object are public and
// can be accessed directly by the list methods below. For example,
// if p is a pointer to a node, the value stored in the node can be set
// with the assignment
//   p->value = 6;
//
class node
{
	public:
		node()
		{
			value = 0;
			next = NULL;
			prev = NULL;
		}
		node(node* prev, int val, node *next)
		{
			this->prev = prev;
			value = val;
			this->next = next;
		}

		int value;
		node* next;
		node* prev;
};

linked_list::linked_list()
{
	m_head = NULL;
	m_tail = NULL;

	m_size = 0;
}

linked_list::~linked_list()
{
	if (m_tail != NULL && m_size > 0) { // if m_tail is NULL, list is already empty
		node *p = m_tail;

		while(p->prev != NULL) {
			p = p->prev;
			delete p->next;
		}
		delete p;
	}
}

void linked_list::clear()
{
	node* p = m_tail;
	while (p->prev) {
		p = p->prev;
		delete p->next;
	}
	delete p;

	m_size = 0;
}

unsigned int linked_list::size() const
{
	return m_size;
}

bool linked_list::is_empty() const
{
	return (m_size == 0 ? true : false);
}

void linked_list::insert_front(const int value)
{
	node* p = new node(NULL, value, m_head);
	if (m_head != NULL) {
		m_head->prev = p;
	}
	else {
		m_tail = p;
	}

	m_head = p;

	m_size++;
}

void linked_list::insert_end(const int value)
{
	node* p = new node(m_tail, value, NULL);
	if (m_head != NULL && m_tail != NULL) {
		m_tail->next = p;
	}
	else {
		m_head = p;
	}

	m_tail = p;

	m_size++;
}

void linked_list::insert(const int value, const unsigned int pos)
{
	node* t;

	t = m_head;
	for (int i=1; i < pos; i++) {
		t = t->next;
	}

	node* p = new node(t, value, t->next);
	t->next = p;

	m_size++;
}

bool linked_list::in_list(const int value)
{
	node* t = m_head;
	for (int i=0; i < m_size; i++) {
		if (t->value == value) {
			return true;
		}
		t = t->next;
	}
	return false;
}

int linked_list::get(const unsigned int pos)
{
	node* t = m_head;
	for (int i=0; i < pos; i++) {
		t = t->next;
	}
	return t->value;
}

int linked_list::remove_front()
{
	node* t;
	t = m_head;
	m_head = m_head->next;

	int removed = t->value;
	delete t;
	m_size--;

	return removed;
}

int linked_list::remove_end()
{
	node* t;
	t = m_tail;
	m_tail = m_tail->prev;

	/* if list now empty, set m_head to reflect */
	if (m_tail == NULL) {
		m_head = NULL;
	}

	int removed = t->value;
	delete t;
	m_size--;

	return removed;
}

int linked_list::remove(const unsigned int pos)
{
	node* t;

	t = m_head;
	for (int i=0; i < pos; i++) {
		t = t->next;
	}

	/* if node before t is NULL, node after t becomes head */
	if (t->prev != NULL) {
		t->prev->next = t->next;
	}
	else {
		m_head = t->next;
	}
	/* if node after t is NULL, node before t becomes tail */
	if (t->next != NULL) {
		t->next->prev = t->prev;
	}
	else {
		m_tail = t->prev;
	}

	int removed = t->value;

	delete t;
	m_size--;

	return removed;
}

void linked_list::bubble_sort()
{
	/* This implementation is very slow
	 * It can be improved by iterating over the list to make
	 * swaps instead of calling get_node */
	bool swap_made = true;

	while(swap_made)
	{

		swap_made = false;
		for (unsigned int i = 0; i < m_size - 1; i++)
		{
			node *currentNode = get_node(i);
			node *nextNode = get_node(i+1);
			if ( currentNode->value > nextNode->value )
			{
				int temp = currentNode->value;
				currentNode->value = nextNode->value;
				nextNode->value = temp;
				swap_made = true;
			}
		}
	}
}

std::ostream & operator<< (std::ostream &s, const linked_list &l)
{
	s << "{";
	node* p = l.m_head;
	while (p != NULL) {
		s << p->value;
		if (p->next != NULL) {
			s << ", ";
		}
		p = p->next;
	}
	s << "}";
	return s;
}

void linked_list::print() {
	std::cout << "{";
	node* p = m_head;
	while (p != NULL) {
		std::cout << p->value;
		if (p->next != NULL) {
			std::cout << ", ";
		}
		p = p->next;
	}
	std::cout << "}" << std::endl;
}


node* linked_list::get_node(const unsigned int pos)
{
	//Erroneous return value (to prevent a compiler error)
	return NULL;
}
