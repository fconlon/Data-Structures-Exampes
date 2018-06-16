class BST {
	class Node {
	public:
		Node *left, *right, *parent;
		int datum;
		Node(int);
	};
	Node *root;
	void destr_helper(Node*);
	void in_order(Node*);
public:
	BST();
	~BST();
	void insert(int);
	void recur_insert(int);
	void rec_inst_helper(Node*, Node*);
	void remove(int);
	Node* search(int);
	void traverse();
};
