#include <iostream>
#include <string>


int main()
{
	setlocale(LC_ALL, "rus");

	std::string str;
	std::cout << "Введите предложение";
	getline(std::cin, str);
	
	size_t count = 1;
	size_t length = str.size();
	for (size_t i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			count++;
		}
		else if (str[i] == '.')
		{
			break;
		}
	}

	std::cout << "слов " << count;

	return 0;
}