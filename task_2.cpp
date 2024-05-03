#include <iostream>

#include "iPseudoMain.cpp"

using namespace std;

class Task2 : virtual public IPseudoMain
{
private:
    int calculate_sum(int a, int b)
    {
        return a + b;
    }
public:
    Task2(string taskName) : IPseudoMain(taskName) {}

    virtual int pseudo_main() override
    {
        int number1;
        int number2;

        cout << "Enter first number: ";
        cin >> number1;
        cout << "Enter second number: ";
        cin >> number2;
        cout << "Sum: ";
        cout << calculate_sum(number1, number2) << endl;

        return 0;
    }
};