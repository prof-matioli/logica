#include <iostream>
#include "headers/pilha.h"

using namespace std;

int main()
{
    Pilha * p1 = cria();
    int result = -1; // receberá o resultado da operação POP()

    for(int i=1; i<=10; i++)
        push(p1,i);

    imprime(p1);

    //chama a função pop(), que retira o elemento do topo, e imprime
    //o valor. Se quiser pode armazenar o valor em alguma variável
    //ao invéz de imprimí-lo diretamente.
    cout << endl << "===========================" << endl;
    cout << "Retirou: " << pop(p1,&result) << endl;
    cout << "Retirou: " << pop(p1,&result) << endl;
    cout << endl << "===========================" << endl;

    imprime(p1);
    return 0;
}
