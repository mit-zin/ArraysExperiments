#include <TXLib.h>
#include <stdio.h>

const size_t ar2Ysize = 5;

void Print1dAr(int *ar, size_t arSize);
void Er1Print1dAr(int *ar, size_t arSize);
void Er2Print1dAr(int *ar, size_t arSize);

void Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);
void Er1Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);
void Er2Print2dAr(int (*ar)[ar2Ysize], size_t Xsize);

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
    //Ysize = sizeof(ar2[0]) / sizeof(ar2[0][0]);

    Print2dAr(ar2, Xsize);
    Er1Print2dAr(ar2, Xsize);
    Er2Print2dAr(ar2, Xsize);

    return 0;
}

// 1d array right
void Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
    {
        printf("%d ", *(ar + x));
    }

    printf("\n\n");
}

// wrong offset
void Er1Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
        printf("%d ", *(ar - x));

    printf("\n\n");
}

// printing pointers instead of values
void Er2Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
        printf("%d ", ar + x);

    printf("\n\n");
}

// 2d array right
void Print2dAr(int (*ar)[ar2Ysize], size_t Xsize)
{
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
    for (size_t x = 0; x < Xsize; x++)
    {
        for (size_t y = 0; y < ar2Ysize; y++)
            printf("%d ", *(ar + x * ar2Ysize + y));

        printf("\n");
    }

    printf("\n");
}
