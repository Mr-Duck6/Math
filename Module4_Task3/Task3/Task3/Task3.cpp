#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class Matrix 
{
private:
    T** data;
    size_t rows;
    size_t cols;

    //Метод для виділення пам'яті
    void allocate(size_t r, size_t c)
    {
        rows = r;
        cols = c;
        if (r == 0 || c == 0)
        {
            data = nullptr;
            return;
        }
        data = new T * [rows];
        for (size_t i = 0; i < rows; ++i) 
        {
            data[i] = new T[cols]();
        }
    }

    //Метод для очищення пам'яті
    void clear()
    {
        if (data != nullptr) 
        {
            for (size_t i = 0; i < rows; ++i) 
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
        rows = 0;
        cols = 0;
    }

public:
    Matrix(size_t r = 0, size_t c = 0) 
    {
        allocate(r, c);
    }

     
    Matrix(const Matrix& other) 
    {
        allocate(other.rows, other.cols);
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    ~Matrix()
    {
        clear();
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            clear();
            allocate(other.rows, other.cols);
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    T* operator[](size_t index) { return data[index]; }
    const T* operator[](size_t index) const { return data[index]; }


    Matrix copyByRows() const 
    {
        return Matrix(*this);
    }

    //Копіювання за стовпцями
    Matrix copyByCols() const 
    {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    //Копіювання вибраного рядка
    Matrix copyRow(size_t rowIndex) const 
    {
        if (rowIndex >= rows) 
        {
            throw std::out_of_range("Індекс рядка виходить за межі");
        }
        Matrix result(1, cols);
        for (size_t j = 0; j < cols; ++j)
        {
            result.data[0][j] = data[rowIndex][j];
        }
        return result;
    }

    //Копіювання вибраного стовпчика
    Matrix copyCol(size_t colIndex) const 
    {
        if (colIndex >= cols)
        {
            throw out_of_range("Індекс стовпчика виходить за межі");
        }
        Matrix result(rows, 1);
        for (size_t i = 0; i < rows; ++i) 
        {
            result.data[i][0] = data[i][colIndex];
        }
        return result;
    }

    //Копіювання головної діагоналі
    Matrix copyMainDiagonal() const 
    {
        size_t minDim = (rows < cols) ? rows : cols;
        Matrix result(1, minDim);
        for (size_t i = 0; i < minDim; ++i)
        {
            result.data[0][i] = data[i][i];
        }
        return result;
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& matrix) 
    {
        for (size_t i = 0; i < matrix.rows; ++i) 
        {
            for (size_t j = 0; j < matrix.cols; ++j) 
            {
                out << matrix.data[i][j] << "\t";
            }
            out << "\n";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Matrix<T>& matrix)
    {
        for (size_t i = 0; i < matrix.rows; ++i) 
        {
            for (size_t j = 0; j < matrix.cols; ++j) 
            {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }
};

int main() 
{

    size_t r = 3, c = 4;
    Matrix<int> myMatrix(r, c);

    cout << "Введіть елементи матриці 3х4\n";
    cin >> myMatrix;

    cout << myMatrix;

    Matrix<int> rowCopy = myMatrix.copyByRows();
    cout << rowCopy;

    Matrix<int> colCopy = myMatrix.copyByCols();
    cout << colCopy;

    Matrix<int> singleRow = myMatrix.copyRow(1);
    cout << singleRow;

    Matrix<int> singleCol = myMatrix.copyCol(2);
    cout << singleCol;

    Matrix<int> diag = myMatrix.copyMainDiagonal();
    cout  << diag;

    return 0;
}