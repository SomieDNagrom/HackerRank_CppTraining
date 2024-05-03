#ifndef IPEUDO_MAIN
#define IPEUDO_MAIN

#include <string>

using namespace std;

class IPseudoMain
{
private:
    string m_taskName;
public:
    IPseudoMain(string taskName)
    {
        m_taskName = taskName;
    }

    virtual string getTaskName() const
    {
        return m_taskName;
    }

    virtual int pseudo_main() = 0;
};

#endif // !IPEUDO_MAIN