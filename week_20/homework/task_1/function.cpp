#include <iostream>
#include <ctime>

void FillArrayInt(int array[], size_t SIZE)
{
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 10;
	}
}

void ShowArrayInt(int array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

}

int MinimalArrayInt(int array[], size_t SIZE)
{
	int min = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

int MaximumArrayInt(int array[], size_t SIZE)
{
	int max = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

void SortArrayInt(int array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void EditElementArrayInt(int array[], size_t SIZE, int IndexElement, int NewElement)
{
	array[IndexElement] = NewElement;
}


void FillArrayDouble(double array[], size_t SIZE)
{
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = static_cast<double>(rand() % 10 *1.1);
	}
}

void ShowArrayDouble(double array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

double MinimalArrayDouble(double array[], size_t SIZE)
{
	double min = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

double MaximumArrayDouble(double array[], size_t SIZE)
{
	double max = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

void SortArrayDouble(double array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void EditElementArrayDouble(double array[], size_t SIZE, int IndexElement, double NewElement)
{
	array[IndexElement] = NewElement;
}


void FillArrayChar(char array[], size_t SIZE)
{
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = 'a' + rand() % 10;
	}
}

void ShowArrayChar(char array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

char MinimalArrayChar(char array[], size_t SIZE)
{
	char min = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

char MaximumArrayChar(char array[], size_t SIZE)
{
	char max = array[0];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

void SortArrayChar(char array[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void EditElementArrayChar(char array[], size_t SIZE, int IndexElement, char NewElement)
{
	array[IndexElement] = NewElement;
}