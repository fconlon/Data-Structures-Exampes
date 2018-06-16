class Heap {
	class Node {
	public:
		Node * left, *right, *parent;
		int datum;
		Node(int);
	};
	Node *root, *tail;
	void upheap(Node*);
	void downheap(Node*);
	void destr_helper(Node*);
public:
	Heap();
	~Heap();
	void push(int);
	int pop();
};