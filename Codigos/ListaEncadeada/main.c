#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista{
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

//cabecalho das funcoes
void libera (Lista* l);
int vazia (Lista* l);
Lista * inicializa();
Lista* insere (Lista* l, int i);
void imprime (Lista* l);
Lista* busca (Lista* l, int v);
Lista* busca (Lista* l, int v);
Lista* retira (Lista* l, int v);
void libera (Lista* l);

//funcao de inicializacao
Lista * inicializa(){
    return NULL;
}

/* insercao no inicio: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* funcao imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
    Lista* p; /* variavel auxiliar para percorrer a lista */
    if(vazia(l)){
        printf("Lista vazia!");
        return;
    }

    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

/* funcao busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
    Lista* p;
    if(vazia(l)){
        printf("Lista vazia!");
        return NULL;
    }

    for (p=l; p!=NULL; p=p->prox){
        if (p->info == v)
            return p;
    }
    return NULL; /* nao achou o elemento */
}

/* funcao retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
        return l; /* nao achou: retorna lista original */
    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do inicio */
        l = p->prox;
    }
    else {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void libera (Lista* l)
{
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; /* guarda referencia para o proximo elemento
        */
        free(p); /* libera a memoria apontada por p */
        p = t; /* faz p apontar para o proximo */
    }
}

/* funcao vazia: retorna 1 se vazia ou 0 se nao vazia */
int vazia (Lista* l)
{
    return (l == NULL);
}

int main()
{
    Lista* l; /* declara uma lista, ainda nao inicializada */
    int v=0;

    setlocale(LC_ALL, "Portuguese");

    l = inicializa(); // inicializa a lista
    do{
        system("cls");
        printf("Valor : ");
        scanf("%d",&v);
        if(v>0)
            l = insere(l,v);

    }while(v>0);

    imprime(l);

    printf("Qual elemento excluir:");
    scanf("%d",&v);
    l = retira(l,v); //retira um elemento da lista, se existir
    imprime(l);

    libera(l); //libera todos os elementos da lista

    return 0;
}
