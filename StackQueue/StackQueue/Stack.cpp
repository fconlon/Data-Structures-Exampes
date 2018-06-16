#include "Stack.h"

Node::Node(int datum) {
	this->next = 0;
	this->prev = 0;
	this->datum = datum;
}
///////////////LINKED LIST STACK///////////////
LStack::LStack() {
	this->head = 0;
}

void LStack::destr_helper(Node *node) {
	if (node) {
		this->destr_helper(node->next);
		delete node;
	}
}

LStack::~LStack() {
	this->destr_helper(this->head);
}

void LStack::push(int datum) {
	Node *newNode = new Node(datum);
	newNode->next = this->head;
	this->head = newNode;
}

int LStack::pop() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	int datum = this->head->datum;
	Node *remNode = this->head;
	this->head = remNode->next;
	delete remNode;
	return datum;
}

int LStack::peek() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	return this->head->datum;
}

bool LStack::empty() {
	return !this->head;
}
///////////////ARRAY LIST STACK///////////////
AStack::AStack() {
	this->size = 10;
	this->head = new int[this->size];
	this->curr = 0;
}

AStack::~AStack() {
	delete this->head;
}

void AStack::push(int datum) {
	if (this->curr == this->size) {
		this->size *= 2;
		int *newArr = new int[this->size];
		for (int i = 0; i < this->size / 2; i++) {
			newArr[i] = this->head[i];
		}
		delete this->head;
		this->head = newArr;
	}
	this->head[this->curr] = datum;
	this->curr++;
}

int AStack::pop() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	this->curr--;
	return this->head[this->curr];
}

int AStack::peek() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	return this->head[this->curr-1];
}

bool AStack::empty() {
	return !this->curr;
}
///////////////LINKED LIST QUEUE///////////////
Queue::Queue() {
	this->head = 0;
	this->tail = 0;
}

void Queue::destr_helper(Node *node) {
	if (node) {
		this->destr_helper(node->next);
		delete node;
	}
}

Queue::~Queue() {
	this->destr_helper(this->head);
}

void Queue::push(int datum) {
	Node *newNode = new Node(datum);
	newNode->next = this->head;
	if (this->head) {
		this->head->prev = newNode;
	}
	this->head = newNode;
	if (!this->tail) {
		this->tail = newNode;
	}
}

int Queue::pop() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	int datum = this->tail->datum;
	Node *remNode = this->tail;
	this->tail = remNode->prev;
	if (this->tail) {
		this->tail->next = 0;
	}
	else {
		this->head = 0;
	}
	delete remNode;
	return datum;
}

int Queue::peek() {
	if (this->empty()) {
		throw "Stack is empty";
	}
	return this->tail->datum;
}

bool Queue::empty() {
	return !this->head;
}