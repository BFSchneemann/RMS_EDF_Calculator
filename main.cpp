#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cstdarg>

using namespace std;

vector<uint32_t> *castArguments(int argc, char **argv)
{
    vector<uint32_t> *retVal = new vector<uint32_t>();

    for(int i = 0; i < argc; i++)
    {
        if (i != 0)
        {
            retVal->push_back(atoi(argv[i]));
        }
    }

    return retVal;
}

uint32_t lcmMultiple(vector<uint32_t> *numbers)
{
    uint32_t retVal = 0;
    int vecSize = numbers->size();

    if(vecSize > 2)
    {
        uint32_t last = numbers->back();
        numbers->pop_back();
        retVal = lcm(last, lcmMultiple(numbers));
    }
    else if (vecSize == 2)
    {
        uint32_t last = numbers->back();
        numbers->pop_back();
        retVal = lcm(last, numbers->back());
    }

    return retVal;
}



int main(int argc, char *argv[])
{
    int retVal = 0;
    vector<uint32_t> *v = castArguments(argc, argv);

    cout << lcmMultiple(v) << endl;

    return retVal;
}