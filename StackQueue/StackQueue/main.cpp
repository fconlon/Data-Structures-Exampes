#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	AStack astack;
	LStack lstack;
	Queue queue;
	string input;

	int datum;

	while (true) {
		cout << "Enter command\n: ";
		cin >> input;
		try {
			if (input == "push") {
				cin >> datum;
				queue.push(datum);
			}
			else if (input == "pop") {
				cout << queue.pop() << endl;
			}
			else if (input == "peek") {
				cout << queue.peek() << endl;
			}
			else if (input == "exit") {
				break;
			}
			else {
				cout << "Invalid command" << endl;
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
}