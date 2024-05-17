#include <iostream>
#include "iPseudoMain.cpp"
#include <string>
#include <map>
#include <utility>

using namespace std;

/*
Sample input:
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
Sample output:
30
20
0
*/
class Task15 : virtual public IPseudoMain
{
private:
    map<string, int> m;

    void add(pair<string, int> p)
    {
        m[p.first] += p.second;
    }

    void remove(pair<string, int> p)
    {
        m.erase(p.first);
    }

    void display(pair<string, int> p)
    {
        cout << m[p.first] << endl;
    }
public:
    Task15(string taskName) : IPseudoMain(taskName)
    {}

    virtual int pseudo_main() override
    {
        cout << "Enter queries count: ";
        int queriesCount;
        cin >> queriesCount;

        while (queriesCount--)
        {
            int y;
            pair<string, int> p;
            cin >> y;

            switch (y)
            {
            case 1:
                cin >> p.first >> p.second;
                add(p);
                break;
            case 2:
                cin >> p.first;
                p.second = 0;
                remove(p);
                break;
            case 3:
                cin >> p.first;
                p.second = 0;
                display(p);
                break;
            }
        }

        return 0;
    }
};