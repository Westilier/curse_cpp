#include <iostream>
#include <string>


int main()
{
    std::string str = " 1 3 3";
    size_t length = str.size();

    for (size_t i = 0; i < length; ++i)
    {
        if (str[i] == ' ')
        {
            str[i] = '\t';
        }
    }
    std::cout << str;

    return 0;
}
