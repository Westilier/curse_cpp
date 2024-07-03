#include <iostream>
#include <fstream>
#include <string>


size_t CountLineInFile(std::string NameFile)
{
    std::ifstream in(NameFile);
    size_t countLine = 0;
    std::string line;

    while (std::getline(in, line))
    {
        countLine++;
    }

    return countLine;
}

int main()
{
    std::string line;
    std::string NameFile = "text_1.txt";

    std::ofstream out("text_2.txt");
    size_t CountLine = CountLineInFile(NameFile);
    std::ifstream in(NameFile);
    if (in.is_open() && out.is_open())
    {
        while(std::getline(in, line))
        {
            out << line << "\n";
        }
    }
    in.close();
    out.close();

    return 0;
}