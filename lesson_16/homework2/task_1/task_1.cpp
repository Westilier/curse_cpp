#include <iostream>
#include <string>


int main()
{
    setlocale(LC_ALL, "rus");

    std::string str = "hello world. it is new Creater.";
    std::cout << str << std::endl;
    //начало 1 пункта
    std::string celectedWord;
    std::string replacedWord;
    std::cout << "Введите слово и слово на которое его заненить(Слова дожны быть одной и тойже длины)";
    getline(std::cin, celectedWord);
    getline(std::cin, replacedWord);

    if (str.find(celectedWord) != std::string::npos)
    {
        size_t startCelectedWord = str.find(celectedWord);
        size_t lenCelectedWord = celectedWord.size();
        size_t lenReplacedWord = replacedWord.size();
        if (lenCelectedWord != lenReplacedWord)
        {
            std::cout << "Error(incorrect lengths of words)";
        }
        else
        {
            str.replace(startCelectedWord, lenCelectedWord, replacedWord);
        }
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << str << std::endl;
    //начало 2 пункта
    str[0] = toupper(str[0]);
    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?')
        {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    std::cout << str << std::endl;
    //начало 3 пункта
    for (size_t i = 0; i < 26; ++i)
    {
        size_t countLetter = 0;
        for (size_t j = 0; j < str.size(); ++j)
        {
            if (islower(str[j]) && str[j] == 'a' + i)
            {
                countLetter++;
            }
            else if (isupper(str[j]) && str[j] == 'A' + i)
            {
                countLetter++;
            }
        }
        std::cout << (char)('a' + i) << " - " << countLetter<<std::endl;
    }
    //начало 4 пункта
    size_t countNumber = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            countNumber++;
        }
    }
    std::cout << "количество цифер - " << countNumber<<std::endl;
}
