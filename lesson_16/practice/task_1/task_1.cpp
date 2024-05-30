#include <iostream>


int mystrlen(const char* str)
{
	size_t length = strlen(str);
	return length;
}

char* mystrcpy(char* str1, const char* str2)
{
	char* ptr1 = str1;
	size_t length = strlen(str2);
	for (size_t i = 0; i < length; ++i)
	{
		ptr1[i] = str2[i];
	}
	return str1;
}

char* mystrcat(char* str1, const char* str2)
{
	size_t length1 = strlen(str1);
	size_t length2 = strlen(str2);
	for (size_t i = 0; i < length2; ++i)
		str1[length1 + i] = str2[i];
	return str1;
}

char* mystrchr(char* str, char s)
{
	size_t length = strlen(str);
	size_t entry = 0;
	for (size_t i = 0; i < length; ++i)
	{
		if (str[i] == s) 
		{
			str +=i;
			return str;
		}
	}

	return 0;
}

char* mystrstr(char* str1, char* str2)
{
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	size_t length1 = strlen(str1);
	size_t length2 = strlen(str2);
	size_t entry = 0;
	for (size_t i = 0; i < length1; ++i)
	{
		if (str1[i] == str2[0])
		{
			entry = i;
			for (size_t j = 0; j < length2; ++j)
			{
				if (str1[i + j] != str2[j])
				{
					entry = 0;
					break;
				}
			}
			if (entry == i)
			{
				str1 += entry;
				std::cout << str1 << std::endl;;
				return str1;
			}
		}
	}
	return 0;
}

int main()
{
	return 0;
}
