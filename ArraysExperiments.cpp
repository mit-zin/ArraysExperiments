#include <TXLib.h>
#include <stdio.h>

void Print1dAr(int * ar, size_t arSize);

int main(void)
{
    int ar1[] = {1, 3, 9, 27, 81, 243, 729};

    size_t ar1Size = sizeof(ar1) / sizeof(ar1[0]);

    Print1dAr(ar1, ar1Size);
}

void Print1dAr(int *ar, size_t arSize)
{
    for (size_t x = 0; x < arSize; x++)
    {
        assert(x < arSize);

        printf("%8d", *(ar + x));
    }

    printf("\n\n");
}
