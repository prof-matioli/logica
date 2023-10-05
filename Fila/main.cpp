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
    cout << "Primeiro elemento: " << retira(f,NULL) << endl;
    cout << "Segundo elemento: " << retira(f, NULL) << endl;
    cout << "Configuracao atual da fila: " << endl;
    imprime(f);
    libera(f);
    return 0;
}
