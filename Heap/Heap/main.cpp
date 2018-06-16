#include "Heap.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Heap myheap;
	string input;
	int val;
	while (true) {
		cout << "Enter a command\n: ";
		cin >> input;
		if (input == "push") {
			cin >> val;
			myheap.push(val);
		}
		else if (input == "pop") {
			cout << myheap.pop() << endl;
		}
		else if (input == "exit") {
			break;
		}
		else {
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}