#include <iostream>
#include <fstream>
#include <string>


int main()
{
    size_t key = 3;
    std::string lettersUppercase = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::string lettersLowercase = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    std::ifstream in("text.txt");
    std::ofstream out("finishText.txt");
    char symbol;
    while (in.get(symbol))
    {
        if (!(lettersUppercase.find(symbol) == lettersUppercase.npos))
        {
            size_t position = lettersUppercase.find(symbol) + key;
            if (position > 32)
            {
                symbol = lettersUppercase[position-33];
            }
            else
            {
                symbol = (lettersUppercase[position]);
            }
        }
        else if (!(lettersLowercase.find(symbol) == lettersLowercase.npos))
        {
            size_t position = lettersLowercase.find(symbol) + key;
            if (position > 32)
            {
                symbol = lettersLowercase[position - 33];
            }
            else
            {
                symbol = (lettersLowercase[position]);
            }
        }
        out << symbol;
    }
    std::cout << "completed " << std::endl;
    return 0;
}

