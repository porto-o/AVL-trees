#include "ArBin.h"

typedef ArBin ArBB;

ArBB insordAB(Elem e, ArBB a)
{
    if (esVacioAB(a))
        return consAB(e, vacioAB(), vacioAB());
    else if (EsMenor(e, raiz(a)))
        return consAB(raiz(a), insordAB(e, izqAB(a)), derAB(a));
    else
        return consAB(raiz(a), izqAB(a), insordAB(e, derAB(a)));
}