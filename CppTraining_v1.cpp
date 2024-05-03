#include "cppTasks.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int GetArraySize(IPseudoMain* lseudoMains[])
{
    return sizeof(pseudoMains) / sizeof(pseudoMains[0]);
}

void ShowAllTask(IPseudoMain* lseudoMains[])
{
    int arraySize = GetArraySize(pseudoMains);

    for (int i = 0; i < arraySize; i++)
    {
        cout << "[ " << i + 1 << " ]" << " " << pseudoMains[i]->getTaskName() << endl;
    }
}

void ShowExitCommand()
{
    cout << "[ " << 0 << " ]" << " " << "Exit " << endl;
}

int main()
{
    int selectedCommand = -1;

    do
    {
        system("cls");
        ShowExitCommand();
        ShowAllTask(pseudoMains);
        cout << "Select task: ";
        cin >> selectedCommand;

        if (selectedCommand == 0)
        {
            cout << "Closing..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }
        else if (selectedCommand - 1 >= 0 && selectedCommand - 1 < GetArraySize(pseudoMains))
        {
            int taskNumber = selectedCommand - 1;
            cout << pseudoMains[taskNumber]->getTaskName() << " is executing..." << endl;
            pseudoMains[taskNumber]->pseudo_main();
            cout << "Task end" << endl;
            cout << "Moving to main..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        else
        {
            cout << "Invalid input" << endl;
            cout << "Moving to main..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
    } while (selectedCommand!= 0);

    return 0;
}