#include <TXLib.h>
#include <stdio.h>

void Print1dAr(int * ar, size_t arSize);
void Er1Print1dAr(int * ar, size_t arSize);
void Er2Print1dAr(int * ar, size_t arSize);

int main(void)
{
    int ar1[] = {1, 3, 9, 27, 81, 243, 729};

    size_t ar1Size = sizeof(ar1) / sizeof(ar1[0]);

    Print1dAr(ar1, ar1Size);
    Er1Print1dAr(ar1, ar1Size);
    Er2Print1dAr(ar1, ar1Size);
}

void Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
    {
        assert(x < arSize);
        assert(x >= 0);

        printf("%8d", *(ar + x));
    }

    printf("\n\n");
}

void Er1Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
        printf("%8d", *(ar - x));

    printf("\n\n");
}

void Er2Print1dAr(int * ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
        printf("%8d", ar + x);

    printf("\n\n");
}


