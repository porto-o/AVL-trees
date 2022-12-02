#include "ArBB.h"

typedef ArBB AVL;

int absoluto(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
int EsAVL(AVL a)
{
    return esVacioAB(a) ||
           ((absoluto(Altura(izqAB(a)) - Altura(derAB(a))) <= 1) &&
            (EsAVL(izqAB(a))) && (EsAVL(derAB(a))));
}

int FactBal(AVL a) { return Altura(izqAB(a)) - Altura(derAB(a)); }
AVL HazAVL(ArBB a) { return a; }

AVL InsAVL(Elem e, AVL a)
{
    a = insordAB(e, a);
    if (EsAVL(a))
        return a;
    else
        return HazAVL(a);
}

AVL rotaDer(ArBB a)
{
    return consAB(raiz(izqAB(a)), izqAB(izqAB(a)),
                  consAB(raiz(a), derAB(izqAB(a)), derAB(a)));
}
AVL rotaIzq(ArBB a)
{
    return consAB(raiz(derAB(a)), consAB(raiz(a), izqAB(derAB(a)), izqAB(a)),
                  derAB(derAB(a)));
}

AVL rotaDerIzq(ArBB a)
{
    return rotaDer(consAB(raiz(a), rotaIzq(izqAB(a)), derAB(a)));
}

AVL rotaIzqDer(ArBB a)
{
    return rotaIzq(consAB(raiz(a), izqAB(a), rotaDer(derAB(a))));
}