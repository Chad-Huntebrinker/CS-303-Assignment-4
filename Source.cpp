#include "BinaryTree.h"

using namespace std;

int main() {
	bool isFull = true;
	BinaryTree B1(new Node(15));
	BinaryTree B2(new Node(25));
	BinaryTree B3(30, B1, B2);

	BinaryTree BA(new Node(150));
	BinaryTree BB(new Node(250));
	BinaryTree BC(300, BA, BB);

	BinaryTree B(1000, B3, BC);
	isFull = B.returnStatus(isFull);
	cout << isFull << endl;

	//cout << B3 << endl;
	//cout << B2 << endl;
	//cout << B1 << endl;
	//BinaryTree temp = B.getRightTree();
	//cout << temp << endl;
	//cout <<B1.isLeaf()<<" "<<B1.isNull()<< " " << B1.getData() << endl;
	//cout <<B3.isLeaf()<<" "<<B3.isNull()<< " " << B3.getData() << endl;
	//cout << B.getHeight() << " " << B.getNumberNodes() << endl;
	B.printTree(3);
}