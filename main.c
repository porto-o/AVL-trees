#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "AVL.h"

int main()
{
    Elem e;
    AVL x = vacioAB();

    for (e = 1; e <= 100; e++)
    {
        x = InsAVL(e, x);
        printf("%d\n", FactBal(x));
    }

    return 0;
}