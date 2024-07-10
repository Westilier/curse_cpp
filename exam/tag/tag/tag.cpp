#include <iostream>
#include <vector>

using map = std::vector<std::vector<size_t>>;

void PrintMap(map& map, size_t& size)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (map[i][j] < 10)
            {
                std::cout << " " << map[i][j] << " ";
            }
            else
            {
                std::cout << map[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void CreateMap(map& map, size_t& size)
{
    size_t x = 1;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            map[i][j] = x++;
        }
    }
}


int main()
{
    size_t SIZE=1;

    std::cout << "Выберите режим " << std::endl
            << "1 - 3 на 3" << std::endl
            << "2 - 4 на 4" << std::endl;
    size_t key;
    std::cin >> key;
    if (key == 1)
    {
        SIZE = 3;
    }
    else if (key == 2)
    {
        SIZE = 4;
    }
    map Map(SIZE, std::vector<size_t>(SIZE));
    CreateMap(Map, SIZE);
    PrintMap(Map, SIZE);
}
