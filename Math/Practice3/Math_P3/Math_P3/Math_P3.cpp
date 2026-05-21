#include <iostream>
#include <limits> 

using namespace std;

int main()
{
    int shots = 0;
    double frequency = 0.0;

    cout << "Enter shots";
    while (true)
    {
        if (cin >> shots && shots >= 0)
        {
            break;
        }
        else
        {
            cout << "Try again";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter frequency";
    while (true)
    {
        if (cin >> frequency && frequency >= 0.0 && frequency <= 1.0)
        {
            break;
        }
        else
        {
            cout << "Try again";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    int hits = static_cast<int>(frequency * shots);

    cout << "\nResult Hits / Shots: " << hits << " / " << shots << endl;

    return 0;
}