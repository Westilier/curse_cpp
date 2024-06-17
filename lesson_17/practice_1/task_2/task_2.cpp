#include <iostream>


void AddColInMatrixStart(size_t** arr, size_t& cols, size_t& rows)//фунция из задания
{
    rows += 1;
    arr[rows - 1] = new size_t[cols];

    for (size_t i = rows - 1; i > 0; --i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            arr[i][j] = arr[i - 1][j];
        }
    }
    for (size_t i = 0; i < cols; ++i)
    {
        arr[0][i] = 0;
    }
}

void OutputMatrix(size_t** arr, size_t& cols, size_t& rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void InitializationMatrix(size_t** arr, size_t& cols, size_t& rows)
{
    size_t x = 1;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            arr[i][j] = x++;
        }
    }
}

int main()
{
    size_t rows = 5;
    size_t cols = 5;
    size_t** array = new size_t * [cols];
    for (size_t i = 0; i < cols; i++)
    {
        array[i] = new size_t[rows];
    }

    InitializationMatrix(array, cols, rows);

    OutputMatrix(array, cols, rows);

    AddColInMatrixStart(array, cols, rows);

    OutputMatrix(array, cols, rows);

    return 0;
}