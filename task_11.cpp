#include <iostream>
#include "iPseudoMain.cpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Task11 : virtual public IPseudoMain
{
public:
    Task11(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter numbers count: ";
        int numbersCount;
        cin >> numbersCount;

        cout << "Enter numbers: ";
        vector<int> numbers;
        int input;

        for (int i = 0; i < numbersCount; i++)
        {
            cin >> input;

            numbers.push_back(input);
        }

        cout << "Sorted array: ";
        sort(numbers.begin(), numbers.end());

        for (int i = 0; i < numbersCount; i++)
        {
            cout << numbers[i] << " ";
        }

        cout << endl;

        return 0;
    }
};