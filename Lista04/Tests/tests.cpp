#include "UnitTestPP.h"
#include "../headers/funcoes.h"

    namespace
    {


        TEST(testaSeparaLista_ValorUltimoElementoLista1)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result = testaSepara_UltimoElementoLista(l1);
            CHECK_EQUAL(1, Result);
        }
        TEST(testaSeparaLista_ValorUltimoElementoLista2)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result2 = testaSepara_UltimoElementoLista(l2);
            CHECK_EQUAL(3, Result2);
        }

        TEST(testaSeparaLista_ValorPrimeiroElementoLista1)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result = testaSepara_PrimeiroElementoLista(l1);
            CHECK_EQUAL(2, Result);
        }
        TEST(testaSeparaLista_ValorPrimeiroElementoLista2)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[5]={3,8,1,7,2};
            l1 = constroi(5, vetor);
            l2 = separa(l1,1);
            const int Result2 = testaSepara_PrimeiroElementoLista(l2);
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
            const int Result1 = testaSepara_UltimoElementoLista(l1);
            CHECK_EQUAL(3, Result1);
        }

        TEST(testaRetiraPrefixoLista_ValorPrimeiroElementoLista)
        {
            struct lista * l1 = NULL;
            struct lista * l2 = NULL;
            int vetor[]={3,8,1,7,2,9,19,38,49,8,93,1723,28,398,19,72,93,128,193};
            l1 = constroi(sizeof(vetor)/sizeof(int), vetor);
            l1 = retira_prefixo(l1,3);
            const int Result1 = testaRetiraPrefixo_PrimeiroElementoLista(l1);
            CHECK_EQUAL(72, Result1);
        }

    }
