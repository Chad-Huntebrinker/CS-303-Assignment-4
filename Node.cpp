#include"Node.h"

Node::Node(int D, Node* l, Node* r) {
	data = D;
	left = l;
	right = r;
}

Node::Node(int D) {
	data = D;
	left = NULL;
	right = NULL;
}

Node::~Node() {}

ostream& operator<<(ostream& w, const  Node n) {
	w << n.data;
	return w;
}