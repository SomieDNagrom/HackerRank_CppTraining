#include <iostream>
#include "iPseudoMain.cpp"

using namespace std;

class Task3 : virtual public IPseudoMain
{
public:
    Task3(string taskName) : IPseudoMain(taskName) {}

    virtual int pseudo_main() override
    {
        int a;
        int b;
        int c;
        int sum;

        cout << "Enter 3 space-separated integers: " << endl;
        cin >> a >> b >> c;

        cout << "Sum: " << (sum = a + b + c) << endl;

        return 0;
    }
};