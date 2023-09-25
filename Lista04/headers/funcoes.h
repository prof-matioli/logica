#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
struct lista
{
	int info;
	struct lista * prox;
};

typedef struct lista Lista;
struct lista * insere(struct lista * l, int info);
struct lista * separa(struct lista * l, int info);
struct lista * concatena(struct lista * _l1, struct lista * _l2);
struct lista * constroi(int n, int * v);
struct lista * retira_prefixo(struct lista * l, int n);
void imprimeLista(struct lista * l);

int testaUltimoElementoLista(struct lista *l);
int testaPrimeiroElementoLista(struct lista *l);
#endif // FUNCOES_H_INCLUDED
