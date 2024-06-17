#include <iostream>


void DelColInMatrix(size_t** arr, size_t& cols, size_t rows, size_t position)//фунция из задания
{
    for (size_t i = position; i < cols - 1; ++i)
    {
        for (size_t j = 0; j < rows; ++j)
        {
            arr[j][i] = arr[j][i + 1];
        }
    }
    cols -= 1;
}

void OutputMatrix(size_t** arr, size_t cols, size_t rows)
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

void InitializationMatrix(size_t** arr, size_t cols, size_t rows)
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

    size_t position = 3;
    DelColInMatrix(array, cols, rows, position);

    OutputMatrix(array, cols, rows);

    return 0;
}
