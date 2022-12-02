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
    ImpElem(raiz(a));

    if(!EsAVL(a))
    {
        if(absoluto(FactBal(a)) > 1)
        {
            if(EsAVL(izqAB(a)) && EsAVL(derAB(a)))
            {
                if(FactBal(a) > 1) // Desbalanceo por la izquierda
                {
                    if(FactBal(izqAB(a)) > 0)
                        a = rotaDer(a);
                    else if(FactBal(izqAB(a)) < 0)
                        a = rotaDerIzq(a);
                    
                }
                else if(FactBal(a) < -1)
                {
                    if(FactBal(derAB(a)) < 0 )
                        a = rotaIzq(a);
                    else if(FactBal(derAB(a)) > 0)
                        a = rotaIzqDer(a);
                } 
            }
        }
        else
        {
            if(EsAVL(izqAB(a)))
                a = consAB(raiz(a), izqAB(a), HazAVL(derAB(a)));
            else if(EsAVL(derAB(a)))
                a = consAB(raiz(a), HazAVL(izqAB(a)), derAB(a));
        }
    }
    else
    {
        if(EsAVL(izqAB(a)))
            a = consAB(raiz(a),izqAB(a), HazAVL(derAB(a)));
        else if(EsAVL(derAB(a)))
            a = consAB(raiz(a), HazAVL(izqAB(a)), derAB(a));
    }

    EsAVL(a) ? puts("Si") : puts("No");
    ImpElem(raiz(a));

}