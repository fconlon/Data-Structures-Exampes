#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
	LinkedList myLL;
	
	try {
		//myLL.insert(1, 5);
		myLL.insert(0, 3);
		myLL.insert(1, 5);
		myLL.insert(1, 7);
		myLL.set(2, 13);
		myLL.remove(1);
		for (int i = 0; i < myLL.length(); i++) {
			cout << myLL.get(i) << " ";
		}
		cout << endl;
	}
	catch (const char *msg) {
		cout << msg << endl;
	}
	system("pause");
	return 0;
}