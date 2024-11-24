#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }

        cout << "To-Do List:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i].description
                 << " ["
                 << (tasks[i].isCompleted ? "Completed" : "Pending")
                 << "]" << endl;
        }
    }

    void markTaskAsCompleted(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
    }

    void removeTask(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
};

int main() {
    ToDoList myList;
    int choice;
    int taskNumber;
    string taskDescription;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to ignore the newline character after the choice input

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                myList.addTask(taskDescription);
                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                myList.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                myList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting To-Do List Manager..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

