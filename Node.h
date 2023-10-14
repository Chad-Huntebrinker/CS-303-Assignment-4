#pragma once

#ifndef NODE_H
#define NODE_H


#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int D, Node* l, Node* r);
	Node(int D);
	virtual ~Node();
	friend ostream& operator<<(ostream& w, const Node n);
};



#endif

