#include <iostream>
#include "iPseudoMain.cpp"
#include <cstdio>

using namespace std;

class Task4 : virtual public IPseudoMain
{
public:
    Task4(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        string sampleInput = "3 12345678912345 a 334.23 14049.30493";

        int intValue;
        long longValue;
        char charValue;
        float floatValue;
        double doubleValue;

#pragma warning(suppress : 4996)
        scanf("%d %ld %c %f %lf", &intValue, &longValue, &charValue, &floatValue, &doubleValue);
        printf("%d\n%ld\n%c\n%.3f\n%.9lf\n", intValue, longValue, charValue, floatValue, doubleValue);
        cout << endl;

        return 0;
    }
};