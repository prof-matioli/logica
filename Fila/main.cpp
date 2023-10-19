#include <iostream>
#include "headers/fila.h"

using namespace std;

int main()
{
    Fila* f = cria();
    insere(f,20.0);
    insere(f,20.8);
    insere(f,21.2);
    insere(f,24.3);
    printf("\n============== CONFIGURACAO ATUAL DA FILA =====================\n");
    imprime(f);
    printf("\n============== REALIZA ALGUMAS OPERACOES NA FILA =====================\n");
    cout << "Retira um elemento: " << retira(f,NULL) << endl;
    cout << "Retira um elemento: " << retira(f,NULL) << endl;
    cout << "Insere novo elemento: 38.7" << endl;
    insere(f,38.7);
    printf("\n============== CONFIGURACAO ATUAL DA FILA =====================\n");
    imprime(f);
    libera(f);
    return 0;
}
