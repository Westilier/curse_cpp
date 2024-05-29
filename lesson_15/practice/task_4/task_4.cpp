#include <iostream>
#include <string>

std::string strrev(std::string str)
{
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    setlocale(LC_ALL, "rus");

	std::string str = "15151";

    if (str == strrev(str))
    {
        std::cout << "строка палендром";
    }
    else 
    {
        std::cout << "строка не палендром";
    }
}
