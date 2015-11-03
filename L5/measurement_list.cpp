#include "measurement_list.hpp"

using namespace std;

//// Implementation of class "measurement" ////

measurement::measurement()
{
	this->time = 0;
	this->value = 0;
}

measurement::measurement(float time, float value)
{
	this->time = time;
	this->value = value;
}

ostream & operator<< (ostream & stream, const measurement & m)
{
	stream << m.time << ": " << m.value;
    return stream;
}

//// Implementation of class "measurement_list" ////

measurement_list::measurement_list()
{
	this->m_head = NULL;
	this->m_size = 0;
}

measurement_list::~measurement_list()
{
	node *t = m_head;

	if (t == NULL) {
		return;
	}

	node *d;
	while (t->next) {
		d = t;
		t = t->next;
		delete d;
	}
	delete t;
}

int measurement_list::size()
{
    return 0;
}

void measurement_list::insert( const measurement & m )
{
	node* t = m_head;
	if (t == NULL) {
		node* d = new node(m, NULL);
		m_head = d;
		return;
	}

	while (t->next && m.time > t->data.time) {
		t = t->next;
	}
	node* d = new node(m, t->next);
	t->next = d;
}

measurement * measurement_list::find ( float time ) const
{
	node* t = m_head;

	while (t && t->next && t->data.time != time) {
		t = t->next;
	}
	if (t == NULL) {
		measurement* error = new measurement(-1, -1);
		return error;
	}

	return &t->data;
}

void measurement_list::remove_earlier_than( float time )
{
}

void measurement_list::remove_smaller_than( float value )
{
}

ostream & operator<< (ostream & stream, const measurement_list & list)
{
	node* t = list.m_head;
	stream << "{";
	while (t) {
		stream << t->data;
		if (t->next) {
			stream << ", ";
		}
		t = t->next;
	}
	stream << "}";
    return stream;
}
