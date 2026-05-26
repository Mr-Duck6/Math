#include <iostream>
#include <cstdarg> 

using namespace std;

//Перевантаження функції
int& Sum(int& first, int second) 
{
    first = first + second;
    return first;
}

int* sumOverload(int* first, int second, int third)
{
    if (first) 
    {
        *first = *first + second + third;
    }
    return first;
}


//Конструктор за замовчуванням
int& sumDefault(int& first, int b = 0, int c = 0, int d = 0, int e = 0)
{
    first = first + b + c + d + e;
    return first;
}


//Зміна кількості параметрів
int& Variadic(int& first, int count, ...)
{
    va_list numbers;
    va_start(numbers, count);

    for (int i = 0; i < count; ++i) 
    {
        first += va_arg(numbers, int);
    }

    va_end(numbers);
    return first;
}


int* VariadicPtr(int* first, int count, ...)
{
    if (!first) return nullptr;

    va_list numbers;
    va_start(numbers, count);

    for (int i = 0; i < count; ++i) 
    {
        *first += va_arg(numbers, int);
    }

    va_end(numbers);
    return first;
}


int main()
{

    int a1 = 10;
    int& Result = Sum(a1, 5);
    cout << a1 << Result << "\n";

    int a2 = 10;
    int* ResultPtr = sumOverload(&a2, 5, 20);
    cout << a2 << *ResultPtr << "\n";



    int b1 = 10;
    sumDefault(b1, 5);
    cout << b1 << "\n";

    int b2 = 10;
    Variadic(b2, 5, 15, 20);
    cout <<  b2 << "\n";


    int c1 = 10;
    Variadic(c1, 3, 10, 20, 30);
    cout << c1 << "\n";

    int c2 = 10;
    int* ResultPtr2 = VariadicPtr(&c2, 4, 5, 5, 5, 5);
    cout << c2 << *ResultPtr2 << "\n";

    return 0;
}