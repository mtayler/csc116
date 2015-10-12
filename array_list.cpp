/* array_list.cpp

   CSC 116 Assignment 2 (Fall 2015)

   Implementation of methods defined in array_list.h
*/

#include <iostream>
#include "array_list.h"

array_list::array_list()
{
	m_capacity = INITIAL_SIZE;
	m_arraystorage = new int[INITIAL_SIZE];
	m_size = 0;
}


array_list::~array_list()
{
	delete m_arraystorage;
}


void array_list::clear()
{
	m_capacity = INITIAL_SIZE;
	delete m_arraystorage;
	m_arraystorage = new int[INITIAL_SIZE];
	m_size = 0;
}

unsigned int array_list::size() const
{
	return m_size;
}

bool array_list::is_empty() const
{
	return (m_size == 0 ? true : false);
}

void array_list::insert_front(const int value)
{
	check_storage();

	// copy all values in m_arraystorage to new_array shifted one index forward
	int* new_array = new int[m_capacity];
	for (unsigned int i=0; i < m_capacity; i++) {
		new_array[i+1] = m_arraystorage[i];
	}

	new_array[0] = value;

	m_size++;

	// free current memory associated with m_arraystorage and assign to newly created array
	delete m_arraystorage;
	m_arraystorage = new_array;
}

void array_list::insert_end(const int value)
{
	check_storage();

	m_arraystorage[m_size] = value;
	++m_size;

}

void array_list::insert(const int value, const unsigned int pos)
{
	check_storage();

	int* new_array = new int[m_size*GROW_FACTOR];
	for (unsigned int i=0; i < pos; i++) {
		new_array[i] = m_arraystorage[i];
	}

	new_array[pos] = value;

	for (unsigned int i=pos; i < m_size; i++) {
		new_array[i+1] = m_arraystorage[i];
	}

	m_size++;

	delete m_arraystorage;
	m_arraystorage = new_array;
}

bool array_list::in_list(const int value)
{
	for (int i=0; i < m_size; i++) {
		if (m_arraystorage[i] == value) {
			return true;
		}
	}
	return false;
}

int array_list::get(const unsigned int pos)
{
	if (pos <= m_size) {
		return m_arraystorage[pos];
	}
	else {
		return false;
	}
}

int array_list::remove_front()
{
 	int removed = m_arraystorage[0];
 
 	int* new_array = new int[m_capacity];
 	for (int i=1; i < m_size; i++) {
 		new_array[i-1] = m_arraystorage[i];
 	}
 	delete m_arraystorage;
 	m_arraystorage = new_array;
 
 	m_size--;
 
 	return removed;
}

int array_list::remove_end()
{
 	// Seems bad, but index inbounds. m_size states how
 	// many elements m_arraystorage contains, not the array's
 	// size in memory.
 	return m_arraystorage[--m_size];
}

int array_list::remove(const unsigned int pos)
{
	// Faster function, so call if possible
	if (pos == m_size) {
		return remove_end();
	}

	int removed = m_arraystorage[pos];

	int* new_array = new int[m_capacity];
	for (int i=0; i < pos; i++) {
		new_array[i] = m_arraystorage[i];
	}
	for (int i=pos+1; i < m_size; i++) {
		new_array[i-1] = m_arraystorage[i];
	}
	delete m_arraystorage;
	m_arraystorage = new_array;

	m_size--;

	return removed;
}

void array_list::bubble_sort()
{
	bool swap_made = true;

	while(swap_made)
	{

		swap_made = false;
		for (unsigned int i = 0; i < m_size - 1; i++){
			if ( m_arraystorage[i] > m_arraystorage[i+1] )
			{
				int temp = m_arraystorage[i];
				m_arraystorage[i] = m_arraystorage[i+1];
				m_arraystorage[i+1] = temp;
				swap_made = true;
			}
		}
	}
}

std::ostream & operator<< (std::ostream &s, const array_list &l)
{
    s << "{";
    for (unsigned int i = 0; i < l.m_size; i++){
        s << l.m_arraystorage[i];
        if (i != l.m_size - 1)
            s << ",";
    }
    s << "}";
    return s;
}

void array_list::check_storage()
{
	if (m_size >= m_capacity-1) {
		expand_storage();
	}
}

void array_list::expand_storage()
{
	int* new_array = new int[m_capacity*GROW_FACTOR];
	m_capacity *= GROW_FACTOR;

	for (int i=0; i < m_size; i++) {
		new_array[i] = m_arraystorage[i];
	}

	delete m_arraystorage;
	m_arraystorage = new_array;

}
