#include <iostream>
#include <vector>
#include <string>


void SortAscending(std::vector<std::string>& surnames)
{
    size_t count = surnames.size();
    for (size_t i = 0; i < count; i++) 
    {
        for (size_t j = 0; j < count-1; j++) 
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
    setlocale(LC_ALL, "rus");

    size_t count = 5;
    std::vector<std::string> surnames;
    surnames.resize(count);

    for (size_t i = 0; i < count; ++i)
    {
        std::cout << "Введите фамилию студента";
        getline(std::cin, surnames[i]);
    }

    SortAscending(surnames);

    for (size_t i = 0; i < count; ++i)
    {
        std::cout << surnames[i] << std::endl;
    }
}
