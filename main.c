#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "AVL.h"

void main()
{
    AVL a = vacioAB();
    EsAVL(a) ? puts("Si") : puts("No");
    a = InsAVL(1,InsAVL(2,InsAVL(3,InsAVL(4,vacioAB()))));
    EsAVL(a) ? puts("Si") : puts("No");
    a = InsAVL(42,a);
    ImpElem(raiz(a));
    EsAVL(a) ? puts("Si") : puts("No");
    //a = HazAVL(a);
}