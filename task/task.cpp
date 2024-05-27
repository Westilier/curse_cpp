#include <iostream>
#include<string>

int mystrcmp(const char* str1, const char* str2);

int StringToNumber(char* str)
{
    size_t number = 0;
    size_t length = strlen(str)-1;
    for (size_t i = 0; i < length; ++i)
    {
        number = number * 10 + str[i] - '0';
    }
    return number;
}

std::string NumberToString(int number)
{
    std::string str = std::to_string(number);
    return str;
}

int main()
{
    std::cout << NumberToString(123);

    return 0;
}