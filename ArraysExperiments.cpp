#include <TXLib.h>
#include <stdio.h>

const size_t ar2Ysize = 5;

void Print1dAr(int *ar, size_t arSize);
void Er1Print1dAr(int *ar, size_t arSize);
void Er2Print1dAr(int *ar, size_t arSize);

void Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);
void Er1Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);
void Er2Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);

void PrintTrAr(int *ar, size_t Xsize, size_t arSize);

size_t FindSize(size_t arSize);

size_t ProgresSum(size_t num);

int main(void)
{
    int ar1[] = {1, 3, 9, 27, 81, 243, 729};

    size_t ar1Size = sizeof(ar1) / sizeof(ar1[0]);

    Print1dAr(ar1, ar1Size);
    Er1Print1dAr(ar1, ar1Size);
    Er2Print1dAr(ar1, ar1Size);

    int ar2[][ar2Ysize] =
    {{1, 2, 4, 8, 16},
     {3, 6, 12, 24, 48},
     {9, 18, 36, 72, 144}};

    size_t Xsize = 0;
    Xsize = sizeof(ar2) / sizeof(ar2[0]);

    Print2dAr(ar2, Xsize);
    Er1Print2dAr(ar2, Xsize);
    Er2Print2dAr(ar2, Xsize);

    int trAr[] = {1,
                  1, 1,
                  1, 2, 1,
                  1, 3, 3, 1,
                  1, 4, 6, 4, 1};
    size_t arSize = sizeof(trAr) / sizeof(trAr[0]);

    PrintTrAr(trAr, FindSize(arSize), arSize);

    return 0;
}

// 1d array right
void Print1dAr(int *ar, size_t arSize)
{
    assert(ar);

    printf("1d array, right program\n");

    for (size_t x = 0; x < arSize; x++)
    {
        printf("%d ", *(ar + x));
    }

    printf("\n\n");
}

// wrong offset
void Er1Print1dAr(int *ar, size_t arSize)
{
    assert(ar);

    printf("1d array, wrong offset\n");

    for (size_t x = 0; x < arSize; x++)
        printf("%d ", *(ar - x));

    printf("\n\n");
}

// printing pointers instead of values
void Er2Print1dAr(int *ar, size_t arSize)
{
    assert(ar);

    printf("1d array, printing pointers instead of values\n");

    for (size_t x = 0; x < arSize; x++)
        printf("%d ", ar + x);

    printf("\n\n");
}

// 2d array right
void Print2dAr(int (*ar)[ar2Ysize], size_t Xsize)
{
    assert(ar);

    printf("2d array, right program\n");

    for (size_t x = 0; x < Xsize; x++)
    {
        for (size_t y = 0; y < ar2Ysize; y++)
            printf("%d ", *(*(ar + x) + y));

        printf("\n");
    }

    printf("\n");
}

// x and y are changed
void Er1Print2dAr(int (*ar)[ar2Ysize], size_t Xsize)
{
    assert(ar);

    printf("2d array, x and y are changed\n");

    for (size_t x = 0; x < Xsize; x++)
    {
        for (size_t y = 0; y < ar2Ysize; y++)
            printf("%d ", *(*(ar + y) + x));

        printf("\n");
    }

    printf("\n");
}

// missed (int *)
void Er2Print2dAr(int (*ar)[ar2Ysize], size_t Xsize)
{
    assert(ar);

    printf("2d array, printing pointers instead of values\n");

    for (size_t x = 0; x < Xsize; x++)
    {
        for (size_t y = 0; y < ar2Ysize; y++)
            printf("%d ", *(ar + x * ar2Ysize + y));

        printf("\n");
    }

    printf("\n");
}

// prints triangle array
void PrintTrAr(int *ar, size_t Xsize, size_t arSize)
{
    assert(ar);

    printf("triangle array\n");

    for (size_t x = 0; x < Xsize; x++)
    {
        for (size_t y = 0; y < x + 1; y++)
        {
            if (ProgresSum(x) + y < arSize)
                printf("%3d", *(ar + ProgresSum(x) + y));
            else
                printf("  0");
        }

        printf("\n");
    }
}

size_t FindSize(size_t arSize)
{
    size_t Xsize = 1;

    while (arSize > ProgresSum(Xsize))
        Xsize++;

    return Xsize;
}

size_t ProgresSum(size_t num)
{
    return (num + 1) * num / 2;
}
