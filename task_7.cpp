#include <iostream>
#include "iPseudoMain.cpp"

using namespace std;

class Task7 : virtual public IPseudoMain
{
private:
    int max_of_four(int a, int b, int c, int d)
    {
        return max({ a, b, c, d });
    }
public:
    Task7(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        int a, b, c, d;
        cout << "Enter numbers(a,b,c,d): " << endl;
        cin >> a >> b >> c >> d;

        cout << "Max value: " << max_of_four(a, b, c, d) << endl;

        return 0;
    }
};