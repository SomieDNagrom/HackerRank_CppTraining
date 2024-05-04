#include <iostream>
#include "iPseudoMain.cpp"
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Task10 : virtual public IPseudoMain
{
private:
    struct ArrayInfo
    {
    private:
        int size;
        vector<int> values;
    public:
        ArrayInfo(int size, vector<int> values)
        {
            this->size = size;
            this->values = values;
        }
        int getSize() const
        {
            return size;
        }
        vector<int> getValues() const
        {
            return values;
        }
        int getValue(int index)
        {
            return values.at(index);
        }
    };
    struct QueryInfo
    {
    private:
        int arrayIndex;
        int valueIndex;
    public:
        QueryInfo(int arrayIndex, int valueIndexes)
        {
            this->arrayIndex = arrayIndex;
            this->valueIndex = valueIndexes;
        }
        int getArrayIndex() const
        {
            return arrayIndex;
        }
        int getValueIndex() const
        {
            return valueIndex;
        }
    };

    int arrayCount;
    int queryCount;
    vector<ArrayInfo*> arrayInfos;
    vector<QueryInfo*> queryInfos;

    vector<int> splitStringToIntArray(const string& str, char delimiter = ' ')
    {
        vector<int> intArray;
        istringstream iss(str);

        int num;
        while (iss >> num)
        {
            intArray.push_back(num);
        }

        return intArray;
    }

    void InitializeArrayCount()
    {
        cout << "Enter array count:";
        cin >> arrayCount;
    }
    void InitializeQueryCount()
    {
        cout << "Enter query count: ";
        cin >> queryCount;
    }
    void InitializeArraysSizeAndValue()
    {
        for (int i = 0; i < arrayCount; i++)
        {
            cout << "Enter array size and array values:" << endl;
            string lInput;
            cin.ignore();
            getline(cin, lInput);

            vector<int> convertedArray = splitStringToIntArray(lInput);
            int arraySize = convertedArray[0];
            vector<int> values;
            values.insert(values.begin(), convertedArray.begin(), convertedArray.end());
            values.erase(values.begin());
            arrayInfos.push_back(new ArrayInfo(arraySize, values));
        }
    }
    void InitializeArraysIndexAndValuesIndex()
    {
        string lInput;

        for (int i = 0; i < queryCount; i++)
        {
            cout << "Enter array index and value index:" << endl;
            cin.ignore();
            getline(cin, lInput);
            vector<int> convertedArray = splitStringToIntArray(lInput);
            queryInfos.push_back(new QueryInfo(convertedArray[0], convertedArray[1]));
        }
    }
    vector<int> InitializeResults()
    {
        vector<int> results;

        for (int i = 0; i < queryInfos.size(); i++)
        {
            int arrayIndex = queryInfos[i]->getArrayIndex();
            int valueIndex = queryInfos[i]->getValueIndex();

            results.push_back(arrayInfos[arrayIndex]->getValue(valueIndex));
        }

        return results;
    }
    void PrintResult(vector<int> results)
    {
        for (int i = 0; i < results.size(); i++)
        {
            cout << results.at(i) << " ";
        }
    }
public:
    Task10(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        InitializeArrayCount();
        InitializeQueryCount();
        InitializeArraysSizeAndValue();
        InitializeArraysIndexAndValuesIndex();
        vector<int> results = InitializeResults();
        PrintResult(results);

        cout << endl;

        int temp;
        cin >> temp;

        return 0;
    }
};