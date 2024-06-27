#pragma once

#ifdef INTEGER

void FillArrayInt(int array[], size_t SIZE);
void ShowArrayInt(int array[], size_t SIZE);
int MinimalArrayInt(int array[], size_t SIZE);
int MaximumArrayInt(int array[], size_t SIZE);
void SortArrayInt(int array[], size_t SIZE);
void EditElementArrayInt(int array[], size_t SIZE, int IndexElement, int NewElement);

#define FillArray(array, SIZE) FillArrayInt(array, SIZE);
#define ShowArray(array, SIZE) ShowArrayInt(array, SIZE);
#define MinimalArray(array, SIZE) MinimalArrayInt(array, SIZE);
#define MaximumArray(array, SIZE) MaximumArrayInt(array, SIZE);
#define SortArray(array, SIZE) SortArrayInt(array, SIZE);
#define EditArray(array, SIZE, IndexElement, NewElement) EditElementArrayInt(array, SIZE, IndexElement, NewElement);

#elif DOUBLE

void FillArrayDouble(double array[], size_t SIZE);
void ShowArrayDouble(double array[], size_t SIZE);
double MinimalArrayDouble(double array[], size_t SIZE);
double MaximumArrayDouble(double array[], size_t SIZE);
void SortArrayDouble(double array[], size_t SIZE);
void EditElementArrayDouble(double array[], size_t SIZE, int IndexElement, double NewElement);

#define FillArray(array, SIZE) FillArrayDouble(array, SIZE);
#define ShowArray(array, SIZE) ShowArrayDouble(array, SIZE);
#define MinimalArray(array, SIZE) MinimalArrayDouble(array, SIZE);
#define MaximumArray(array, SIZE) MaximumArrayDouble(array, SIZE);
#define SortArray(array, SIZE) SortArrayDouble(array, SIZE);
#define EditArray(array, SIZE, IndexElement, NewElement) EditElementArrayDouble(array, SIZE, IndexElement, NewElement);

#elif CHAR

void FillArrayChar(char array[], size_t SIZE);
void ShowArrayChar(char array[], size_t SIZE);
char MinimalArrayChar(char array[], size_t SIZE);
char MaximumArrayChar(char array[], size_t SIZE);
void SortArrayChar(char array[], size_t SIZE);
void EditElementArrayChar(char array[], size_t SIZE, int IndexElement, char NewElement);

#define FillArray(array, SIZE) FillArrayChar(array, SIZE);
#define ShowArray(array, SIZE) ShowArrayChar(array, SIZE);
#define MinimalArray(array, SIZE) MinimalArrayChar(array, SIZE);
#define MaximumArray(array, SIZE) MaximumArrayChar(array, SIZE);
#define SortArray(array, SIZE) SortArrayChar(array, SIZE);
#define EditArray(array, SIZE, IndexElement, NewElement) EditElementArrayChar(array, SIZE, IndexElement, NewElement);

#endif

