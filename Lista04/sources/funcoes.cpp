#include <iostream>
#include <string.h>
#include "../headers/funcoes.h"

using namespace std;

struct lista * insere(struct lista * l, int info)
{
	struct lista * aux = (struct lista *) malloc(sizeof(struct lista));
	aux -> info = info;
	aux -> prox = NULL;

	if(l!=NULL)
	{
		aux->prox = l;
	}
	return aux;
}

Lista * separa(Lista * l, int info)
{
	Lista * aux = l;
	Lista * nova = NULL;
	while(aux!=NULL && aux->info!=info)
	{
		aux=aux->prox;
	}
	if(aux!=NULL) //achou
	{
		nova = aux->prox;
		aux->prox = NULL;
	}
	return nova;
}

Lista * concatena(Lista * _l1, Lista * _l2)
{
	Lista * a=_l1;
	if(_l1==NULL)
	{
		_l1=_l2;
	}
	else
	{
		for(Lista * p=_l1; p!=NULL; p=p->prox)
		{
			a = p;
		}
	}
	a->prox = _l2;
	return _l1;
}
struct lista * constroi(int n, int * v)
{
	Lista * aux=NULL;
	for(int i=0;i<n;i++)
		aux = insere(aux,v[i]);
	return aux;
}

Lista * retira_prefixo(Lista * l, int n)
{
	Lista * aux = l;
	Lista * novo = l;
	if(aux!=NULL)
	{
		int i=0;
		do
		{
			novo =aux->prox;
			free(aux);
			aux = novo;
			i++;
		}while(i<n && aux!=NULL);
	}
	return novo;
}

void imprimeLista(Lista * l)
{
	if(l!=NULL)
	{
		for(Lista * p = l; p!=NULL; p=p->prox)
		{
			cout << p->info << endl;
		}
	}
	else
		cout << "LISTA VAZIA!!!\n\n";
}
