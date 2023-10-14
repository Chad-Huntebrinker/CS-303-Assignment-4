#include "BinaryTree.h"
#include <algorithm>
#include <string>

BinaryTree::BinaryTree() {
	root = NULL;
}
BinaryTree::BinaryTree(Node* r) {
	root = r;
}
BinaryTree::BinaryTree(int d, const BinaryTree& bLeft = BinaryTree(), const BinaryTree& bRight = BinaryTree()) {
	root = new Node(d, bLeft.root, bRight.root);

}
BinaryTree::~BinaryTree() {}
ostream& operator<<(ostream& w, const BinaryTree bt) {
	w << bt.root->data;
	return w;
}

// 1 - get left subtree
BinaryTree BinaryTree::getLeftTree() {
	if (root == NULL) {
		cout << "there is no left tree" << endl;
	}
	return BinaryTree(root->left);
}

// 2 - get right subtree
BinaryTree BinaryTree::getRightTree() {
	if (root == NULL) {
		cout << "there is no right tree" << endl;
	}
	return BinaryTree(root->right);
}

// 3 - get data form root
int BinaryTree::getData() {
	if (root == NULL) {
		cout << "there is no Data" << endl;
	}
	return root->data;
}

// 4 - check if it's empty
bool BinaryTree::isNull() {
	return root == NULL;
}

// 5 - check if the tree is a leaf
bool BinaryTree::isLeaf() {
	if (root != NULL)
		return (root->left == NULL && root->right == NULL);
	else
		return true;
}

bool BinaryTree::returnStatus(bool treeFull) {
	isFullTree(root, treeFull);
	return treeFull;
}

bool BinaryTree::isFullTree(Node* r, bool& treeFull) {
	if (r != NULL)
		//if left sub-tree and right sub-tree are both NULL, than this is a leaf and is still a full tree
		if (r->left == NULL && r->right == NULL) {
			treeFull = true;
		}
		else {
			//if only the left sub-tree or only the right sub-tree is NULL, than this Node has
			//only one child and means the tree is not a full tree.
			if (r->left == NULL || r->right == NULL) {
				return treeFull = false;
			}
			else {
				//if it still hasn't been proven to not be a full tree
				if (treeFull != false)
					treeFull = isFullTree(r->left, treeFull);
				//if it still hasn't been proven to not be a full tree
				if (treeFull != false)
					treeFull = isFullTree(r->right, treeFull);
			}
		}
	return treeFull;
}

// 6 - print the tree(pre, post and inorder)
void BinaryTree::printTree(int c) {
	switch (c) {
	case 1:
		cout << preOrder(root) << endl;
		break;
	case 2:
		cout << postOrder(root) << endl;
		break;
	case 3:
		cout << inOrder(root) << endl;
		break;
	default:
		cout << "Error....\n";
	}
}

// 7 - get the height of a tree
int BinaryTree::getHeight() {
	if (isNull())
		return 0;
	return 1 + max(getLeftTree().getHeight(), getRightTree().getHeight());
}

// 8 - get the number of nodes
int BinaryTree::getNumberNodes() {
	if (isNull())
		return 0;
	return 1 + getLeftTree().getNumberNodes() + getRightTree().getNumberNodes();
}

string BinaryTree::preOrder(Node* r) {
	string str;
	if (root != NULL) {
		str += to_string(r->data);
		if (r->left != NULL) {
			str += " ";
			str += preOrder(r->left);
		}
		if (r->right != NULL) {
			str += " ";
			str += preOrder(r->right);
		}
	}
	return str;
}


string BinaryTree::postOrder(Node* r) {
	string str;
	if (root != NULL) {
		if (r->left != NULL) {
			str += postOrder(r->left);
			str += " ";
		}
		if (r->right != NULL) {
			str += postOrder(r->right);
			str += " ";
		}
		str += to_string(r->data);
	}
	return str;
}
string BinaryTree::inOrder(Node* r) {
	string str;
	if (root != NULL) {
		if (r->left != NULL) {
			str += inOrder(r->left);
			str += " ";
		}
		str += to_string(r->data);
		if (r->right != NULL) {
			str += " ";
			str += inOrder(r->right);
		}
	}
	return str;
}
