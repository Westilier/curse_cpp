#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"


size_t CounterWordInText(std::string& text, std::string& searchWord)
{
    size_t count = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        size_t startOfWord = text.find(searchWord, i);
        if (startOfWord != std::string::npos)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::fstream initialFile("text.txt");
    std::cout << "Введите слово "<<std::endl;
    std::string word;
    getline(std::cin, word);
    std::string buffer;
    size_t count = 0;
    while (std::getline(initialFile, buffer))
    {
        count += CounterWordInText(buffer, word);
    }
    initialFile.close();
    std::cout << count << " слово \"" << word << "\" встречается в файле" << std::endl;

    return 0;
}