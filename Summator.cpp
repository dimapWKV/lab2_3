#include "Summator.h"
#include <iostream>

using namespace std;

Summator::Summator()
{
    sequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
}

int Summator::transform(int *n)
{
    int c = *n;
    return c;
}


int Summator::sum(int n)
{
    int summa = 0;
    for (int i = 0; i < n; i++)
        summa += transform(&sequence[i]);

    return summa;
}

int SquareSummator::transform(int *n)
{
    int c = *n;
    return c * c;  // квадрат числа
}

int CubeSummator::transform(int *n)
{
    int c = *n;
    return c * c * c;  // квадрат числа
}