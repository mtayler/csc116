//
// vector_stack.h
//
// A container for storing unsigned integers. The implementation of the vector_stack will 
// use a vector data structure.
//
// This version introduces an exception for empty vector_stack accesses.
//
#ifndef CSC116_STACK_H
#define CSC116_STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const unsigned int g_initialsize = 2;
static const unsigned int g_growFactor = 2;

using namespace std;

//
// This exception will be used to indicate when invalid access to
// an empty vector_stack occurs.
//
class stack_empty_exception {
		
	public:
		stack_empty_exception(const string & msg, unsigned int line) {  
			_msg = msg; _line = line;
		}
		string what() {	
			ostringstream s;
			s << "stack empty in function: " << _msg << " at line: " << _line;
            return s.str();
		}
	private:
		stack_empty_exception();
		string			_msg;
		unsigned int	_line;
};


template <class T>
class vector_stack
{
public:


	//
	// Construct a new, empty vector_stack.
	//
	// Pre-conditions:
	//	none
	vector_stack()
	{
		m_size = 0;
		m_top = 0;  
		m_capacity = g_initialsize;
		allocate_storage(g_initialsize);
	}

	//
	// Construct a new, vector_stack with the values from vector
	// pushed on the stack. 
	//
	// For example, if v={1,2,3}, values are pushed 
	// on the stack and s={TOP_3,2,1}
	//
	// Pre-conditions:
	//	none
	vector_stack(vector<T> &vec)
	{
		unsigned int numvals = vec.size();
		allocate_storage(numvals);
		m_capacity = numvals;
		m_top = 0;
		m_size = 0;
		for (unsigned int i = 0; i < numvals; i++)
		{
			push(vec[i]); 

		}
	}

	~vector_stack()
	{
		delete[] m_storage;
		// theoretically these next three lines aren't required
		// in practice, this might help you catch an error
		m_storage = 0;
		m_capacity = 0;
		m_size = 0;
		m_top = 0;  
	}

	//
	// Make the vector_stack empty.  For example, if s={TOP_1,2,3}, 
	// after s.clear(), s={TOP_}
	//
	// Pre-conditions:
	//	none
	void clear()
	{
		m_size = 0;
	}

	//
	// Return the number of elements in the vector_stack
	//
	// Pre-conditions:
	//	none
	//
	// Returns:
	//	number of elements in the vector_stack
	//
	unsigned int	size() const
	{
		return m_size;
	}

	//
	// Is the vector_stack empty?  Ie. the vector_stack contains no elements
	//
	// Pre-conditions:
	//	none
	//
	// Returns:
	//	true	the number of elements in the vector_stack is 0
	//	false	the number of elements in the vector_stack is > 0
	bool		empty() const
	{
		return m_size == 0;
	}

	//
	// Insert a new element at the front of the vector_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.push(4) is called, 
	// the result is: s={TOP_4,1,2,3}
	//
	// Pre-conditions:
	//	none
	//
	void	push(const T val)
	{
		if (m_size == m_capacity)
			grow_and_copy_storage();

		m_storage[m_top++] = val;
		
		m_size++;
	}

	// 
	// Return and remove the first element in the vector_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.pop() is called, 
	// 1 is returned and s={TOP_2,3}
	//
	// Pre-conditions:
	//	none
	//
	// Returns
	//	the top element in the vector_stack
	//
	// Throws
	//	stack_empty_exception if size() == 0
	T pop()
	{
		if (m_size == 0)
			throw stack_empty_exception(__func__, __LINE__);
		
		m_size--;

		return m_storage[--m_top];
		
	}

	// 
	// Returns the element at the top of the vector_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.peek() is called, 
	// 1 is returned and s={TOP_1,2,3}
	//
	// Pre-conditions:
	//	none
	//
	// Returns
	//	the first element in the vector_stack
	//
	// Throws
	//	stack_empty_exception if size() == 0
	T peek()
	{
		if (m_size == 0)
			throw stack_empty_exception(__func__, __LINE__);
		
		return m_storage[(m_top-1)];
	}

	//
	// Print the vector_stack to the stream.  The format is: {TOP_1,2,3}
	// Do not print a newline in this method.  
	// The empty vector_stack is: {TOP_}
	//
	// This is declared as a friend so the implementation can be 
	// more efficient.  
	//
	// Pre-conditions:
	//	ostream s is valid
	//	vector_stack s is valid
	friend std::ostream & operator<< (std::ostream &s, const vector_stack<T> &v)
	{
		s << "{TOP_";
		for (unsigned int i=v.size(); i>0; i--)
		{
			s << v.m_storage[i-1];
			if (i != 1)
				s << ",";
		}
		return s << "}";
	}


private:
	
	T *	m_storage;
	unsigned int 	m_top;
	unsigned int 	m_capacity;
	unsigned int	m_size;
	
	void allocate_storage(unsigned int size)
	{
		m_storage = new T[size];	
	}

	void grow_and_copy_storage()
	{
		T *oldstorage = m_storage;
		unsigned int oldcap = m_capacity;
	
		m_capacity*= g_growFactor;
		allocate_storage(m_capacity);

		for (unsigned int i=0;i<oldcap;i++)
		{
			m_storage[i] = oldstorage[i];
		}
		delete [] oldstorage;
	}

	// These are private to prevent users of the vector_stack class
	// from copying and assigning vector_stacks
	//
	// The compiler provides default implementations of these
	// operations and they will not work for our vector_stack.
	// 
	// Since we aren't going to implement these in the current 
	// assignment, we will leave them private.
	vector_stack (const vector_stack<T> &);
	vector_stack& operator= (vector_stack<T> &);
};
#endif

