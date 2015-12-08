#ifndef __CSC116__BST_H__
#define __CSC116__BST_H__

//
// An implementation of a binary search tree.
//
// This tree stores both keys and values associated with those keys.
//
// More information about binary search trees can be found here:
//
// http://en.wikipedia.org/wiki/Binary_search_tree
//
// Note: Wikipedia is using a different definition of
//       depth and height than we are using.  Be sure
//       to read the comments in this file for the
//	 height function.
//

#include <queue>
#include <list>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

//
// Each node in the tree stores
// both a key and a value
//
template <class K, class V> class TreeNode
{
public:
	TreeNode(K k, V v): key(k), value(v), left(0), right(0) {}

	K		key;
	V		value;
	TreeNode<K,V>	*left;
	TreeNode<K,V>	*right;
	template <class X, class Y> friend std::ostream & operator<< (std::ostream &s, const TreeNode<X,Y> &t);
};

//
// TreeNodes can output themselves to streams
template <class K, class V> std::ostream & operator << (std::ostream &s, const TreeNode<K,V> &n)
{
	s << "\"" << n.key << ":" << n.value << "\"";
	return s;
}

//
// This exception is thrown if you try to find
// a key in the tree that isn't present.
//

class key_not_found_exception {
};

//
// The binary search tree class.
//
// When creating an instance of the class you need
// to specify the type for both the key and the values
// stored.
//
// For example:
//
// BinarySearchTree<string, int> t1;
//
// or:
//
// BinarySearchTree<int, bool> t2;
//

template <class K, class V> class BinarySearchTree {
public:
	//
	// Constructor
	//
	BinarySearchTree ()
	{
		root = NULL;
	}

	//
	// Destructor
	//
	// You must call delete on all the nodes in the
	// tree.  You will need to implement
	// a helper function that performs a post-order
	// traversal over the tree deleting nodes after
	// both children have been deleted.
	//
	~BinarySearchTree()
	{
		doDelete(this->root);
	}

	//
	// Purpose:
	//
	// Insert a new Key:Value pair into the tree.  If the Key
	// already exists in the tree, update the value stored at
	// that node with the new value.
	//
	// Pre-Conditions:
	// 	the tree is a valid binary search tree
	//
	void insert (K k, V v)
	{
		TreeNode<K,V> *t = root;

		while (t)
		{
			if (k < t->key)
			{
				if (t->left)
				{
					t = t->left;
				}
				else
				{
					t->left = new TreeNode<K,V>(k,v);
				}
			}
			else if (k == t->key)
			{
				t->value = v;
				break;
			}
			else
			{
				if (t->right)
				{
					t = t->right;
				}
				else
				{
					t->right = new TreeNode<K,V>(k,v);
					break;
				}
			}
		}

		t = new TreeNode<K,V>(k,v);

		/* if no root, assign to inserted value */
		if (!root)
			root = t;

	}

	//
	// Purpose:
	//
	// Return the value stored at key.  Throw a key_not_found_exceptoin
	// if the key isn't in the tree.
	//
	// Pre-conditions:
	//	the tree is a valid binary search tree
	//
	// Returns:
	//	they value stored at key
	//
	// Throws:
	//	key_not_found_exception if key isn't in the tree
	//
	V & find (K key)
	{
		TreeNode<K,V> *t = root;
		if (!t)
			throw key_not_found_exception();

		while (t) {
			if (key == t->key) {
				return t->value;
			}
			else if (key < t->key) {
				t = t->left;
			}
			else {
				t = t->right;
			}
		}

		throw key_not_found_exception();
	}

	//
	// Purpose:
	//
	// Return the number of nodes in the tree.
	//
	// Returns:
	//	the number of nodes in the tree.
	unsigned int size()
	{
		return doSize(this->root);
	}

	//
	// Purpose:
	//
	// Return the height of the tree.  We define height
	// as being the number of nodes on the path from the root
	// to the deepest node.
	//
	// This means that a tree with one node has height 1.
	//
	// Examples:
	//	See the assignment PDF and the test program for
	//	examples of height.
	//
	unsigned int height()
	{
		return doHeight(this->root);
	}

	//
	// Purpose:
	//
	// Return a list of all the key/value pairs stored in the tree
	// The list will be constructed by performing a level-order
	// traversal of the tree.
	//
	// Level order is most commonly implemented using a queue of nodes.
	//
	//  From wikipedia (they call it breadth-first), the algorithm for level order is:
	//
	//	levelorder()
	//		q = empty queue
	//		q.enqueue(root)
	//		while not q.empty do
	//			node := q.dequeue()
	//			visit(node)
	//			if node.left ≠ null then
	//			      q.enqueue(node.left)
	//			if node.right ≠ null then
	//			      q.enqueue(node.right)
	// There is some inefficiency here as the list is copied.
	//
	list<pair<K,V> > key_value_pairs()
	{
		list<pair<K, V> > l;	// for storing (key, value) pairs

		queue<TreeNode<K,V> *> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode<K,V> *node = q.front(); q.pop();
			l.push_back(make_pair(node->key, node->value));

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		
		return l;
	}

private:

	unsigned int doHeight (TreeNode<K,V> *t)
	{
		if (t) {
			return max(doHeight(t->left), doHeight(t->right))+1;
		}
		else {
			return 0;
		}
	}

	void doDelete (TreeNode<K,V> * n )
	{
		if (n == NULL)
			return;

		doDelete(n->left);
		doDelete(n->right);
		delete n;
	}

	unsigned int doSize(TreeNode<K,V> *t)
	{
		if (t) {
			return doSize(t->right) + doSize(t->left) + 1;
		}
		else {
			return 0;
		}
	}

	void listPostOrder(TreeNode<K,V> *t, list<pair<K, V> > &l)
	{

		if (!t)
			return;

		l.push_back(make_pair(t->key, t->value));
		listPostOrder(t->left, l);
		listPostOrder(t->right, l);
	}

	TreeNode<K,V>	*root;

	template <class X, class Y> friend class tree_view;
	template <class X, class Y> friend std::ostream & operator << (std::ostream &s, const BinarySearchTree<X,Y> &t);
};

template <class K,class V> void do_inorder (std::ostream &s, const TreeNode<K,V> *n)
{
	if (!n)
		return;

	do_inorder(s,n->left);
	s << n->key << ":" << n->value << " ";
	do_inorder(s,n->right);
}

//
// Output the tree to a stream by doing an in-order traversal
//
template <class K, class V> std::ostream & operator << (std::ostream &s, const BinarySearchTree<K,V> &t)
{
	s << "{ ";
	do_inorder(s,t.root);
	s << "}";
	return s;
}
#endif

