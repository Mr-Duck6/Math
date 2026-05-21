#include <iostream>
#include <cmath>     
#include <limits>    

using namespace std;

int main() 
{


    const int SIZE = 4;
    double x[SIZE] = { 0.0 };
    double p[SIZE] = { 0.0 };

    for (int i = 0; i < SIZE; i++) 
    {
        while (true) 
        {
            cout << "Enter x[" << i + 1 << "]: ";
            if (cin >> x[i]) break;
            cout << "Error" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true) 
    {
        double sum_p = 0.0;
        for (int i = 0; i < SIZE; i++) 
        {
            while (true) 
            {
                cout << "Enter p[" << i + 1 << "]  0 оr 1 ";
                if (cin >> p[i] && p[i] >= 0.0 && p[i] <= 1.0) {
                    sum_p += p[i];
                    break;
                }
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (abs(sum_p - 1.0) < 1e-5) 
        {
            break;
        }
        else 
        {
            cout << "Error" << endl;
        }
    }

    double M_X = 0.0;  
    double M_X2 = 0.0;

    for (int i = 0; i < SIZE; i++) 
    {
        M_X += x[i] * p[i];
        M_X2 += (x[i] * x[i]) * p[i];
    }

    double D_X = M_X2 - (M_X * M_X);
    double sigma = sqrt(D_X);

    cout << "M(X) = " << M_X << endl;
    cout << " M(X^2) = " << M_X2 << endl;
    cout << "D(X) = " << D_X << endl;
    cout << " sigma(X) = " << sigma << endl;

    return 0;
}