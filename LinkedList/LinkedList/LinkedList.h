//LIFO->last in first out STACK
//FIFO->first in first out QUEUE

class Node {
public:
	int datum;
	Node *next, *prev;
	Node(int);
};

class LinkedList {
	Node *head, *tail;
	int size;
	void destr_helper(Node *head);
public:
	LinkedList();
	~LinkedList();
	void insert(int index, int datum);
	int remove(int index);
	int get(int index);
	void set(int index, int datum);
	int length();
};

class Stack {
	LinkedList *stack;
public:
	Stack();
	~Stack();
	void push(int);
	int pop();
	int peek();
};

class Queue {
	LinkedList *stack;
public:
	Queue();
	~Queue();
	void push(int);
	int pop();
	int peek();
};