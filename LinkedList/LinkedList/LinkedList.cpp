#include "LinkedList.h"

Node::Node(int datum) {
	this->datum = datum;
	this->next = 0;
	this->prev = 0;
}

LinkedList::LinkedList() {
	this->head = 0;
	this->tail = 0;
	this->size = 0;
}

void LinkedList::destr_helper(Node *node) {
	if (node) {
		this->destr_helper(node->next);
		delete node;
	}
}

LinkedList::~LinkedList() {
	this->destr_helper(this->head);
}

void LinkedList::insert(int index, int datum) {
	if (index < 0 || index > this->size) {
		throw "Invalid index";
	}

	Node *newNode = new Node(datum);
	if (index == 0) {
		newNode->next = this->head;
		if (this->head) {
			this->head->prev = newNode;
		}
		this->head = newNode;
		if (!tail) {
			this->tail = newNode;
		}
	}
	else if (index == this->size) {
		newNode->prev = this->tail;
		this->tail->next = newNode;
		this->tail = newNode;
	}
	else {
		Node *temp = this->head;
		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		newNode->next->prev = newNode;
	}
	this->size++;
}

int LinkedList::remove(int index){
	if (index < 0 || index >= this->size) {
		throw "Invalid index";
	}

	int datum;
	Node *remNode;
	if (index == 0) {
		remNode = this->head;
		this->head = this->head->next;
		if (this->head) {
			this->head->prev = 0;
		}
		else {
			this->tail = 0;
		}
	}
	else if (index == this->size - 1) {
		remNode = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = 0;
	}
	else {
		Node *temp = this->head;
		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}
		remNode = temp->next;
		temp->next = remNode->next;
		remNode->next->prev = remNode->prev;
	}
	this->size--;
	datum = remNode->datum;
	delete remNode;
	return datum;
}

int LinkedList::get(int index) {
	if (index < 0 || index >= this->size) {
		throw "Invalid index";
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}

	return temp->datum;
}

void LinkedList::set(int index, int datum) {
	if (index < 0 || index >= this->size) {
		throw "Invalid index";
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}

	temp->datum = datum;
}

int LinkedList::length() {
	return this->size;
}

Stack::Stack() {
	this->stack = new LinkedList;
}

Stack::~Stack() {
	delete this->stack;
}

void Stack::push(int datum) {
	stack->insert(0, datum);
}

int Stack::pop() {
	return stack->remove(0);
}

int Stack::peek() {
	return stack->get(0);
}

Queue::Queue() {
	this->stack = new LinkedList;
}

Queue::~Queue() {
	delete this->stack;
}

void Queue::push(int datum) {
	stack->insert(stack->length(), datum);
}

int Queue::pop() {
	return stack->remove(0);
}

int Queue::peek() {
	return stack->get(0);
}