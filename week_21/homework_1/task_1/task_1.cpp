#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line_1, line_2;

    std::ifstream in_1("text_1.txt");
    std::ifstream in_2("text_2.txt");
    if (in_1.is_open() && in_2.is_open());
    {
        while (std::getline(in_1, line_1) && std::getline(in_2, line_2))
        {
            if (line_1 != line_2)
            {
                std::cout << line_1 << std::endl
                        << line_2 << std::endl;
            }
        }
    }
    in_1.close();
    in_2.close();
    
    return 0;
}