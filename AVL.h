#include "ArBB.h"

typedef ArBB AVL;

int absoluto(int);
int EsAVL(AVL);
int FactBal(AVL);
AVL HazAVL(ArBB);
AVL InsAVL(Elem,AVL);
AVL rotaDer(ArBB);
AVL rotaIzq(ArBB);
AVL rotaDerIzq(ArBB);
AVL rotaIzqDer(ArBB);

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


AVL HazAVL(ArBB a) 
{ 
    if(absoluto(FactBal(a)) > 1)
    {
        if(EsAVL(izqAB(a)) && EsAVL(derAB(a)))
        {
            if(FactBal(a) > 1)
            {
                if(FactBal(izqAB(a)) > 0)
                    return rotaDer(a);
                else if(FactBal(izqAB(a)) < 0)
                    return rotaDerIzq(a);
            }
            else if(FactBal(a) < -1)
            {
                if(FactBal(derAB(a)) < 0)
                    return rotaIzq(a);
                else if(FactBal(derAB(a)) > 0)
                    return rotaIzqDer(a);
            }
        }
        else
        {
            if(EsAVL(izqAB(a)))
                return consAB(raiz(a),izqAB(a),HazAVL(derAB(a)));
            else if(EsAVL(derAB(a)))
                return consAB(raiz(a),HazAVL(izqAB(a)),derAB(a));
        }
    }
    else if(FactBal(a) <= 1)
    {
        if(EsAVL(izqAB(a)))
            return consAB(raiz(a),izqAB(a),HazAVL(a));
        else if(EsAVL(derAB(a)))
            return consAB(raiz(a),HazAVL(izqAB(a)),derAB(a));
    }    
    
    return a; 
}

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