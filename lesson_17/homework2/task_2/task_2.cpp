#include <iostream>
#include <vector>
#include <string>


using Matrix = std::vector<std::vector<std::string>>;

void OutputMatrix(Matrix& matrix)
{
    size_t SIZE_1 = matrix.size();
    size_t SIZE_2 = matrix[0].size();

    for (size_t i = 0; i < SIZE_1; ++i)
    {
        for (size_t j = 0; j < SIZE_2; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::size_t> SearchByName(const Matrix& matrix, std::string name)
{
    std::vector<std::size_t> SearchedName;
    size_t SIZE = matrix[0].size();
    for (size_t i = 0; i < SIZE; ++i)
    {
        if (matrix[0][i] == name)
        {
            SearchedName.push_back(i);
        }
    }
    return SearchedName;
}

std::vector<std::size_t> SearchByPhone(const Matrix& matrix, std::string phone)
{
    std::vector<std::size_t> SearchedPhone;
    size_t SIZE = matrix[0].size();
    for (size_t i = 0; i < SIZE; ++i)
    {
        if (matrix[1][i] == phone)
        {
            SearchedPhone.push_back(i);
        }
    }
    return SearchedPhone;
}

void ChangeData(Matrix& matrix,size_t position)
{
    std::cout << "Введите имя";
    getline(std::cin, matrix[0][position]);
    std::cout << "Введите телефон";
    getline(std::cin, matrix[1][position]);
}

void AddDataInMatrix(Matrix& matrix)
{
    std::string name,phone;
    std::cout << "Введите имя";
    getline(std::cin, name);
    matrix[0].push_back(name);
    std::cout << "Введите телефон";
    getline(std::cin, phone);
    matrix[1].push_back(phone);
}
int main()
{
    setlocale(LC_ALL, "rus");

    size_t SIZE_1 = 2;
    size_t SIZE_2 = 5;
    Matrix matrix(SIZE_1, std::vector<std::string>(SIZE_2));
    matrix[0] = { "Влад","Андрей","Вася","Егор","Андрей"};
    matrix[1] = { "89991272112","89992372112" ,"89991232112" ,"89231272112" ,"89991272312" };
    AddDataInMatrix(matrix);
    OutputMatrix(matrix);
    return 0;
}