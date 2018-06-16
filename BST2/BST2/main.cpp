#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	BST bst;
	string input;
	int num;
	while (true) {
		cout << "Enter a command\n: ";
		cin >> input ;
		try {
			if (input == "insert") {
				cin >> num;
				bst.insert(num);
			}
			else if (input == "remove") {
				cin >> num;
				bst.remove(num);
			}
			else if (input == "search") {
				cin >> num;
				if (bst.search(num)) {
					cout << num << " was found" << endl;
				}
				else {
					cout << num << " was not found" << endl;
				}
			}
			else if (input == "exit") {
				break;
			}
			else if (input == "traverse") {
				bst.traverse();
			}
			else {
				cout << "Invaild command" << endl;
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
	return 0;
}