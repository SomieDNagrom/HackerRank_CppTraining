#include <iostream>
#include <string>

#include "iPseudoMain.cpp"

using namespace std;

class Task1 : virtual public IPseudoMain
{
private:
    string name;

    string get_user_name()
    {
        cout << "What's your name?\n";
        cout << "your name: ";
        string temp_name;
        cin >> temp_name;

        return temp_name;
    }
    void say_hello_world()
    {
        name = get_user_name();
        cout << name << " said: " << "\"Hello, World!\"\n";
    }
public:
    Task1(string taskName) : IPseudoMain(taskName){}

    virtual int pseudo_main() override
    {
        say_hello_world();

        return 0;
    }
};