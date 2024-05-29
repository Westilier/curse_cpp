#include <iostream>
#include<string>


int mystrcmp(const char* str1, const char* str2)
{
    if (*str1 == *str2)
    {
        return 0;
    }

    size_t length_1 = strlen(str1);
    size_t length_2 = strlen(str2);
    if (length_1 > length_2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


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

void Uppercase(char* str1)
{
    size_t length = strlen(str1) - 1;

    for (size_t i = 0; i < length; ++i)
        if (str1[i] < 'z' && str1[i] > 'a')
        {
            str1[i] -= 32;
        }
}

void Lowercase(char* str1)
{
    size_t length = strlen(str1) - 1;

    for (size_t i = 0; i < length; ++i)
        if (str1[i] < 'Z' && str1[i] > 'A')
        {
            str1[i] += 32;
        }
}

void mystrrev(char* str)
{
    size_t length = strlen(str) - 1;
    for (size_t i = 0; i <= (length / 2); ++i)
    {
        std::swap(str[i], str[length - i]);
    }

}
int main()
{
    return 0;
}