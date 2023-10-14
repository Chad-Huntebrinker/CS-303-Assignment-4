#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"Node.h"



class BinaryTree {
protected:
	Node* root;
public:
	BinaryTree();
	BinaryTree(Node* r);
	BinaryTree(int d, const BinaryTree& bLeft, const BinaryTree& bRight);
	virtual ~BinaryTree();
	friend ostream& operator<<(ostream& w, const BinaryTree bt);

	// ------------- list of methods ----------------------
	// 1 - get left subtree
	BinaryTree getLeftTree(); // ???

	// 2 - get right subtree
	BinaryTree getRightTree(); // ???

	// 3 - get data form root
	int getData();

	// 4 - check if it's empty
	bool isNull();

	// 5 - check if the tree is a leaf
	bool isLeaf();

	bool isFullTree(Node* r, bool& treeFull);
	bool returnStatus(bool treeFull);

	// 6 - print the tree(1- pre, 2- post and 3- inorder)
	void printTree(int);

	// 7 - get the height of a tree
	int getHeight();

	// 8 - get the number of nodes
	int getNumberNodes();

	string preOrder(Node* r);
	string postOrder(Node* r);
	string inOrder(Node* r);
};



#endif
