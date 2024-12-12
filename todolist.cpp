// Simple TODO List App Using C++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Maximum number of ToDo list count
const int MAX_TASKS = 100;

string fileName = "todolist.txt";

void line_separator()
{
    for (int i = 0; i <= 100; i++)
    {
        cout << "*";
    }
}
void welcome_message()
{
    cout << "\n\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Welcome to TODO List>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
    cout << " Developed By: Ishan Rijal \n \n";
}
// Function to display the menu options to the users.
void display_menu()
{
    cout << endl;
    cout << "-----------------------------------------\n";
    cout << "|Please Make Your Choice                |\n";
    cout << "|---------------------------------------|\n";
    cout << "|1. Show the task                       |\n";
    cout << "|2. Remove the Completed Task           |\n";
    cout << "|3. Enter a task to add to the list     |\n";
    cout << "|4. Quit                                |\n";
    cout << "|_______________________________________|";
}

// Function to Read the To Do list from the file
int read_todo_file(string tasks[])
{
    int totalTasksCount = 0;
    ifstream inFile(fileName);
    string task;
    while (getline(inFile, task) && totalTasksCount < MAX_TASKS)
    {
        tasks[totalTasksCount] = task;
        totalTasksCount++;
    }
    inFile.close();
    return totalTasksCount;
}

// Function to Show the To Do List
void show_tasks(string tasks[], int totalTaskCount)
{
    line_separator();
    if (totalTaskCount == 0)
    {
        cout << "\nNo task found\n";
    }
    else
    {
        cout << endl;
        cout << "List of all task:\n";
        for (int i = 0; i < totalTaskCount; i++)
        {
            cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
    line_separator();
}

// Function to write the task to the ToDo list.
void write_tasks(string tasks[], int totalTaskCount)
{
    ofstream outFile("todolist.txt");
    for (int i = 0; i < totalTaskCount; i++)
    {
        outFile << tasks[i] << "\n";
    }
    outFile.close();
}

// Function to Remove the specified task number from the list and passing variable by reference.
void remove_task(string tasks[], int &totalTaskCount)
{
    int taskNumber;
    show_tasks(tasks, totalTaskCount);
    cout << "\nEnter the task number to remove (Press '0' to quite this operation): ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > totalTaskCount)
    {
        line_separator();
        switch (taskNumber)
        {
        case 0:
            cout << "\nOperation Cancelled\n";
            break;
        default:
            cout << "\nInvalid task number\n";
            break;
        }
        line_separator();
    }
    else
    {
        cout << "Are you sure you want to remove the task \"" << tasks[taskNumber - 1] << "\"? (y/n):";
        char confirm;
        cin >> confirm;

        line_separator();
        if (confirm == 'y')
        {
            for (int i = taskNumber - 1; i < totalTaskCount - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            totalTaskCount--;
            write_tasks(tasks, totalTaskCount);
            cout << "\nTask removed Successfully\n";
        }
        else
        {
            cout << "\n Opps! Task not removed\n";
        }
        line_separator();
    }
}

// Function to Add the Task to the todoList.txt file
void add_task(string tasks[], int &totalTaskCount)
{
    cout << "Enter a task to add to the list:(Press 'q' to quite this operation)\n";
    string task;
    cin.ignore();
    getline(cin, task);
    if (task == "q")
    {
        line_separator();
        cout << "\nOperation Cancelled\n";
        line_separator();
    }
    else if (totalTaskCount < MAX_TASKS)
    {
        tasks[totalTaskCount] = task;
        totalTaskCount++;
        write_tasks(tasks, totalTaskCount);
        line_separator();
        cout << "\nYour Task added Successfully\n";
        cout << "Total Task=" << totalTaskCount << endl;
        line_separator();
    }
}

int main()
{
    string tasks[MAX_TASKS];
    int totalTaskCount = read_todo_file(tasks);
    int choice;

    line_separator();
    welcome_message();
    line_separator();
    do
    {
        display_menu();
        cout << "\nEnter Your Choice(1-4):";
        cin >> choice;
        switch (choice)
        {
        case 1:
            show_tasks(tasks, totalTaskCount);
            break;
        case 2:
            remove_task(tasks, totalTaskCount);
            break;
        case 3:
            add_task(tasks, totalTaskCount);
            break;
        case 4:
            write_tasks(tasks, totalTaskCount);
            line_separator();
            cout << "\nThank You For Using To Do List...\n";
            line_separator();
            break;
        default:
            line_separator();
            cout << "\nOpps!!!Invalid choice\n";
            cout << "Please Select Correct Options\n";
            line_separator();
            break;
        }
    } while (choice != 4);
    return 0;
}
