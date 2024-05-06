#include <iostream>
#include "iPseudoMain.cpp"
#include <vector>
#include <string>

using namespace std;

class Task10 : virtual public IPseudoMain
{
private:
    int arrayCount = 0;
    int queryCount = 0;
    vector<vector<int>> array = {};
    vector<int> rows = {};
    vector<int> columns = {};

    void printResult(vector<vector<int>> results, int row, int column)
    {
        cout << results[row][column] << endl;
    }
    void initializeArrayCountAndQuery()
    {
        cin >> arrayCount >> queryCount;
    }
    void initializeArraysSizeAndValue()
    {
        array.resize(arrayCount);
        int lArrayColumnCount;

        for (int i = 0; i < arrayCount; i++)
        {
            cin >> lArrayColumnCount;

            array[i].resize(lArrayColumnCount);

            for (int j = 0; j < lArrayColumnCount; j++)
            {
                cin >> array[i][j];
            }
        }
    }
    void initializeArraysIndexAndValuesIndex()
    {
        int row;
        int column;

        for (int i = 0; i < queryCount; i++)
        {
            cin >> row >> column;
            rows.push_back(row);
            columns.push_back(column);
        }
    }
public:
    Task10(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        initializeArrayCountAndQuery();
        initializeArraysSizeAndValue();
        initializeArraysIndexAndValuesIndex();

        for (int i = 0; i < rows.size(); i++)
        {
            printResult(array, rows[i], columns[i]);
        }

        cout << endl;
        return 0;
    }
};