#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const int MAX_TASKS = 10;
struct Task {
	string name;
	string priority;
	string deadline;
	string status;
};

void displayTasks(const Task tasks[], int numTasks) {
	cout << "\nDaily Task Planner:\n";
	cout << "--------------------\n";
	cout << "Task\t\tPriority\tDeadline\tStatus\n";
	cout << "--------------------\n";
	for (int i = 0; i < numTasks; ++i) {
		cout << tasks[i].name << "\t\t" << tasks[i].priority << "\t" << tasks[i].deadline << "\t" << tasks[i].status << endl;
	}
	cout << "--------------------\n";
}

void progressTracker(const Task tasks[], int numTasks) {
	int completedTasks = 0;
	for (int i = 0; i < numTasks; ++i) {
		if (tasks[i].status == "Completed") {
			completedTasks++;
		}
	}
	cout << "\nProgress Tracker:\n";
	cout << "--------------------\n";
	cout << "Total Tasks:     " << numTasks << endl;
	cout << "Completed Tasks: " << completedTasks << endl;
	cout << "Pending Tasks:   " << numTasks - completedTasks << endl;
	cout << "--------------------\n";
}

void addTask(Task tasks[], int& numTasks) {
	if (numTasks >= MAX_TASKS) {
		cout << "Maximum number of tasks reached." << endl;
		return;
	}

	cout << "\nEnter task name: ";
	getline(cin, tasks[numTasks].name);

	cout << "Enter priority (High, Medium, Low): ";
	cin >> tasks[numTasks].priority;
	cin.ignore();

	cout << "Enter deadline (YYYY-MM-DD): ";
	cin >> tasks[numTasks].deadline;
	cin.ignore();

	tasks[numTasks].status = "Not Started";
	numTasks++;
}

int main() {
	Task tasks[MAX_TASKS];
	int numTasks = 0;
	char choice;

	do {
		cout << "\n1. Add Task" << endl;
		cout << "2. Display Tasks" << endl;
		cout << "3. Progress Tracker" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case '1':
			addTask(tasks, numTasks);
			break;
		case '2':
			displayTasks(tasks, numTasks);
			break;
		case '3':
			progressTracker(tasks, numTasks);
			break;
		case '4':
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
		}

	} while (choice != '4');

	return 0;
}