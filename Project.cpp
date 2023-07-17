#include <iostream>
#include <string>

using namespace std;

int main() {
	//Main screen and instructions for user 
	cout << "          To-Do List \n";
	cout << "   Add, View, and Remove Tasks \n";
	cout << "----------------------------------------\n";
	cout << endl;
	cout << "Select from the following:" << endl;
	cout << "[a]dd task to list" << endl;
	cout << "[v]iew list" << endl;
	cout << "[r]emove task from list" << endl;
	cout << "[q]uit and leave program" << endl;
	cout << endl;

	char userInput;
	cin >> userInput;

	while (userInput != 'q') {
		cout << "Select (a)dd, (v)iew, (r)emove, or (q)uit" << endl;
		cin >> userInput;

		switch (userInput) {
		case 'a'://adds item to to-do list
			
			break;
		case 'v': 
			
			break;
		case 'r': //removes item from to-do list
			
			break;
		default:
			cout << "That is not a valid input. Press 'a' for add, 'v' for view, 'r' for remove, or 'q' for quit." << endl;
			break;
		}
	}

	if (userInput == 'q') { //ends program
		cout << "Thank you for using my To-do list progam. See you later!" << endl;
	}

	return 0;
}