#include <iostream>
#include <string>


int main()
{
    std::string str = " 1 b3 3";
    size_t length = str.size();
    
    size_t countLetter = 0;
    size_t countNumber = 0;
    size_t countOther = 0;
    for (size_t i = 0; i < length; ++i)
    {
        if (std::isalpha(str[i]))
        {
            countLetter++;
        }
        else if (std::isdigit(str[i]))
        {
            countNumber++;
        }
        else
        {
            countOther++;
        }
    }
    std::cout << "number " << countNumber << " letter " << countLetter << " other " << countOther;
    return 0;
}
