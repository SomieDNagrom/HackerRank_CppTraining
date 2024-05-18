#include "iPseudoMain.cpp"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*

*/
class Task16 : virtual public IPseudoMain
{
public:
    Task16(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter test cases number: ";
        int testCasesCount;
        cin >> testCasesCount;

        cout << setiosflags(ios::uppercase);
        cout << setw(0xf) << internal;

        for (int i = 0; i < testCasesCount; i++)
        {
            double num1, num2, num3;
            cin >> num1 >> num2 >> num3;

            cout << left << nouppercase << showbase << hex << (long long)num1 << endl;

            cout << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << num2 << endl;

            cout << noshowpos << uppercase << scientific << setprecision(9) << num3 << endl;
        }

        return 0;
    }
};