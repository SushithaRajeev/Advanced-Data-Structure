#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <ctype.h>
#include <stdlib.h>

#define true 1
#define false 0
#define Left(i) (2 * (i))
#define Right(i) (2 * (i) + 1)
#define Parent(i) (i / 2)
#define GrandParent(m) (m / 4)
using namespace std;


int h, i = 1, array_size, j;
int TrickelDown(int i, int h, int array_size, int *array);
bool isMinLevel(int i, int h);
void swap(int* a, int* b);
void TrickleDownMin(int i, int h, int array_size, int *array);
void TrickleDownMax(int i, int h, int array_size, int *array);
void Print(int* a, int n);
void BubbleUp(int i, int h, int array_size, int *array);
int BubbleUpMin(int i, int *array);
int BubbleUpMax(int i, int *array);
int FindMax(int *array, int array_size);
int FindMin(int *array, int array_size);
int lc, lclc, lcrc, rc, rclc, rcrc, x, y, u, q, t, s, m, mc, mlc, mrc, Val, noOfInserts, option;
bool child = false;
