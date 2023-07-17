#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct Task { //Task struct holds task details
	string description;
	string dueDate;
	int priority;
};


int main() {
	
	char userInput;
	vector<Task> tasks; 

	 do {

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

		cin >> userInput;

		try {
			switch (userInput) {
			case 'a'://adds item to to-do list

				break;
			case 'v': //view and siplay current list

				break;
			case 'r': //removes item from to-do list

				break;
			default: //if wrong input entered
				cout << "That is not a valid input. Press 'a' for add, 'v' for view, 'r' for remove, or 'q' for quit." << endl;
				cout << endl;
				break;
			}
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << "\n";
		}
	} while (userInput != 'q');

	if (userInput == 'q') { //ends program
		cout << "Thank you for using my To-do list progam. See you later!" << endl;
	}

	return 0;
}