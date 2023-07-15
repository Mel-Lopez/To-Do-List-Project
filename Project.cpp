#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	cout << "          To-Do List \n";
	cout << "   Add, View, and Remove Tasks \n";
	cout << "----------------------------------------\n";
	cout << endl;
	cout << endl;
	cout << "Select (a)dd, (v)iew, (r)emove, or (q)uit" << endl;

	char userInput;
	cin >> userInput;

	while (userInput != 'q') {
		cout << "Select (a)dd, (v)iew, (r)emove, or (q)uit" << endl;
		cin >> userInput;

		switch (userInput) {
		case 'a':
			//adds item to to-do list
			break;
		case 'v':
			//views to-do list
			break;
		case 'r':
			//removes item from to-do list
			break;
		default:
			cout << "That is not a valid input. Press 'a' for add, 'v' for view, 'r' for remove, or 'q' for quit." << endl;
			break;
		}
	}

	if (userInput == 'q') {
		cout << "Thank you using my To-do list. See you later!" << endl;
	}

	system("pause");
	return 0;
}