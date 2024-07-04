#include <iostream>
#include <fstream>
#include <string>

std::string GetLongestStringInFile(std::string & FileName)
{
    std::fstream initialFile(FileName);
    std::string buffer;

    std::getline(initialFile, buffer);
    size_t max = buffer.size();
    std::string maxString = buffer;
    while (std::getline(initialFile, buffer))
    {
        size_t length = buffer.size();
        if (length > max)
        {
            max = length;
            maxString = buffer;
        }
    }

    initialFile.close();
    return maxString;
}

int main()
{
    std::string FileName = "text.txt";
    std::cout << GetLongestStringInFile(FileName) << std::endl;
    return 0;
}