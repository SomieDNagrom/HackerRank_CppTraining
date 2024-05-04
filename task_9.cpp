#include <iostream>
#include "iPseudoMain.cpp"
#include <vector>

using namespace std;

class Task9 : virtual public IPseudoMain
{
public:
    Task9(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter numbers count: ";
        int numbersCount;
        cin >> numbersCount;

        cout << "Enter numbers (space-separated):" << endl;
        vector<int> numbers(numbersCount);

        for (int i = 0; i < numbers.size(); i++)
        {
            cin >> numbers[i];
        }

        cout << "You entered: " << endl;
        for (int i = 0; i < numbers.size(); i++)
        {
            cout << "[ " << i << ": " << numbers[i] << " ]";
        }

        cout << endl;
        cout << "Reversed: " << endl;
        reverse(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size(); i++)
        {
            cout << "[ " << i << ": " << numbers[i] << " ]";
        }

        return 0;
    }
};