#include <iostream>
#include <vector>
#include <string>

#include "Windows.h"

void SortAscending(std::vector<std::string>& surnames)
{
    size_t count = surnames.size();
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count - 1; j++)
        {
            if (surnames[j] > surnames[j + 1])
            {
                std::swap(surnames[j], surnames[j + 1]);
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    size_t count = 5;
    std::vector<std::string> surnames;

    for (size_t i = 0; i < count; ++i)
    {
        std::cout << "Введите фамилию студента ";
        std::string str;
        std::cout << str;
        getline(std::cin,str);
        surnames.push_back(str);
    }

    SortAscending(surnames);

    for (size_t i = 0; i < count; ++i)
    {
        std::cout << surnames[i] << std::endl;
    }
}
