class Node {
public:
	int datum;
	Node *next, *prev;
	Node(int);
};

class LStack {
	Node *head;
	void destr_helper(Node*);
public:
	LStack();
	~LStack();
	void push(int);
	int pop();
	int peek();
	bool empty();
};

class AStack {
	int *head, curr, size;
public:
	AStack();
	~AStack();
	void push(int);
	int pop();
	int peek();
	bool empty();
};

class Queue {
	Node *head, *tail;
	void destr_helper(Node*);
public:
	Queue();
	~Queue();
	void push(int);
	int pop();
	int peek();
	bool empty();
};