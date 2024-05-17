#include <iostream>
#include "iPseudoMain.cpp"
#include <string>
#include <set>
#include <vector>

using namespace std;

/*
Sample input:
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6
Sample output:
Yes
No
No
*/
class Task14 : virtual public IPseudoMain
{
private:
    enum MapOperationType
    {
        Add = 1,
        Remove = 2,
        Contain = 3
    };
    struct MapInfo
    {
    private:
        MapOperationType type{};
        int value = 0;
    public:
        MapInfo(MapOperationType type, int value)
        {
            this->type = type;
            this->value = value;
        }
        MapInfo(int type, int value)
        {
            switch (type)
            {
            case 1:
                this->type = MapOperationType::Add;
                break;
            case 2:
                this->type = MapOperationType::Remove;
                break;
            case 3:
                this->type = MapOperationType::Contain;
                break;
            }

            this->value = value;
        }
        MapOperationType getOperationType() const
        {
            return this->type;
        }
        int getValue() const
        {
            return this->value;
        }
    };

    vector<MapInfo*> data;
    set<int> sets;
    vector<string> results;
public:
    Task14(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter queries count: ";
        int queriesCount;
        cin >> queriesCount;

        for (int i = 0; i < queriesCount; i++)
        {
            int type = 0;
            int value = 0;
            cout << "Enter operatio type (integer) and value (integer)(space-separated): ";
            cin >> type >> value;
            data.push_back(new MapInfo(type, value));
        }

        for (int i = 0; i < data.size(); i++)
        {
            MapOperationType type = data[i]->getOperationType();
            int value = data[i]->getValue();

            switch (type)
            {
            case Task14::Add:
                sets.insert(value);
                break;
            case Task14::Remove:
                sets.erase(value);
                break;
            case Task14::Contain:
                set<int>::iterator x = sets.find(value);
                if (x == sets.end())
                {
                    results.push_back("No");
                }
                else
                {
                    results.push_back("Yes");
                }
                break;
            }
        }

        for (int i = 0; i < results.size(); i++)
        {
            cout << results[i] << endl;
        }

        cout << endl;

        data.clear();
        sets.clear();
        results.clear();

        return 0;
    }
};