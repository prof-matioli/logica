#include "UnitTestPP.h"
#include "../headers/funcoes.h"

    namespace
    {
        TEST(testaConstroiLista_ValorPrimeiroElementoLista)
        {
            struct lista * l1 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            const int Result = testaPrimeiroElementoLista(l1);
            CHECK_EQUAL(2, Result);
        }
        TEST(testaConstroiLista_ValorUltimoElementoLista)
        {
            struct lista * l1 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            const int Result = testaUltimoElementoLista(l1);
            CHECK_EQUAL(3, Result);
        }

        TEST(testaSeparaLista_ValorUltimoElementoLista2)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result2 = testaUltimoElementoLista(l2);
            CHECK_EQUAL(3, Result2);
        }

        TEST(testaSeparaLista_ValorPrimeiroElementoLista1)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result = testaPrimeiroElementoLista(l1);
            CHECK_EQUAL(2, Result);
        }
        TEST(testaSeparaLista_ValorPrimeiroElementoLista2)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result2 = testaPrimeiroElementoLista(l2);
            CHECK_EQUAL(8, Result2);
        }

        TEST(testaConcatenaLista_ValorPrimeiroElementoLista1)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            l1 = concatena(l1,l2);
            const int Result1 = testaUltimoElementoLista(l1);
            CHECK_EQUAL(3, Result1);
        }

        TEST(testaRetiraPrefixoLista_ValorPrimeiroElementoLista)
        {
            struct lista * l1 = NULL;
            int vetor[]={3,8,1,7,2,9,19,38,49,8,93,1723,28,398,19,72,93,128,193};
            l1 = constroi(sizeof(vetor)/sizeof(int), vetor);
            l1 = retira_prefixo(l1,3);
            const int Result1 = testaPrimeiroElementoLista(l1);
            CHECK_EQUAL(72, Result1);
        }

    }
