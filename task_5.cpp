#include <iostream>
#include "iPseudoMain.cpp"
#include <string>

using namespace std;

class Task5 : virtual public IPseudoMain
{
private:
    struct Data
    {
    private:
        int intNumber;
        string stringNumber;

    public:
        Data(int number, string inEnglish)
        {
            intNumber = number;
            stringNumber = inEnglish;
        }
        int getIntNumber() const
        {
            return intNumber;
        }
        string getStringNumber() const
        {
            return stringNumber;
        }
    };

    Data* data[9] =
    {
        new Data(1, "one"),
        new Data(2, "two"),
        new Data(3, "three"),
        new Data(4, "four"),
        new Data(5, "five"),
        new Data(6, "six"),
        new Data(7, "seven"),
        new Data(8, "eight"),
        new Data(9, "nine"),
    };

    string ConvertNumberToEnglish(int number, Data* data[], int arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (number == data[i]->getIntNumber())
            {
                return data[i]->getStringNumber();
            }
        }

        return "";
    }
public:
    Task5(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        int userNumber;
        cout << "Enter number(1-" << (sizeof(data) / sizeof(data[0])) << "):";
        cin >> userNumber;

        if (userNumber <= 0)
        {
            cout << "Invalid number" << endl;
            return 0;
        }
        else if (userNumber > (sizeof(data) / sizeof(data[0])))
        {
            cout << "Greater than " << ((sizeof(data) / sizeof(data[0]))) << endl;
            return 0;
        }

        string result = ConvertNumberToEnglish(userNumber, data, ((sizeof(data) / sizeof(data[0]))));

        cout << "In English: " << result << endl;

        return 0;
    }
};