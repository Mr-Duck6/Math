#include <iostream>
#include <stdexcept>

using namespace std;

class Vect
{
public:
    Vect(char);
    ~Vect() noexcept;

    int& operator [] (int i)
    {
        // Перехоплення виявлених помилок, вихід за межі масиву
        int current_size = static_cast<unsigned char>(size);
        if (i < 0 || i >= current_size)
        {
            throw out_of_range("За межами масиву");
        }
        return p[i];
    }

    void Print();
    void Destroy(); // Метод для інкапсуляції дій деструктора

private:
    int* p = nullptr;
    char size;
};

// Конструктор з обробкою винятків
Vect::Vect(char n)
{
    int actual_size = static_cast<unsigned char>(n);

    if (actual_size <= 0)
    {
        throw invalid_argument("Розмір масиву повинен бути більшим за 0");
    }
    //Запис оригіналу
    size = n;

    try
    {
        p = new int[actual_size];
        for (int i = 0; i < actual_size; ++i)
        {
            p[i] = int(); // Ініціалізація нулями
        }
    }
    catch (const bad_alloc& e)
    {
        cerr << "Перехоплено виняток базований на new у конструкторі" << e.what() << endl;
        throw;
    }
}

// Метод руйнування об'єкта
void Vect::Destroy()
{
    if (p != nullptr)
    {
        delete[] p;
        p = nullptr;
    }
    else
    {
        throw runtime_error("Спроба видалення nullptr або подвійне звільнення пам'яті");
    }
}

Vect::~Vect() noexcept
{
    try
    {
        Destroy();
    }
    catch (const exception& e)
    {
        cerr << "Оброблено переривання всередині деструктора" << e.what() << endl;
    }
}

void Vect::Print()
{
    int actual_size = static_cast<unsigned char>(size);
    for (int i = 0; i < actual_size; ++i)
        cout << p[i] << " ";
    cout << endl;
}

int main()
{

    //Стандартний робочий варіант
    try
    {
        Vect a(3);
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a.Print();
    }
    catch (const exception& e)
    {
        cerr << "Помилка об'єкта a" << e.what() << endl;
    }

    //Виправлення помилки без зміни типу
    try
    {
        Vect a1(200);
        a1[10] = 5;
        cout << "Елемент a1[10] успішно змінено на" << a1[10] << endl;
        a1[250] = 10;
    }
    catch (const out_of_range& e)
    {
        cerr << "Перехоплено помилку індексації" << e.what() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Інший виняток" << e.what() << endl;
    }

    return 0;
}