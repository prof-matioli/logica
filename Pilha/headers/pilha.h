#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

struct pilha {
    No* prim;
};
typedef struct pilha Pilha;

Pilha* cria (void);
No* ins_ini (No* l, float v);
No* ret_ini (No* l);
void push (Pilha* p, float v);
float pop (Pilha* p, int * resultado);
int vazia (Pilha* p);
void libera (Pilha* p);
void imprime (Pilha* p);


#endif // PILHA_H_INCLUDED
