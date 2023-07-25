#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

//Task struct to store task details
struct Task { 
	string description;
	string dueDate;
	int priority = 0; //Initializing due to warning to not have garbage data and to avoid unpredictable behavior
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
		cout << endl; //whitespace between message and user input
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
			cout << endl; //whitespace between message and user input
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
				cout << endl; //whitespace between message and user input
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

/*Sample output
		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

p

That is not a valid input. Press 'a' for add, 'v' for view, 'r' for remove, or 'q' for quit.

		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

v

No tasks found.

		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

r

No tasks found.

		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

a

Enter task description: Go for a walk
Enter due date: today
Enter priority level (1-5): 5
Task added successfully!
Add another task? (y/n): y

Enter task description: Clean house
Enter due date: today
Enter priority level (1-5): 1
Task added successfully!
Add another task? (y/n): y

Enter task description: Be a millionaire
Enter due date: tomorrow
Enter priority level (1-5): 2
Task added successfully!
Add another task? (y/n): n
		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

v
Tasks:
Description: Go for a walk
Due Date: today
Priority: 5
-------------------
Description: Clean house
Due Date: today
Priority: 1
-------------------
Description: Be a millionaire
Due Date: tomorrow
Priority: 2
-------------------
		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

r
Enter the index of the task to remove: 5
Error: Invalid task index.
Remove another task? (y/n): y
Enter the index of the task to remove: 2
Task removed successfully!
Remove another task? (y/n): n
		  To-Do List
   Add, View, and Remove Tasks
----------------------------------------

Select from the following:
[a]dd task to list
[v]iew list
[r]emove task from list
[q]uit and leave program

Q
Exiting...

Thank you for using my To-do list progam. See you later!

C:\Users\melvi\source\repos\C++ Project\x64\Debug\C++ Project.exe (process 35616) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/