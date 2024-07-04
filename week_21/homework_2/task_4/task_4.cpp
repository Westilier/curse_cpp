#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"

void ReplaceWordInText(std::string& text, std::string& searchWord, std::string& wordToReplace)
{
    for (size_t i = 0; i < text.size(); ++i)
    {
        size_t startOfWord = text.find(searchWord, i);
        if (startOfWord != std::string::npos)
        {
            text.replace(startOfWord, searchWord.size(), wordToReplace);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string buffer;
    std::cout << "Введите слово для поиска" << std::endl;
    std::string word;
    getline(std::cin, word);

    std::cout << "Введите слово для замены" << std::endl;
    std::string wordToReplace;
    getline(std::cin, wordToReplace);

    std::fstream initialFile("text.txt");
    std::fstream finishFile("text_2.txt");
    while (std::getline(initialFile, buffer))
    {
        if (buffer.find(word) != std::string::npos)
        {
            ReplaceWordInText(buffer, word, wordToReplace);
            finishFile << buffer <<std::endl;
        }
    }

    initialFile.close();
    finishFile.close();
    std::cout << "completed " << std::endl;
    return 0;
}