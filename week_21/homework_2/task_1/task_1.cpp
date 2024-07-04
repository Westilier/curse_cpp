#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::fstream initialFile("text_1.txt");
    std::fstream finishFile("text_2.txt");
    std::string buffer;

    while (std::getline(initialFile, buffer))
    {
        if (initialFile.eof())
        {
            break;
        }
        finishFile << buffer << std::endl;
    }
    finishFile.close();
    initialFile.close();
    std::cout << "completed " << std::endl;
    return 0;
}