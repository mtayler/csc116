//
// sll_stack.h
//
// A container for storing integers. The implementation of the sll_stack will 
// use a singly-linked list data structure.
//
#ifndef CSC116_STACK_H
#define CSC116_STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//
// This exception will be used to indicate when invalid access to
// an empty sll_stack occurs.
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
class node
{
	public:
		node() : m_value(0), m_next(0) {}
		node( T val, node *nxt ) : 
			m_value(val), m_next(nxt) {}

		T		m_value;
		node *	m_next;
};

template <class T>
class sll_stack
{
public:

	//
	// Construct a new, empty sll_stack.
	//
	// Pre-conditions:
	//	none
	sll_stack()
	{
		m_top = NULL;
		m_size = 0;
	}
	
	//
	// Construct a new, sll_stack with the values from vector
	// pushed on to the stack. 
	//
	// For example, if vec={1,2,3}, values are pushed 
	// on the stack and s={TOP_3,2,1}
	//
	// Pre-conditions:
	//	none
	sll_stack(vector<T> &vec)
	{
		m_top = NULL;
		m_size = 0;
		for (unsigned int i=0; i < vec.size(); i++) {
			this->push(vec[i]);
		}
	}
	
	//
	// Destructor
	//
	~sll_stack()
	{
		clear();
	}


	//
	// Make the sll_stack empty.  For example, if s={TOP_1,2,3}, 
	// after s.clear(), s={}
	//
	// Pre-conditions:
	//	none
	void clear()
	{
		while (m_size != 0) {
			this->pop();
		}
	}

	//
	// Return the number of elements in the sll_stack
	//
	// Pre-conditions:
	//	none
	//
	// Returns:
	//	number of elements in this sll_stack
	//
	unsigned int	size() const
	{
		return m_size;
	}

	//
	// Returns whether or not the stack is empty.
	//
	// Pre-conditions:
	//	none
	//
	// Returns:
	//	true	the number of elements in the sll_stack is 0
	//	false	the number of elements in the sll_stack is > 0
	bool		empty() const
	{
		return (m_size == 0 ? true : false);
	}

	//
	// Insert a new element at the front of the sll_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.push(4) is called, 
	// the result is: s={TOP_4,1,2,3}
	//
	// Pre-conditions:
	//	none
	//
	void	push(const int val)
	{
		if (m_size == 0) {
			m_top = new node<T>(val, NULL);
		}
		else m_top = new node<T>(val, m_top);

		m_size++;
	}

	// 
	// Return and remove the first element in the sll_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.pop() is called, 
	// 1 is returned and s={TOP_2,3}
	//
	// Pre-conditions:
	//	none
	//
	// Returns
	//	the top element in the sll_stack
	//
	// Throws
	//	stack_empty_exception if size() == 0
	T 	pop()
	{
		if (m_size == 0) {
			throw stack_empty_exception("Nothing to pop", __LINE__);
		}

		node<T>* hold = m_top;
		T val = m_top->m_value;
		
		m_top = m_top->m_next;
		delete hold;

		m_size--;

		return val;
	}

	// 
	// Returns the element at the top of the sll_stack.  
	//
	// For example, if s={TOP_1,2,3} and s.peek() is called, 
	// 1 is returned and s={TOP_1,2,3}
	//
	// Pre-conditions:
	//	none
	//
	// Returns
	//	the first element in the sll_stack
	//
	// Throws
	//	stack_empty_exception if size() == 0
	T peek()
	{
		if (m_size == 0) {
			throw stack_empty_exception("Nothing to peek at", __LINE__);
		}

		return m_top->m_value;
	}

	//
	// Print the sll_stack to the stream.  The format is: {TOP_1,2,3}
	// Do not print a newline in this method.  
	// The empty sll_stack is: {TOP_}
	//
	// This is declared as a friend so the implementation can be 
	// more efficient.  
	//
	// Pre-conditions:
	//	ostream s is valid
	//	sll_stack s is valid
	friend std::ostream & operator<< (std::ostream &s, const sll_stack &stk)
	{
		s << "{TOP_";
		
		node<T>* tracker = stk.m_top;
		while (tracker->m_next != NULL) {
			s << tracker->m_value << ",";
			tracker = tracker->m_next;
		}
		s << tracker->m_value << "}";

		return s;
	}


private:
	
	node<T>*		m_top;
	unsigned int	m_size;
	

	// These are private to prevent users of the sll_stack class
	// from copying and assigning sll_stacks
	//
	// The compiler provides default implementations of these
	// operations and they will not work for our sll_stack.
	// 
	// Since we aren't going to implement these in the current 
	// assignment, we will leave them private.
	sll_stack (const sll_stack &);
	sll_stack& operator= (sll_stack &);
};
#endif

