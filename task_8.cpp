#include <iostream>
#include "iPseudoMain.cpp"
#include <numeric>
#include <cmath>

using namespace std;

class Task8 : virtual public IPseudoMain
{
private:
    void update(int* a, int* b)
    {
        int array[] = { *a, *b };
        int size = sizeof(array) / sizeof(array[0]);
        int sum = accumulate(array, array + size, 0);
        int absolute = abs(((*a) - (*b)));

        (*a) = sum;
        (*b) = absolute;
    }
public:
    Task8(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        int a, b;
        int* pa = &a, * pb = &b;

        cout << "Enter numbers (a and b): " << endl;
        cin >> a >> b;
        update(pa, pb);
        cout << "Sum: " << a << endl << "Absolute: " << b << endl;

        return 0;
    }
};