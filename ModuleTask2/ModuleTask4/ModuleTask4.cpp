#include <iostream>
using namespace std;

class ClassCounter 
{
private:
    int minval; 
    int maxval;
    int current;

public:

    ClassCounter(int min_v, int max_v)
    {
        minval = min_v;
        maxval = max_v;
        current = min_v;
    }

    void funcIncrement()
    {
        if (current >= maxval)
        {
            current = minval;
        }
        else 
        {
            current++;
        }
    }

    int funcGetValue() 
    {
        return current;
    }
};

int main()
{
    ClassCounter obj(1, 3);

    cout << obj.funcGetValue() << endl; 

    obj.funcIncrement();
    cout << obj.funcGetValue() << endl; 

    obj.funcIncrement();
    cout << obj.funcGetValue() << endl;

    obj.funcIncrement();
    cout << obj.funcGetValue() << endl;

    return 0;
}