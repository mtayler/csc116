#ifndef __CSC116_TREE_VIEW__
#define __CSC116_TREE_VIEW__

// 
// tree_view.h
//
// This helper class is a friend of the BinarySearchTree class
// and performs various traversals to allow the tester to 
// easily see if your code constructs the correct tree.
//
// You do not need to modify or change this code.
//
// It also prints trees in a special "dot" language
// that allows you to see your tree drawn.  Copy and
// paste the output from dot_print to here:
//
// http://sandbox.kidstrythisathome.com/erdos/
//
// To see your tree drawn.
//

#include <list>
#include <iostream>
#include <utility>
#include "bst.h"

using namespace std;

template <class K, class V> class tree_view
{
public:
	tree_view(BinarySearchTree<K,V> &t): tree(t)
	{
	}

	list<pair<K,V> >	inorder()
	{
		list<pair<K,V> >	l;
		doInOrder (l, tree.root);
		return l;
	}

	list<pair<K,V> >	postorder()
	{
		list<pair<K,V> >	l;
		doPostOrder(l, tree.root);
		return l;

	}
	
	list<pair<K,V> >	preorder()
	{
		list<pair<K,V> >	l;
		doPreOrder(l,tree.root);
		return l;
	}

	// This modified from 
	// http://eli.thegreenplace.net/2009/11/23/visualizing-binary-trees-with-graphviz
	//
	void	dot_print (ostream &s)
	{
		s << "digraph BST {" << endl;
		s << "    node [fontname=\"Arial\"];" << endl;

		if (tree.root)
			do_dot_print(s,tree.root);
		else
		{
			s << endl;
		}
		s << "}" << endl;
	}


private:
	void do_dot_print (std::ostream &s, const TreeNode<K,V> *n)
	{
		static int nullcount = 0;

		if (n->left)
		{
			s << "    " << *n << " -> " << *n->left << ";\n";
			do_dot_print(s,n->left);
		}
		else
		{
			s << "    null" << nullcount << "[shape=point];\n";
			s << "    " << *n << " -> null" << nullcount << ";\n";
			nullcount++;
		}

		if (n->right)
		{
			s << "    " << *n << " -> " << *n->right << ";\n";
			do_dot_print(s,n->right);
		}
		else
		{
			s << "    null" << nullcount << "[shape=point];\n";
			s << "    " << *n << " -> null" << nullcount << ";\n";
			nullcount++;
		}	
	}

	void doInOrder (list<pair<K,V> > &l, TreeNode<K,V> *n)
	{
		if (!n)
			return;

		doInOrder(l, n->left);
		l.push_back(make_pair(n->key, n->value));
		doInOrder(l, n->right);
	}

	void doPostOrder (list<pair<K,V> > &l, TreeNode<K,V> *n)
	{
		if (!n)
			return;

		doPostOrder(l, n->left);
		doPostOrder(l, n->right);
		l.push_back(make_pair(n->key, n->value));
	}

	void doPreOrder (list<pair<K,V> > &l, TreeNode<K,V> *n)
	{
		if (!n)
			return;

		l.push_back(make_pair(n->key, n->value));
		doPreOrder(l, n->left);
		doPreOrder(l, n->right);
	}	
	BinarySearchTree<K,V> 	&tree;
};

#endif
