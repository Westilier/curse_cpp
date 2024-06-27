//#define INTEGER 1
#define DOUBLE 1
//#define CHAR 1

#include "function.h"


int main()
{

	const size_t SIZE = 10;
#ifdef INTEGER
	int* array = new int[SIZE];
#elif DOUBLE
	double* array = new double[SIZE];
#elif CHAR
	char* array = new char[SIZE];
#endif

	FillArray(array, SIZE);
	ShowArray(array, SIZE);
	MinimalArray(array, SIZE);
	MaximumArray(array, SIZE);
	SortArray(array, SIZE);
	EditArray(array, SIZE, 4, 4);

	ShowArray(array, SIZE);

	return 0;
}
