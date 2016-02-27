#ifndef __LIST__
#define __LIST__

#include <iostream>

using namespace std;

#define MAX_SIZE	100

class list
{
public:
	list();
	~list();

	void add (int val);
	
	int  get (unsigned int pos);

	unsigned int size ();
	
private:
	int		m_storage[MAX_SIZE];
	unsigned int	m_size;

	friend std::ostream & operator<< (std::ostream& s, const list& l);
};

#endif




