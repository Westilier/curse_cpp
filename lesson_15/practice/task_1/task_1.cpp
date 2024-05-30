#include <iostream>
#include <string>


int main()
{
    std::string str = "1 2 3 4";
    size_t length = str.size();
    for (size_t i = 0; i < length; ++i)
    {
        if (str[i] == ' ')
        {
            str[i] = '\t';
        }
    }
    std::cout << str;
}
