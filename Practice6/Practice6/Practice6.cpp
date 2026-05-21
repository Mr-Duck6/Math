#include <iostream>
#include <iomanip>  
#include <limits>

using namespace std;

int main()
{

    double p1 = 0.0, p2 = 0.0;

    while (true) 
    {
        cout << "Enter p1  0 or 1: ";
        if (cin >> p1 && p1 >= 0.0 && p1 <= 1.0) break;
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) 
    {
        cout << "Enter p2  0 or 1): ";
        if (cin >> p2 && p2 >= 0.0 && p2 <= 1.0) break;
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double q1 = 1.0 - p1;
    double q2 = 1.0 - p2;

    double P0 = q1 * q2;
    double P1 = (p1 * q2) + (q1 * p2);
    double P2 = p1 * p2;

    double sumCheck = P0 + P1 + P2;

    cout << "Z | 0 | 1 | 2 |" << endl;
 
    cout << " P | "
        << fixed << setprecision(3)
        << setw(7) << P0 << " | "
        << setw(7) << P1 << " | "
        << setw(7) << P2 << " |" << endl;


    double probabilities[3] = { P0, P1, P2 };
    for (double level = 0.6; level > 0.0; level -= 0.1) 
    {
        cout << fixed << setprecision(1) << level << "|";
        for (int i = 0; i < 3; i++) {
            if (probabilities[i] >= level - 0.02)
            {
                cout << "    * ";
            }
            else {
                cout << "         ";
            }
        }
        cout << endl;
    }
    cout << "0.0+------------------------->" << endl;
    cout << "    Z = 0    Z = 1    Z = 2" << endl;

    return 0;
}