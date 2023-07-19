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

void addTasks(vector<Task>& tasks) { //function adds multiple tasks to list
	char userInput;
	do {
		Task newTask;
		cout << endl;
		cout << "Enter task description: ";
		cin.ignore();
		getline(cin, newTask.description);
		cout << "Enter due date: ";
		cin >> newTask.dueDate;

		while (true) {
			cout << "Enter priority level (1-5): ";
			try {
				cin >> newTask.priority;
				if (newTask.priority < 1 || newTask.priority > 5) {
					throw invalid_argument("Invalid priority level.");
				}
				break;
			}
			catch (const exception& e) {
				cout << "Error: " << e.what() << " Please try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		tasks.push_back(newTask);
		cout << "Task added successfully!\n";

		cout << "Add another task? (y/n): ";
		cin >> userInput;
	} while (userInput == 'y' || userInput == 'Y');
}

void removeTasks(vector<Task>& tasks) {
	char choice;
	do {
		if (tasks.empty()) {
			cout << "No tasks found.\n";
			cout << endl;
			return;
		}

		int taskIndex;
		cout << "Enter the index of the task to remove: ";
		cin >> taskIndex;

		try {
			if (taskIndex < 0 || taskIndex >= tasks.size()) {
				throw out_of_range("Invalid task index.");
			}

			tasks.erase(tasks.begin() + taskIndex);
			cout << "Task removed successfully!\n";
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << "\n";
		}

		cout << "Remove another task? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

int main() {
	
	char userInput;
	vector<Task> tasks; 

	 do {

		//Main screen and instructions for user 
		cout << "          To-Do List \n";
		cout << "   Add, View, and Remove Tasks \n";
		cout << "----------------------------------------\n";
		cout << endl;
		cout << "Select from the following: \n";
		cout << "[a]dd task to list \n";
		cout << "[v]iew list \n";
		cout << "[r]emove task from list \n";
		cout << "[q]uit and leave program \n";
		cout << endl;

		cin >> userInput;

		try {
			switch (userInput) {
			case 'a'://adds item to to-do list
			case 'A':
				addTasks(tasks);
				break;
			case 'v': //view and siplay current list
			case 'V':

				break;
			case 'r': //removes item from to-do list
			case 'R':
				removeTasks(tasks);
				break;
			case 'q': //ends program
			case 'Q':
				cout << "Exiting...\n";
				cout << endl;
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