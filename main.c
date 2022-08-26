#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void vetor_random(int vet[], int N)
{
    for (int i = 0; i < N; i++)
    {
        vet[i]=rand()%1000;
    }
}

void print_vet(int vet[], int N)
{
    for(int i=0; i<N; i++)
    {
        if (i%7==0)
            printf("\n");
        printf("\t[%3d]: %3d", i+1, vet[i]);
    }
}

void Bubble_Sort(int vet[], int N)
{
    int aux, i, contador;


    for (contador = 1; contador < N; contador++)
    {
        for (i = 0; i < N - 1; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
    print_vet(vet,N);
}

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;


    i = left;
    j = right;
    x = a[(left + right) / 2];


    while(i <= j)
    {
        while(a[i] < x && i < right)
        {
            i++;
        }
        while(a[j] > x && j > left)
        {
            j--;
        }
        if(i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }


    if(j > left)
    {
        quick_sort(a, left, j);
    }
    if(i < right)
    {
        quick_sort(a, i, right);
    }


}
float media_vet(int vet[], int N)
{
    float media;
    for(int i=0; i<N; i++)
    {
        media += vet[i];
    }
    return media/N;
}

void mediana_vet(int v[], int N)
{
    int aux;
    float mediana;

    for(int i=0; i<N-1; i++)
    {
        for(int j=i+1; j<N; j++)
        {

            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    if(N%2)
    {
        mediana = v[N/2];
    }
    else
    {
        mediana = (v[N/2-1]+v[N/2])/2;
    }
    printf("\n\nMediana: %2.1f \n", mediana);
}

int main()
{
    int Vrand[1000];
    int N=1000, MA, ME;
    int menu;
    float media;

    printf("Gerando 1000 valores aleatorios:\n\n");
    vetor_random(Vrand,N);
    print_vet(Vrand,N);

    do
    {
        printf("\n\nDigite uma das opcoes:\n\t[1]: Bubble Sort\n\t[2]: Quick Sort__");
        scanf("%d", &menu);
    }
    while(menu!=1 && menu!=2);

    switch(menu)
    {
    case 1:
        printf("\n\n\nBubble Sort:\n");
        Bubble_Sort(Vrand,N);

    case 2:
        printf("\n\n\nQuick Sort:\n");
        quick_sort(Vrand, 0, N - 1);
        print_vet(Vrand,N);
    }

    media = media_vet(Vrand,N);
    printf("\n\nMedia: %.3f", media);

    mediana_vet(Vrand, N);

    MA = maior(Vrand,N);
    printf("\nMaior: %d", MA);

    ME = menor(Vrand,N);
    printf("\tMenor: %d ", ME);

    getch();
    return 0;
}
