#include <iostream>
#include <vector>


using Matrix = std::vector<std::vector<int>>;

Matrix InizialitionMatrix(size_t rows, size_t cols)
{
    Matrix matrix(rows, std::vector<int>(cols));
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            if (rand() % 2 == 0) {
                matrix[i][j] = rand() % 10;
            }
            else
            {
                matrix[i][j] = -rand() % 10;
            }
        }
    }
    return matrix;
}

void OutputMatrix(Matrix& matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void OutputVector(std::vector<int>& vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> DeleteRepetitionsInVector(std::vector<int>& vector)
{
    std::vector<int> result;

    for (size_t i = 0; i < vector.size()-1; ++i)
    {
        bool isNotInResult = true;
        for (size_t j = 0; j < result.size(); ++j)
        {
            if (result[j] == vector[i])
            {
                isNotInResult = false;
            }
        }
        if (isNotInResult) {
            result.push_back(vector[i]);
        }
    }
    return result;
}

std::vector<int> FindingCommonValuesInMatrixs(Matrix& A, Matrix& B, Matrix& C)
{
    std::vector<int> findingValues;

    for (size_t i_A = 0; i_A < A.size(); ++i_A)
    {
        for (size_t j_A = 0; j_A < A[0].size(); ++j_A)
        {
            for (size_t i_B = 0; i_B < B.size(); ++i_B)
            {
                for (size_t j_B = 0; j_B < B[0].size(); ++j_B)
                {
                    for (size_t  i_C = 0; i_C < C.size(); ++i_C)
                    {
                        for (size_t j_C = 0; j_C < C[0].size(); ++j_C)
                        {
                            if ((A[i_A][j_A] == B[i_B][i_B]) && (A[i_A][j_A] == C[i_C][j_C]))
                            {
                                findingValues.push_back(A[i_A][j_A]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (findingValues.empty())
    {
        return findingValues;
    }
    else
    {
        return DeleteRepetitionsInVector(findingValues);
    }
}

bool IsNotInMatrix(int element, Matrix matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == element)
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> NotFindingElementOfMatrixInOtherMatrix(Matrix& matrix_1, Matrix& matrix_2, Matrix& matrix_3)
{
    std::vector<int> findingValues;

    for (size_t i = 0; i < matrix_1.size(); ++i)
    {
        for (size_t j = 0; j < matrix_1[0].size(); ++j)
        {
            if ((IsNotInMatrix(matrix_1[i][j], matrix_2)) && (IsNotInMatrix(matrix_1[i][j], matrix_3)))
            {
                findingValues.push_back(matrix_1[i][j]);
            }
        }
    }
    return findingValues;
}

std::vector<int> FindingUniqueValuesInMatrixs(Matrix& A, Matrix& B, Matrix& C)
{
    std::vector<int> findingValues;

    std::vector<int> findingValuesMatrixA = NotFindingElementOfMatrixInOtherMatrix(A,B,C);
    findingValues.insert(findingValues.end(), findingValuesMatrixA.begin(), findingValuesMatrixA.end());

    std::vector<int> findingValuesMatrixB = NotFindingElementOfMatrixInOtherMatrix(A, B, C);
    findingValues.insert(findingValues.end(), findingValuesMatrixB.begin(), findingValuesMatrixB.end());

    std::vector<int> findingValuesMatrixC = NotFindingElementOfMatrixInOtherMatrix(A, B, C);
    findingValues.insert(findingValues.end(), findingValuesMatrixC.begin(), findingValuesMatrixC.end());

    if (findingValues.empty())
    {
        return findingValues;
    }
    else
    {
        return DeleteRepetitionsInVector(findingValues);
    }
}

std::vector<int> FindingCommonValuesInTwoMatrixs(Matrix& A, Matrix& C)
{
    std::vector<int> findingValues;

    for (size_t i_A = 0; i_A < A.size(); ++i_A)
    {
        for (size_t j_A = 0; j_A < A[0].size(); ++j_A)
        {
            for (size_t i_C = 0; i_C < C.size(); ++i_C)
            {
                for (size_t j_C = 0; j_C < C[0].size(); ++j_C)
                {
                    if (A[i_A][j_A] == C[i_C][j_C])
                    {
                        findingValues.push_back(A[i_A][j_A]);
                    }
                }
            }
        }
    }
    if (findingValues.empty())
    {
        return findingValues;
    }
    else
    {
        return DeleteRepetitionsInVector(findingValues);
    }
}

std::vector<int> NegativeValuesInMatrixs(Matrix& A, Matrix& B, Matrix& C)
{
    std::vector<int> findingValues;

    for (size_t i = 0; i < A.size(); ++i)
    {
        for (size_t j = 0; j < A[0].size(); ++j)
        {
            if (A[i][j]<0)
            {
                findingValues.push_back(A[i][j]);
            }
        }
    }

    for (size_t i = 0; i < B.size(); ++i)
    {
        for (size_t j = 0; j < B[0].size(); ++j)
        {
            if (B[i][j] < 0)
            {
                findingValues.push_back(B[i][j]);
            }
        }
    }

    for (size_t i = 0; i < C.size(); ++i)
    {
        for (size_t j = 0; j < C[0].size(); ++j)
        {
            if (C[i][j] < 0)
            {
                findingValues.push_back(C[i][j]);
            }
        }
    }

    if (findingValues.empty())
    {
        return findingValues;
    }
    else
    {
        return DeleteRepetitionsInVector(findingValues);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    size_t rows_A, cols_A;
    size_t rows_B, cols_B;
    size_t rows_C, cols_C;

    std::cout << "введите количество строк и столбцов для матрицы A";
    std::cin >> rows_A >> cols_A;
    Matrix A = InizialitionMatrix(rows_A, cols_A);
    OutputMatrix(A, rows_A, cols_A);

    std::cout << "введите количество строк и столбцов для матрицы B";
    std::cin >> rows_B >> cols_B;
    Matrix B = InizialitionMatrix(rows_B, cols_B);
    OutputMatrix(B, rows_B, cols_B);

    std::cout << "введите количество строк и столбцов для матрицы C";
    std::cin >> rows_C >> cols_C;
    Matrix C = InizialitionMatrix(rows_C, cols_C);
    OutputMatrix(C, rows_C, cols_C);

    std::vector<int> result = FindingCommonValuesInMatrixs(A, B, C);
    OutputVector(result);

    result = FindingUniqueValuesInMatrixs(A, B, C);
    OutputVector(result);

    result = FindingCommonValuesInTwoMatrixs(A, C);
    OutputVector(result);

    result = NegativeValuesInMatrixs(A, B, C);
    OutputVector(result);
    return 0;
}
