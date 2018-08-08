#include <stdio.h>
#include <stdlib.h>

int exibe(int *vetor, int n);
int insere (int vet[], int n);
int buble (int *vetor, int n);
int insertion (int *vetor, int n);
int select (int *vetor, int n);
int mergesort (int vetor[], int n);
int msort (int vetor[], int aux[], int esq, int dir);
int intercala(int vet[], int aux[], int ini1, int ini2, int fim2);
int decrescente (int vet[], int n);
int menu (void);

int main(void)
{
    //Variaveis
   int *vet;
   int i, n, m, x;
   char q;

   //Alocação e inicialização
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &n);
   vet=malloc(n*sizeof(int));
   for (i=0; i<n; i++)
    {
        vet[i]=0;
    }

    //Inserção
    printf("\n");
    printf("Digite os valores do vetor:\n");
    insere(vet, n);
    exibe(vet, n);

    //Menu de ordenação e busca
    menu();
    printf("Digite o metodo: ");
    scanf("%d", &m);
    if (m==1)
    {
        buble(vet, n+1);
    }
    else if (m==2)
    {
        insertion(vet, n+1);
    }
    else if (m==3)
    {
        select(vet, n);
    }
    else if (m==4)
    {
        mergesort(vet, n);
    }
    else
    {
        printf("\n");
        printf("Opcao invalida\n");
        return -1;
    }

    //Exibicao de ordenados
    printf("\n");
    printf("Valores ordenados:\n");
    exibe(vet, n);
    printf("\n");
    printf("Buscar valor? (S/N)\n");
    scanf("%s", &q);
    printf("\n");
    if ((q=='S') || (q=='s'))
    {
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &x);
        busca(vet, n, x);
        return 0;
    }
    return 0;
}

int exibe(int vet[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%3d", vet[i]);
    }
}

int insere (int vet[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        scanf("%d", &vet[i]);
    }
}

int menu (void)
{
    printf("\n");
    printf("Digite o codigo do metodo de ordenacao a ser usado no vetor. Ou se deseja buscar um valor no vetor\n");
    printf("1:Buble Sort\n");
    printf("2:Insertion Sort\n");
    printf("3:Select Sort\n");
    printf("4:Merge Sort\n");
}

//Metodo 1
int buble (int vetor[], int n)
{
    int aux, i=0, j=0;
    char q;
    printf("\n");
    printf("(C)rescente ou (D)ecrescente?\n");
    scanf("%s", &q);
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<(n-i-2); j++)
        {
            if (vetor[j]>vetor[j+1])
            {
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    }
    if ((q=='d') || q=='D')
    {
        decrescente(vetor, n);
    }
}

//Metodo 2
int insertion (int vetor[], int n)
{
    int temp, i, j;
    char q;
    printf("\n");
    printf("(C)rescente ou (D)ecrescente?\n");
    scanf("%s", &q);
    for (i=1; i<n-1; i++)
    {
        temp=vetor[i];
        j=i-1;
        while ((j>=0) && (vetor[j]>temp))
            {
                vetor[j+1]=vetor[j];
                j--;
            }
        vetor[j+1]=temp;
    }
    if ((q=='d') || q=='D')
    {
        decrescente(vetor, n);
    }
}

//Metodo 3
int select (int vetor[], int n)
{
    int min, i, j, x;
    char q;
    printf("\n");
    printf("(C)rescente ou (D)ecrescente?\n");
    scanf("%s", &q);
    for (i=0; i<(n-1); i++)
    {
        min=i;
        for (j=(i+1); j<n; j++)
        {
            if (vetor[j]<vetor[min])
            {
                min=j;
            }
        }
        if (i!=min)
        {
            x=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=x;
        }
    }
    if ((q=='d') || q=='D')
    {
        decrescente(vetor, n+1);
    }
}

//Metodo 4
int mergesort (int vetor[], int n)
{
    int *aux, i;
    char q;
    printf("\n");
    printf("(C)rescente ou (D)ecrescente?\n");
    scanf("%s", &q);
    aux=malloc(n*(sizeof(int)));
    int esq=0, dir=n-1;
    for (i=0; i<n; i++)
    {
        aux[i]=0;
    }
    msort(vetor, aux, esq, dir);
    if ((q=='d') || q=='D')
    {
        decrescente(vetor, n+1);
    }
}

int msort (int vetor[], int aux[], int esq, int dir)
{
    int meio;
    if (esq<dir)
    {
        meio=(esq+dir)/2;
        msort(vetor,aux,esq,meio);
        msort(vetor,aux,meio+1,dir);
        intercala(vetor,aux,esq,meio+1,dir);
    }
}

int intercala(int vet[], int aux[], int ini1, int ini2, int fim2)
{
    int in1=ini1, in2=ini2, fim1=in2-1, au=0, i;
    while (in1<=fim1 && in2<=fim2)
    {
        if (vet[in1]<vet[in2])
        {
            aux[au++]=vet[in1++];
        }
        else
        {
            aux[au++]=vet[in2++];
        }
    }
    while (in1<=fim1)
    {
        aux[au++]=vet[in1++];
    }
    while (in2<=fim2)
    {
        aux[au++]=vet[in2++];
    }
    for (i=0; i<au; i++)
    {
        vet[i+ini1]=aux[i];
    }
}

//Metodo de busca
int busca (int vetor[], int n, int x)
{
    int i=0, f=n-1, m;
    while (i<=f)
    {
        m=(i+f)/2;
        if (x==vetor[m])
        {
            printf("\n");
            printf("Valor encontrado\n");
            return 0;
        }
        else if (x<vetor[m])
        {
            f=m-1;
        }
        else if (x>vetor[m])
        {
            i=m+1;
        }
    }
    printf("\n");
    printf("Valor nao encontrado\n");
    return -1;
}

int decrescente (int vet[], int n)
{
    int *vetaux;
    int i, j=n;
    vetaux=malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        vetaux[i]=vet[i];
    }
    for (i=0; i<n; i++)
    {
        vet[i]=vetaux[j-2];
        j--;
    }
}
