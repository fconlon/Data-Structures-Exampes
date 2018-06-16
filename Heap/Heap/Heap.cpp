#include "Heap.h"

Heap::Node::Node(int datum) {
	this->datum = datum;
	this->left = 0;
	this->right = 0;
	this->parent = 0;
}

Heap::Heap() {
	this->root = 0;
	this->tail = 0;
}

void Heap::destr_helper(Node *node) {
	if (node) {
		this->destr_helper(node->left);
		this->destr_helper(node->right);
		delete node;
	}
}

Heap::~Heap() {
	this->destr_helper(this->root);
}

void Heap::upheap(Node *node) {
	if (node->parent && node->datum <= node->parent->datum) {
		int temp = node->datum;
		node->datum = node->parent->datum;
		node->parent->datum = temp;
		this->upheap(node->parent);
	}
}

void Heap::downheap(Node* node) {
	if (node->left && node->right) {
		if (node->left->datum <= node->right->datum) {
			if (node->left->datum <= node->datum) {
				int temp = node->datum;
				node->datum = node->left->datum;
				node->left->datum = temp;
				this->downheap(node->left);
			}
		}
		else {
			if (node->right->datum <= node->datum) {
				int temp = node->datum;
				node->datum = node->right->datum;
				node->right->datum = temp;
				this->downheap(node->right);
			}
		}
	}
	else if (node->left) {
		if (node->left->datum <= node->datum) {
			int temp = node->datum;
			node->datum = node->left->datum;
			node->left->datum = temp;
			this->downheap(node->left);
		}
	}
}

void Heap::push(int datum) {
	Node *newNode = new Node(datum);

	if (this->root == 0) {
		this->root = newNode;
		this->tail = newNode;
	}
	else {
		Node *temp = tail;
		while (temp->parent && temp->parent->left != temp) {
			temp = temp->parent;
		}
		if (temp != root) {
			if (temp->parent->right) {
				temp = temp->parent->right;
			}
			else {
				temp->parent->right = newNode;
				newNode->parent = temp->parent;// fucked up here
				this->tail = newNode;
				this->upheap(newNode);
				return;
			}
		}
		while (temp->left) {
			temp = temp->left;
		}
		temp->left = newNode;
		newNode->parent = temp;
		this->tail = newNode;
		this->upheap(newNode);
	}
}

int Heap::pop() {
	int retVal = this->root->datum;
	this->root->datum = this->tail->datum;
	Node *temp = this->tail;//fucked up here
	while (temp->parent && temp->parent->right != temp) {
		temp = temp->parent;
	}
	if (temp != root) {
		temp = temp->parent->left;
	}
	while (temp->right) {
		temp = temp->right;
	}
	//this moved from top
	if (this->tail != this->root) {
		if (this->tail->parent->left == this->tail) {
			this->tail->parent->left = 0;
		}
		else {
			this->tail->parent->right = 0;
		}
	}
	else {
		this->root = 0;
		this->tail = 0;
		delete this->tail;
		return retVal;
	}
	//end of move
	this->downheap(this->root);
	delete this->tail;
	this->tail = temp;
	return retVal;
}