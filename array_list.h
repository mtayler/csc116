/* array_list.h

   CSC 116 Assignment 2 (Fall 2015)

   Definitions for a list structure with integer elements, stored
   using an array.
   
   
   B. Bird & J. Corless - 09/21/2015
*/



#ifndef CSC116_ARRAY_LIST_H
#define CSC116_ARRAY_LIST_H

#include <iostream>

class array_list
{
	static const unsigned int INITIAL_SIZE = 6;
	static const unsigned int GROW_FACTOR = 2;
	
	private:
		//Pointer to the array storing elements in the list
		int* 				m_arraystorage;
		//Size of the array pointed to by m_arraystorage
		//(Note that not every position available in the array 
		// will necessarily be used by the list)
		unsigned int		m_capacity;
		//Number of elements currently in the list
		unsigned int 		m_size;
		
	public:
	
		// array_list constructor
		//
		// Construct a new, empty list
		//
		// Pre-conditions:
		//   none
		//
		// Post-conditions:
		//   m_capacity is set to INITIAL_SIZE
		//   m_arraystorage is initialized to point to an array of size INITIAL_SIZE
		//   m_size is set to 0
		//
		array_list();
		
		// array_list destructor
		// Empties the list and deallocates all internal
		// storage
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
		//
		// Post-conditions:
		//   m_arraystorage has been deallocated.
		//
		~array_list();
		
		
		// clear()
		// Resets the list to its initial state.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
		//
		// Post-conditions:
		//   m_capacity is set to INITIAL_SIZE
		//	 m_arraystorate is deallocated, then reallocated to point to an array of size INITIAL_SIZE
		//   m_size is set to 0
		//		
		void clear();
		
		
		// size()
		// Returns the number of elements in the list.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
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
		//   This array_list object has been initialized.
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
		// If the insertion would cause the number of elements
		// to exceed the capacity of m_arraystorage (that is, if
		// m_size equals m_capacity - 1 before the insertion), then
		// this method should call expand_storage() to increase the
		// size of m_arraystorage.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
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
		// If the insertion would cause the number of elements
		// to exceed the capacity of m_arraystorage (that is, if
		// m_size equals m_capacity - 1 before the insertion), then
		// this method should call expand_storage() to increase the
		// size of m_arraystorage.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
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
		// If the insertion would cause the number of elements
		// to exceed the capacity of m_arraystorage (that is, if
		// m_size equals m_capacity - 1 before the insertion), then
		// this method should call expand_storage() to increase the
		// size of m_arraystorage.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
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
		//   This array_list object has been initialized.
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
		//   This array_list object has been initialized.
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
		//   This array_list object has been initialized.
		//   m_size >= 1
		//
		// Post-conditions:
		//   The first element of the list is deleted.
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
		//   This array_list object has been initialized.
		//   m_size >= 1
		//
		// Post-conditions:
		//   The last element of the list is deleted.
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
		//   This array_list object has been initialized.
		//   m_size >= 1
		//   0 <= pos < m_size
		//
		// Post-conditions:
		//   The element at index pos in the list is deleted.
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
		// Sort the contents of this array_list with the bubble sort
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
		// This operator allows array_list objects to be printed to output
		// streams (such as cout) using the << operator.
		//
		// The list should be printed as comma-separated values inside
		// a pair of braces. For example, "{1,2,3,4}" or "{10}". An empty
		// list should be represented by "{}". This method must not print
		// any newline characters ("\n" or endl) to the stream.
		//
		// Pre-conditions:
		//   The output stream s is valid.
		//   The array_list l is valid and has been initialized.
		//
		// Post-conditions:
		//   The contents of the list have been printed to the provided
		//   stream s using the format described above.
		//
		// Returns:
		//   The stream s
		//
		friend std::ostream & operator<< (std::ostream& s, const array_list& l);
		
	private:

		void check_storage();
	
		// expand_storage()
		// Expand the internal m_arraystorage array by a factor of GROW_FACTOR.
		//
		// This is a five step process:
		//   1. Create a new array of size GROW_FACTOR*m_capacity
		//   2. Copy all elements from m_arraystorage into the new array
		//   3. Deallocate m_arraystorage.
		//   4. Set m_arraystorage to point to the new array.
		//   5. Update m_capacity to reflect the size of the new array.
		//
		// Pre-conditions:
		//   This array_list object has been initialized.
		//
		// Post-conditions:
		//   m_capacity has been increased by a factor of GROW_FACTOR
		//   m_arraystorage points to an array whose size is the new value
		//   of m_capacity and which contains all elements previously stored
		//   in m_arraystorage.
		//
		void expand_storage();
	
		//The signatures below describe two different forms of the
		//copy operations. Normally, the compiler provides a default
		//implementation of both operations unless they are otherwise
		//defined. The default implementations will not work with this
		//object, so we declare the operations private (since we will
		//not be implementing either operation).
		array_list (const array_list &);
		array_list& operator= (array_list &);
	
};


#endif
