#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm> 
#include <sys/time.h>
using namespace std;

void display(int *array, int size);
void InsertionSort(int *array, int size);
void swapping(int &a, int &b);
void MergeSort(int *array, int l, int r);
void Merge(int *array, int l, int m, int r);
void quickSort(int array[], int low, int high);
void QuickInsertion(int array[], int n, int k);
struct timeval start, end;
double time_taken;
