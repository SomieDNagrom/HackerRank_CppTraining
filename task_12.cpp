#include <iostream>
#include "iPseudoMain.cpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Task12 : virtual public IPseudoMain
{
public:
    Task12(string taskName) : IPseudoMain(taskName)
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

        cout << "Enter index to erase: ";
        int indexToErase;
        cin >> indexToErase;

        cout << "Enter index (from and to) to erase: ";
        int from;
        int to;
        cin >> from >> to;

        numbers.erase(numbers.begin() + indexToErase - 1);
        numbers.erase(numbers.begin() + from - 1, numbers.begin() + to - 1);

        cout << "New size: " << numbers.size() << endl;

        for (int i = 0; i < numbers.size(); i++)
        {
            cout << numbers[i] << " ";
        }

        cout << endl;

        return 0;
    }
};