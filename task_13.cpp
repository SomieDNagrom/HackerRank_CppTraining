#include <iostream>
#include "iPseudoMain.cpp"
#include <string>
#include <vector>

using namespace std;

/*
Sample input:
 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
Sample output:
 Yes 1
 No 5
 Yes 6
 Yes 8
*/
class Task13 : virtual public IPseudoMain
{
public:
    Task13(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter integer array size: ";
        int arraySize;
        cin >> arraySize;

        cout << "Enter intergers in sorted order (separated by space): ";
        vector<int> array;
        int input;

        for (int i = 0; i < arraySize; i++)
        {
            cin >> input;
            array.push_back(input);
        }

        cout << "Enter queries count: ";
        int queriesCount;
        cin >> queriesCount;

        vector<int> queriesValue;
        int queryValueInput;

        cout << "Enter query values:" << endl;

        for (int i = 0; i < queriesCount; i++)
        {
            cout << "Enter integer value: ";
            cin >> queryValueInput;
            queriesValue.push_back(queryValueInput);
        }

        for (int i = 0; i < queriesCount; i++)
        {
            int queryValue = queriesValue[i];
            vector<int>::iterator result = lower_bound(array.begin(), array.end(), queryValue);

            int resultIndex = distance(array.begin(), result);

            if (*result == queryValue)
            {
                cout << "Result: " << "Yes " << resultIndex + 1 << endl;
            }
            else
            {
                cout << "Result: " << "No " << resultIndex + 1 << endl;
            }
        }

        cout << endl;

        return 0;
    }
};