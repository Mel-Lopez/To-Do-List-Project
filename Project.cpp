#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

//Task struct to store task details
struct Task { 
	string description;
	string dueDate;
	int priority;
};

/*Function adds multiple tasks to the list
User can input task description, due date and 
priority level (1-5 scale).*/
void addTasks(vector<Task>& tasks) { 
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

/* Function to display all tasks in the list
If list is empty, a message will display */
void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		cout << "No tasks found.\n";
		cout << endl;
		return;
	}

	std::cout << "Tasks:\n";
	for (const auto& task : tasks) {
		cout << "Description: " << task.description << "\n";
		cout << "Due Date: " << task.dueDate << "\n";
		cout << "Priority: " << task.priority << "\n";
		cout << "-------------------\n";
	}
}

/*Function to remove tasks from the list
User can choose task to remove by it's index 
(0 - onward) */
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
	
	//Variables storing user input and manage to-do list tasks
	char userInput;
	vector<Task> tasks; 

	//Loop to keep program running until the user chooses to quit
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
			case 'a'://Adds item to to-do list
			case 'A':
				addTasks(tasks);
				break;
			case 'v': //View and display current list
			case 'V':
				viewTasks(tasks);
				break;
			case 'r': //Removes item from to-do list
			case 'R':
				removeTasks(tasks);
				break;
			case 'q': //Ends program
			case 'Q':
				cout << "Exiting...\n";
				cout << endl;
				userInput = 'q'; //Added so that program ends if upper Q is entered
				break;
			default: //If wrong input entered
				cout << "That is not a valid input. Press 'a' for add, 'v' for view, 'r' for remove, or 'q' for quit." << endl;
				cout << endl;
				break;
			}
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << "\n";
		}
	} while (userInput != 'q'); //Program runs until 'q' is selected

	if (userInput == 'q') { //Ends program and displays goodbye message
		cout << "Thank you for using my To-do list progam. See you later!" << endl;
	}

	return 0;
}