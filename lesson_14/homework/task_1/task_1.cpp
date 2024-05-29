#include <iostream>
#include<string>

//int mystrcmp(const char* str1, const char* str2);

int StringToNumber(std::string str)
{
    size_t number = 0;
    size_t length = str.size() - 1;

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

void Uppercase(std::string str1)
{
    size_t length = str1.size() - 1;

    for (size_t i = 0; i < length; ++i)
        if (str1[i] < 'z' && str1[i] > 'a')
        {
            str1[i] -= 32;
        }
}

void Lowercase(std::string str1)
{
    size_t length = str1.size() - 1;

    for (size_t i = 0; i < length; ++i)
        if (str1[i] < 'Z' && str1[i] > 'A')
        {
            str1[i] += 32;
        }
}

void mystrrev(char* str)
{
   // reverse()
}
int main()
{
    std::cout << NumberToString(123);

    return 0;
}