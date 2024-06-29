#include <iostream>
#include <fstream>
#include <string>


struct Statistic {
    size_t countSymbol = 0;
    size_t countLine = 0;
    size_t countVowels = 0;
    size_t countСonsonants = 0;
    size_t countNumber = 0;
};

size_t CountLineInFile(std::string NameFile)
{
    std::ifstream in(NameFile);
    size_t countLine = 0;
    std::string line;

    while (std::getline(in, line))
    {
        countLine++;
    }

    in.close();

    return countLine;
}

Statistic StatisticFile(std::string NameFile)
{
    std::string numbers = "0123456789";
    std::string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    std::string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";

    Statistic statistics;
    char symbol;

    std::ifstream in(NameFile);
    if (in.is_open())
    {
        while (in.get(symbol))
        {
            if (!(numbers.find(symbol) == numbers.npos))
            {
                statistics.countNumber++;
            }
            else if (!(vowels.find(symbol) == vowels.npos))
            {
                statistics.countVowels++;
            }
            else if (!(consonants.find(symbol) == vowels.npos))
            {
                statistics.countСonsonants++;
            }
            statistics.countSymbol++;
            
        }
    }

    statistics.countLine = CountLineInFile(NameFile);

    in.close();
    return statistics;
}

void WriteStatisticsInFile(Statistic statistics, std::string NameFile)
{
    std::ofstream out(NameFile);
    out << "Количество символов " << statistics.countSymbol << std::endl
            << "Количество строк " << statistics.countLine << std::endl
            << "Количество гласных букв " << statistics.countVowels << std::endl
            << "Количество согласных букв " << statistics.countСonsonants << std::endl
            << "Количество цифр " << statistics.countNumber << std::endl;
}

int main()
{
    WriteStatisticsInFile(StatisticFile("text.txt"),"statistic.txt");
    std::cout << "completed " << std::endl;
    return 0;
}