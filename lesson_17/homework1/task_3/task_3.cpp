#include <iostream>


void CyclicShiftTwiceArrayToRight(size_t** arr, size_t cols, size_t rows)
{
    size_t temp;
    for (size_t i = 0; i < rows; ++i)
    {
        temp = arr[i][cols - 1];
        for (size_t j = cols - 1; j > 0; --j)
        {
            arr[i][j] = arr[i][j - 1];
        }
        arr[i][0] = temp;
    }
}

void CyclicShiftTwiceArrayToLeft(size_t** arr, size_t cols, size_t rows)
{
    size_t temp;
    for (size_t i = 0; i < rows; ++i)
    {
        temp = arr[i][0];
        for (size_t j = 0; j < cols; ++j)
        {
            arr[i][j] = arr[i][j + 1];
        }
        arr[i][cols - 1] = temp;
    }
}

void CyclicShiftTwiceArrayToUp(size_t** arr, size_t cols, size_t rows)
{
    size_t temp;
    for (size_t j = 0; j < cols; ++j)
    {
        temp = arr[0][j];
        for (size_t i = 0; i < rows - 1; ++i)
        {
            arr[i][j] = arr[i + 1][j];
        }
        arr[rows - 1][j] = temp;
    }
}

void CyclicShiftTwiceArrayToDown(size_t** arr, size_t cols, size_t rows)
{
    size_t temp;
    for (size_t j = 0; j < cols; ++j)
    {
        temp = arr[rows - 1][j];
        for (size_t i = rows - 1; i > 0; --i)
        {
            arr[i][j] = arr[i - 1][j];
        }
        arr[0][j] = temp;
    }
}

void CyclicShiftTwiceArray(size_t** arr, size_t& cols, size_t& rows, size_t times, char side)
{
    while (times != 0) {
        switch (side)
        {
        case 'R':
            CyclicShiftTwiceArrayToRight(arr, cols, rows);
            break;
        case 'L':
            CyclicShiftTwiceArrayToLeft(arr, cols, rows);
            break;
        case 'U':
            CyclicShiftTwiceArrayToUp(arr, cols, rows);
            break;
        case 'D':
            CyclicShiftTwiceArrayToDown(arr, cols, rows);
            break;
        }
        times--;
    }
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

    CyclicShiftTwiceArray(array, cols, rows, 2, 'L');

    OutputMatrix(array, cols, rows);

    return 0;
}