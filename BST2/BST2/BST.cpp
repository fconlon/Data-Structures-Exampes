#include "BST.h"
#include <iostream>
using namespace std;

BST::Node::Node(int datum) {
	this->parent = 0;
	this->left = 0;
	this->right = 0;
	this->datum = datum;
}

BST::BST() {
	this->root = 0;
}

void BST::destr_helper(Node *node) {
	if (node) {
		this->destr_helper(node->left);
		this->destr_helper(node->right);
		delete node;
	}
}

BST::~BST() {
	this->destr_helper(this->root);
}

void BST::insert(int datum) {
	Node *newNode = new Node(datum);

	if (!this->root) {
		this->root = newNode;
	}
	else {
		Node *temp = this->root;
		while (temp) {
			if (datum == temp->datum) {
				throw "No duplicates allowed";
			}
			else if (datum < temp->datum) {
				if (temp->left) {
					temp = temp->left;
				}
				else {
					temp->left = newNode;
					newNode->parent = temp;
					break;
				}
			}
			else {
				if (temp->right) {
					temp = temp->right;
				}
				else {
					temp->right = newNode;
					newNode->parent = temp;
					break;
				}
			}
		}
	}
}


void BST::recur_insert(int datum) {
	Node *newNode = new Node(datum);

	if (!this->root) {
		this->root = newNode;
	}
	else {
		this->rec_inst_helper(this->root, newNode);
	}
}

void BST::rec_inst_helper(Node *node, Node *newNode) {
	if (node->datum == newNode->datum) {
		throw "No duplicates allowed";
	}
	else if (newNode->datum < node->datum) {
		if (node->left) {
			this->rec_inst_helper(node->left, newNode);
		}
		else {
			node->left = newNode;
		}
	}
	else {
		if (node->right) {
			this->rec_inst_helper(node->right, newNode);
		}
		else {
			node->right = newNode;
		}
	}
}

BST::Node* BST::search(int datum) {
	Node *temp = this->root;

	while (temp && temp->datum != datum) {
		if (datum < temp->datum) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}

	return temp;
}

void BST::remove(int datum) {
	Node *temp1 = this->search(datum);
	bool leftChild, isRoot = false;
	if (!temp1) {
		throw "Number not in tree";
	}
	else {
		//determine if root or not
		if (temp1->parent) {
			//determine if left or right child
			if (temp1->parent->left == temp1) {
				leftChild = true;
			}
			else {
				leftChild = false;
			}
		}
		else {
			isRoot = true;
		}
		//execute the remove
		if (!temp1->left) {
			if (!temp1->right) {
				if (isRoot) {
					this->root = 0;
				}
				else if (leftChild) {
					temp1->parent->left = 0;
				}
				else {
					temp1->parent->right = 0;
				}
			}
			else {
				if (isRoot) {
					this->root = temp1->right;
				}
				else {
					if (leftChild) {
						temp1->parent->left = temp1->right;
					}
					else {
						temp1->parent->right = temp1->right;
					}
				}
			}
			delete temp1;
		}
		else if (!temp1->right) {
			if (!temp1->left) {
				if (isRoot) {
					this->root = 0;
				}
				else if (leftChild) {
					temp1->parent->left = 0;
				}
				else {
					temp1->parent->right = 0;
				}
			}
			else {
				if (isRoot) {
					this->root = temp1->left;
				}
				else {
					if (leftChild) {
						temp1->parent->left = temp1->left;
					}
					else {
						temp1->parent->right = temp1->left;
					}
				}
			}
			delete temp1;
		}
		else {
			Node* temp2 = temp1->left;
			if (temp2->right == 0) {
				temp1->datum = temp2->datum;
				temp1->left = temp2->left;
			}
			else {
				while (temp2->right != 0) {
					temp2 = temp2->right;
				}
				temp1->datum = temp2->datum;
				temp2->parent->right = temp2->left;
			}
			delete temp2;
		}
	}
}

void BST::traverse() {
	this->in_order(this->root);
}

void BST::in_order(Node* node) {
	if (!node) {
		return;
	}
	else {
		
		this->in_order(node->left);
		
		this->in_order(node->right);
		cout << node->datum << endl;
	}
}