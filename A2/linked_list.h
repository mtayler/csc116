/* linked_list.h

   CSC 116 Assignment 2 (Fall 2015)

   Definitions for a list structure with integer elements, stored
   using an array.
   
   
   B. Bird & J. Corless - 09/21/2015
*/



#ifndef CSC116_ARRAY_LIST_H
#define CSC116_ARRAY_LIST_H


#include <iostream>

//
// The implementation of the node class is hidden
// and its contents are defined in linked_list.cpp
//
class node;


class linked_list
{
	static const unsigned int INITIAL_SIZE = 6;
	static const unsigned int GROW_FACTOR = 2;
	
	private:
		//Pointer to the first node in the list
		node* m_head;
		
		//Pointer to the last node in the list
		node* m_tail;
		//Number of elements currently in the list
		unsigned int	m_size;

		void print();
		
	public:
	
		// linked_list constructor
		//
		// Construct a new, empty list
		//
		// Pre-conditions:
		//   none
		//
		// Post-conditions:
		//   m_head and m_tail are NULL
		//   m_size is set to 0
		//
		linked_list();
		
		// linked_list destructor
		// Empties the list and deallocates all internal
		// storage
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   All memory allocated for list nodes and elements has been
		//   deallocated.
		//
		~linked_list();
		
		
		// clear()
		// Resets the list to its initial state.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   All memory allocated for list nodes and elements has been
		//   deallocated.
		//   m_size is set to 0
		//   m_head and m_tail are NULL
		//		
		void clear();
		
		
		// size()
		// Returns the number of elements in the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   none
		//
		// Returns:
		//   The number of elements in the list.
		//
		unsigned int size() const;
		
		
		// is_empty()
		// Returns whether or not the list is empty.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   none
		//
		// Returns:
		//   true if the number of elements is 0
		//   false otherwise
		//
		bool is_empty() const;
		
		
		// insert_front(value)
		// Insert the provided value at the beginning of the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   A new element with the provided value is added
		//   to the beginning of the list.
		//   m_size increases by 1
		//
		// Example:
		//   If the list is {1,2,3,4}, then insert_front(6)
		//   will result in the list {6,1,2,3,4}
		//
		void insert_front(const int value);
		
		
		
		// insert_end(value)
		// Insert the provided value at the end of the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   A new element with the provided value is added
		//   to the end of the list.
		//   m_size increases by 1
		//
		// Example:
		//   If the list is {1,2,3,4}, then insert_end(10)
		//   will result in the list {1,2,3,4,10}
		//
		void insert_end(const int value);
		
		
		
		// insert(value, pos)
		// Insert the provided value into the list before the index
		// given by pos. After the insertion, the value will be located
		// at index pos.  Note that indices start at 0.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   0 <= pos < m_size
		//
		// Post-conditions:
		//   A new element with the provided value is inserted into
		//   the list at position pos.
		//   m_size increases by 1
		//
		// Example:
		//   If the list is {100,200,300,400}, then insert(10, 1)
		//   will result in the list {100, 10, 200, 300, 400}
		//
		void insert(const int value, const unsigned int pos);
		
		
		
		// in_list(value)
		// Search for the provided value in the list and return whether or
		// not it was found.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//
		// Post-conditions:
		//   none
		//
		// Returns:
		//   true if value is found in the list
		//   false otherwise
		//
		bool in_list(const int value);
		
		
		
		
		// get(pos)
		// Retrieve and return the element at index pos in the list. Note that
		// indices start at 0.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   0 <= pos < m_size
		//
		// Post-conditions:
		//   none
		//
		// Returns:
		//   Element at index pos
		//
		int get(const unsigned int pos);
		
		
		
		
		
		// remove_front()
		// Remove and return the first element of the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   m_size >= 1
		//
		// Post-conditions:
		//   The first element of the list is deleted and any memory
		//   allocated for its storage has been deallocated.
		//   m_size is decremented.
		//
		// Returns:
		//   The element that was removed.
		//
		// Example:
		//   If the list is {100,200,300,400}, then remove_front()
		//   would return the value 100 and the list would become
		//   {200, 300, 400}.
		//
		int remove_front();
		
		
		
		
		
		
		// remove_end()
		// Remove and return the last element of the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   m_size >= 1
		//
		// Post-conditions:
		//   The last element of the list is deleted and any memory
		//   allocated for its storage has been deallocated.
		//   m_size is decremented.
		//
		// Returns:
		//   The element that was removed.
		//
		// Example:
		//   If the list is {100,200,300,400}, then remove_front()
		//   would return the value 400 and the list would become
		//   {100, 200, 300}.
		//
		int remove_end();
		
		
		
		
		
		// remove(pos)
		// Remove and return the last element of the list.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   m_size >= 1
		//   0 <= pos < m_size
		//
		// Post-conditions:
		//   The element at index pos in the list is deleted and any memory
		//   allocated for its storage has been deallocated.
		//   m_size is decremented.
		//
		// Returns:
		//   The element that was removed.
		//
		// Example:
		//   If the list is {100,200,300,400}, then remove_front(2)
		//   would return the value 300 and the list would become
		//   {100, 200, 400}.
		//
		int remove(const unsigned int pos);
		
		
		
		// bubble_sort()
		// Sort the contents of this linked_list with the bubble sort
		// algorithm. See the wikipedia article at
		//   http://en.wikipedia.org/wiki/Bubble_sort
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
		//
		// Post-conditions:
		//   The elements of the list have been rearranged into ascending
		//   (i.e. smallest to largest) order.
		//
		void bubble_sort();
		
		
		
		// Operator for stream printing.
		// This operator allows linked_list objects to be printed to output
		// streams (such as cout) using the << operator.
		//
		// The list should be printed as comma-separated values inside
		// a pair of braces. For example, "{1,2,3,4}" or "{10}". An empty
		// list should be represented by "{}". This method must not print
		// any newline characters ("\n" or endl) to the stream.
		//
		// Pre-conditions:
		//   The output stream s is valid.
		//   The linked_list l is valid and has been initialized.
		//
		// Post-conditions:
		//   The contents of the list have been printed to the provided
		//   stream s using the format described above.
		//
		// Returns:
		//   The stream s
		//
		friend std::ostream & operator<< (std::ostream& s, const linked_list& l);
		
	private:
	
		// get_node(pos)
		// Retrieve and return a pointer to the node at index pos in the list. 
		// Note that indices start at 0.
		//
		// Pre-conditions:
		//   This linked_list object has been initialized.
		//   0 <= pos < m_size
		//
		// Post-conditions:
		//   none
		//
		// Returns:
		//   Node object representing the element at index pos
		//
		node* get_node(const unsigned int pos);
	
		//The signatures below describe two different forms of the
		//copy operations. Normally, the compiler provides a default
		//implementation of both operations unless they are otherwise
		//defined. The default implementations will not work with this
		//object, so we declare the operations private (since we will
		//not be implementing either operation).
		linked_list (const linked_list &);
		linked_list& operator= (linked_list &);
	
};


#endif
