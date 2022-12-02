typedef struct NodoAB
{
    Elem raiz;
    struct NodoAB *izq;
    struct NodoAB *der;
} * ArBin;

ArBin vacioAB() { return NULL; }

ArBin consAB(Elem r, ArBin i, ArBin d)
{
    ArBin t = (ArBin)malloc(sizeof(struct NodoAB));
    t->raiz = r;
    t->izq = i;
    t->der = d;
    return t;
}
int esVacioAB(ArBin a) { return a == NULL; }

Elem raiz(ArBin a) { return a->raiz; }

ArBin izqAB(ArBin a) { return a->izq; }

ArBin derAB(ArBin a) { return a->der; }

int NumElemsAB(ArBin a)
{
    if (esVacioAB(a))
        return 0;
    else
        return 1 + NumElemsAB(izqAB(a)) + NumElemsAB(derAB(a));
}

int Mayor(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int Altura(ArBin a)
{
    if (esVacioAB(a))
        return 0;
    else
        return 1 + Mayor(Altura(izqAB(a)), Altura(derAB(a)));
}

void PreOrd(ArBin a)
{
    if (!esVacioAB(a))
    {
        ImpElem(raiz(a));
        PreOrd(izqAB(a));
        PreOrd(derAB(a));
    }
}

void PostOrd(ArBin a)
{
    if (!esVacioAB(a))
    {
        PostOrd(izqAB(a));
        PostOrd(derAB(a));
        ImpElem(raiz(a));
    }
}

void InOrd(ArBin a)
{
    if (!esVacioAB(a))
    {
        InOrd(izqAB(a));
        ImpElem(raiz(a));
        InOrd(derAB(a));
    }
}