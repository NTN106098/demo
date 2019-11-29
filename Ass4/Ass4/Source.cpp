#include <stdio.h>
#include <conio.h>
#include "Header.h"

int main()
{
    srand((unsigned int)time(NULL));

    const int N = 25;
    int data[N];

    for (int i=0; i<N; ++i)
    {
        data[i] = rand() % 16 + 1;
        printf("%d ", data[i]);
    }
    puts("");

    quicksort(data, N);

    for (int i=0; i<N; ++i)
        printf("%x ", data[i]);

    puts("");

	_getch();
}