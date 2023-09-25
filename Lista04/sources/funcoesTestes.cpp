#include <iostream>
#include "../headers/funcoes.h"

int testaSepara_UltimoElementoLista(Lista *l)
{
    Lista *p;
    int ult = 0;
    for(p=l; p!=NULL; p=p->prox)
    {
        ult = p->info;
    }
    return ult;
}

int testaSepara_PrimeiroElementoLista(Lista *l)
{
    Lista *p=l;
    int info=0;
    if(p!=NULL)
        info = p->info;

    return info;
}

int testaRetiraPrefixo_PrimeiroElementoLista(Lista *l)
{
    Lista *p=l;
    int info=0;
    if(p!=NULL)
        info = p->info;

    return info;
}
