#include <iostream>
#include <vector>


using Matrix = std::vector<std::vector<size_t>>;

Matrix InizialitionMatrix(size_t SIZE_1, size_t SIZE_2)
{
    Matrix matrix(SIZE_1, std::vector<size_t>(SIZE_2));
    for (size_t i = 0; i < SIZE_1; ++i)
    {
        for (size_t j = 0; j < SIZE_2; ++j)
        {
            matrix[i][j] = i * SIZE_2 + j;
        }
    }
    return matrix;
}

void OutputMatrix(Matrix& matrix, size_t SIZE_1, size_t SIZE_2)
{
    for (size_t i = 0; i < SIZE_1; ++i)
    {
        for (size_t j = 0; j < SIZE_2; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix transposition(Matrix& matrix, size_t& SIZE_1, size_t& SIZE_2)
{
    Matrix resultMatrix(SIZE_2, std::vector<size_t>(SIZE_1));
    for (size_t i = 0; i < SIZE_1; ++i)
    {
        for (size_t j = 0; j < SIZE_2; ++j)
        {
            resultMatrix[j][i] = matrix[i][j];
        }
    }
    return resultMatrix;
}

int main()
{
    size_t SIZE_1 = 100;
    size_t SIZE_2 = 10;
    Matrix matrix = InizialitionMatrix(SIZE_1,SIZE_2);

    OutputMatrix(matrix, SIZE_1, SIZE_2);

    Matrix matrix_new = transposition(matrix, SIZE_1, SIZE_2);

    OutputMatrix(matrix_new, SIZE_2, SIZE_1);
}
