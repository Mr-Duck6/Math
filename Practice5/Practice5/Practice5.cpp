#include <iostream>
#include <cmath>     
#include <limits>    

using namespace std;


double laplaceFunction(double x) 
{
    return 0.5 * erf(x / sqrt(2.0));
}

int main() 
{

    int n = 0;          
    double p = 0.0;     
    int k1 = 0;         
    int k2 = 0;         

    while (true) 
    {
        cout << "Enter n: ";
        if (cin >> n && n > 0) break;
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true)
    {
        cout << "Enter p = 0 or 1: ";
        if (cin >> p && p >= 0.0 && p <= 1.0) break;
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) 
    {
        cout << "Enter k, no more than k ";
        if (cin >> k2 && k2 >= 0 && k2 <= n) break;
        cout << "Error" << n << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    double q = 1.0 - p;
    double np = n * p;
    double npq = n * p * q;
    double sigma = sqrt(npq);

    if (npq <= 9.0) 
    {
        cout << "\n " << npq << "less accuracy" << endl;
    }

    double x1 = (k1 - np) / sigma;
    double x2 = (k2 - np) / sigma;

    double probability = laplaceFunction(x2) - laplaceFunction(x1);

    if (probability < 0) probability = 0;

    cout << "np" << np << endl;
    cout << "npq: " << npq << endl;
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;
    cout << "Ф x1: " << laplaceFunction(x1) << endl;
    cout << "Ф x2: " << laplaceFunction(x2) << endl;
    cout << " P(0 <= k <= " << k2 << ") = " << probability << endl;


    return 0;
}