#include <iostream>
#include <string>

#include "Windows.h"


size_t CounterWordInText(std::string& text,std::string& searchWord)
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

size_t CounterSentenceInText(std::string& text)
{
    size_t count = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] == '.')
        {
            count++;
        }
    }
    return count;
}

size_t CounterDotAndCommaInText(std::string& text)
{
    size_t count = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] == '.' || text[i] == ',')
        {
            count++;
        }
    }
    return count;
}

void ReverseFullText(std::string& text)
{
    reverse(text.begin(), text.end());
}

void ReverseEverySentenceInText(std::string& text)
{
    size_t startSentence = 0;
    size_t endSentence;

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] == '.')
        {
            endSentence = i;
            if (startSentence < endSentence)
            {
                std::string sentence = text.substr(startSentence, endSentence - startSentence + 1);
                reverse(sentence.begin(), sentence.end());
                text.replace(startSentence, sentence.size(), sentence);

                startSentence = i+1;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str = "Lorem ipsum dolor sit amet. Quis nostrud exercitation. Ullamco laboris nisi ut aliquip. Ex ea commodo consequat. ";
    
    std::cout << "Введите слово для поиска";
    std::string searchWord;
    getline(std::cin, searchWord);
    std::cout << CounterWordInText(str, searchWord) << std::endl;

    std::cout << CounterSentenceInText(str) << std::endl;

    std::cout << CounterDotAndCommaInText(str) << std::endl;

    ReverseFullText(str);
    std::cout << str<<std::endl;

    ReverseEverySentenceInText(str);
    std::cout << str<<std::endl;
    return 0;
}
