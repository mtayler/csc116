#ifndef __CSC116__DICTIONARY__
#define __CSC116__DICTIONARY__

#include <iostream>
#include "bst.h"

#define DEFAULT_VALUE (0)

// The dictionary class supports two main operations:
//	insert
// 	find
//
// with the additional convinience of operator[].
//

template <class K, class V> class Dictionary
{
public:
	
	// Constructor
	Dictionary()
	{
		bst =  new BinarySearchTree<K,V>();
		m_size = 0;
	}
	
	// Destructor
	~Dictionary()
	{
		m_size = 0;
		delete bst;
	}

	//
	// Purpose:
	//	return a reference to the value stored at key
	//
	// 	If key is not in the dictionary, add a new
	//	key / value pair, at the key.  Use the 
	//	default constructor to initialze the value and
	//	return a reference to that value.
	//
	V & operator[] (K key)
	{
		try {
			return bst->find(key);
		}
		catch (key_not_found_exception) {
			bst->insert(key, DEFAULT_VALUE);
			m_size++;
		}
		return bst->find(key);
	}

	//
	// Purpose:
	//	Add a new key/value pair to the dictionary.
	//
	void insert (K key, V value)
	{
		bst->insert(key, value);
		m_size = bst->size();
	}
	//
	// Purpose:
	//	Return the value stored at key.
	//	
	//	throw key_not_found_exception if key is not in the 
	//	dictionary.
	V & find (K key)
	{
		if (bst->size() <= 0) {
			throw key_not_found_exception();
		}
		return bst->find(key);
	}

	//
	// Purpose:
	//	Return a list of all the key/value pairs in the
	//	dictionary.
	//
	list<pair<K,V> > key_value_pairs() 
	{
		bst->key_value_pairs();
	}

	//
	// Purpose:
	//	Return the number of elements stored in the dictionary
	//
	unsigned int size()
	{
		return m_size;
	}

private:
	BinarySearchTree<K,V> *bst;
	size_t m_size;
};

#endif

