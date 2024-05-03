#include <iostream>
#include "iPseudoMain.cpp"
#include <string>

using namespace std;

class Task6 : virtual public IPseudoMain
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
        if (number <= 0 || number > data[arraySize - 1]->getIntNumber())
        {
            return number % 2 == 0 ? "even" : "odd";
        }

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
    Task6(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        int numbers[2];
        int arraySize = sizeof(numbers) / sizeof(numbers[0]);

        for (int i = 0; i < arraySize; i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numbers[i];
        }

        string result;
        for (int i = numbers[0]; i <= numbers[1]; i++)
        {
            result = ConvertNumberToEnglish(i, data, sizeof(data) / sizeof(data[0]));
            cout << result << endl;
        }
        return 0;
    }
};