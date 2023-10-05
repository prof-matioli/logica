#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

struct fila {
    No* ini;
    No* fim;
};

typedef struct fila Fila;


Fila* cria (void);
void insere (Fila* f, float v);
float retira (Fila* f, int *resultado);
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f);
#endif // FILA_H_INCLUDED
