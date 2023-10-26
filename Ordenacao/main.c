#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ordenacao bolha - Versao 1 */
void bolha1 (int n, int* v)
{
int i,j;
for (i=n-1; i>=1; i--)
    for (j=0; j<i; j++)
        if (v[j]>v[j+1]) { /* troca */
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
        }
}

/* Ordenacao bolha - Versao 2 - Otimizada*/
void bolha2 (int n, int* v)
{
    int i, j;
    for (i=n-1; i>0; i--) {
        int troca = 0;
        for (j=0; j<i; j++)
            if (v[j]>v[j+1])
            { /* troca */
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1;
            }
        if (troca == 0) /* nao houve troca */
        return;
    }
}

/* Ordenação bolha - Versao Recursiva */
void bolha_rec (int n, int* v)
{
    int j;
    int troca = 0;
    for (j=0; j<n-1; j++)
    if (v[j]>v[j+1]) { /* troca */
        int temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
        troca = 1;
    }
    if (troca != 0) /* houve troca */
        bolha_rec(n-1,v);
}

void* acessa (void* v, int i, int tam)
{
    char* t = (char*)v;
    t += tam*i;
    return (void*)t;
}

void troca (void* a, void* b, int tam)
{
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i;
    for (i=0; i<tam; i++)
    {
        char temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}

int compara_reais (void* a, void* b)
{
    float* p1 = (float*) a;
    float* p2 = (float*) b;
    float f1 = *p1;
    float f2 = *p2;
    if (f1 > f2)
        return 1;
    else
        return 0;
}

/* Ordenação bolha (genérica) */
void bolha_gen (int n, void* v, int tam, int(*cmp)(void*,void*))
{
    int i, j;
    for (i=n-1; i>0; i--)
    {
        int fez_troca = 0;
        for (j=0; j<i; j++)
        {
            void* p1 = acessa(v,j,tam);
            void* p2 = acessa(v,j+1,tam);
            if (cmp(p1,p2))
            troca(p1,p2,tam);
            fez_troca = 1;
        }
        if (fez_troca == 0) /* nao houve troca */
        return;
    }
}

/* Ordenação rápida */
void rapida (int n, int* v)
{
    if (n <= 1)
        return;
    else
    {
        int x = v[0];
        int a = 1;
        int b = n-1;
        do {
            while (a < n && v[a] <= x) a++;
            while (v[b] > x) b--;
            if (a < b)
            { /* faz troca */
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++; b--;
            }
        } while (a <= b);
        /* troca pivô */
        v[0] = v[b];
        v[b] = x;
        /* ordena sub-vetores restantes */
        rapida(b,v);
        rapida(n-a,&v[a]);
    }
}

int comparador(int *x, int *y)
{
    if (*x > *y)
        return 1;
    else if (*x == *y)
        return 0;
    else if (*x < *y)
        return -1;
}


void quick_sort(int *v)
{
    //ordena o array
   qsort(v, 5, sizeof(int), comparador);
}

imprimeVetorInt(int n, int *v)
{
    for(int i=0; i<n;i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n\n");
}
imprimeVetorFloat(int n, float *v)
{
    for(int i=0; i<n;i++)
    {
        printf("%7.2f, ", v[i]);
    }
    printf("\n\n");
}

const int NEL = 10;

int main()
{
    int vetor1[NEL];
    int vetor2[NEL];
    int vetor3[NEL];
    int vetor4[NEL];
    int vetor5[NEL];
    float vetor6[NEL];// = {5.5,6.7,8.5,9.1,6.0,6.5,8.0,7.7,5.9,10.0};

    srand(time(NULL));

    for(int i=0 ; i < NEL ; i++)
    {
        vetor1[i]= rand() % 32767;
        vetor2[i]= rand();
        vetor3[i]= rand();
        vetor4[i]= rand();
        vetor5[i]= rand();
        vetor6[i]= rand()/3.0;
    }

    printf("1.1) Metodo bolha (versao1)\n");
    bolha1(NEL,vetor1);
    //imprimeVetorInt(sizeof(vetor1)/sizeof(int), vetor1);
    printf("1.2) Metodo bolha (versao2)\n");
    bolha2(NEL,vetor2);
    //imprimeVetorInt(sizeof(vetor2)/sizeof(int), vetor2);
    printf("1.3) Metodo bolha (recursivo)\n");
    bolha_rec(NEL,vetor3);
    //imprimeVetorInt(sizeof(vetor3)/sizeof(int), vetor3);
    printf("1.4) Metodo bolha (generico)\n");
    bolha_gen(NEL,vetor6,sizeof(float),compara_reais);
    //imprimeVetorFloat(NEL, vetor6);
    printf("2.1) Metodo rapido(implementacao propria)\n");
    rapida(NEL,vetor4);
    //imprimeVetorInt(sizeof(vetor4)/sizeof(int), vetor4);
    printf("2.2) Metodo qsort(padrao da linguagem C)\n");
    quick_sort(vetor5);
    //imprimeVetorInt(sizeof(vetor4)/sizeof(int), vetor4);

    printf("\n===================F I M====================\n");
}
