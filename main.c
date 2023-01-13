#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void printmatrix(int **M,int R,int S);
void automatrix(int **A,int **B,int R,int S);
void fillmatrix(int **A,int **B,int R,int S);
void mrproper(int **A,int **B,int **C,int **T,int R,int S);
int max(int **A,int R,int S);
int transpon(int **B,int **T,int R,int S);
int dobutok(int **A,int **B,int **C,int R,int S);
int sortin(int **A,int sort,int R,int S);
int summ(int **A,int **B,int sum,int R,int S);

int main()
{

    int choice;
    int sort;
    int sum;
    int dija;
    int R=3;
    int S=4;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    for(int r=0; r<5; r++)
    {
        int **A = NULL;
        A=(int**) malloc(R * sizeof(int));
        for(int i=0; i<R; i++)
        {
            A[i]=(int*) malloc(R * sizeof(int));
        }

        int **B=NULL;
        B=(int**) malloc(S * sizeof(int));

        int **C=NULL;
        C=(int**) malloc(S * sizeof(int));

        int **T=NULL;
        T=(int**) malloc(R * sizeof(int));

        for(int i=0; i<S; i++)
        {
            B[i]=(int*) malloc(R * sizeof(int));
            C[i]=(int*) malloc(R * sizeof(int));
            T[i]=(int*) malloc(R * sizeof(int));
        }


        printf(" Створити матрицю?\n\n Автоматично-1\n Ведення власноруч-2\n\n");
        scanf("%d",&choice);

        if (choice==2)
        {
            printf("\nКількість рядків: ");
            scanf("%d",&R);
            printf("\nКількість стовпців: ");
            scanf("%d",&S);
        }

        if(choice==2)
            fillmatrix(A,B,R,S);
        else
            automatrix(A,B,R,S);

        printmatrix(A,R,R);
        printmatrix(B,R,S);

        do
        {
            printf("\nДii над  матрицями:\n1. максимум А \n2. транспонувати B\n3. помножити AxB\n4. сортувати рядок A\n5. показати суму\n");
            scanf("%d",&dija);
        }
        while(dija != 1 && dija != 2 && dija != 3 && dija != 4 && dija != 5);

        switch(dija)
        {
        case 1:
            max(A,R,S);
            break;

        case 2:
            transpon(B,T,R,S);
            break;

        case 3:
            printf("AxB = \n");
            dobutok(A,B,C,R,S);
            printmatrix(C,R,S);
            break;

        case 4:
            printf("\nВедiть номер рядка для сортування: ");
            scanf("%d",&sort);
            sortin(A,sort,R,S);
            break;

        case 5:
            summ(A,B,sum,R,S);
            break;

            mrproper(A,B,C,T,R,S);

            printf("\n\n");
        }
        return 0;
    }
}

void fillmatrix(int **A,int **B,int R,int S)
{
    printf("Заповніть квадратну матрицю:\n");
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<R; j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Заповншть прямокутну матрицю:\n");
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<S; j++)
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
}

void automatrix(int **A,int **B,int R,int S)
{
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<R; j++)
        {
            A[i][j]= rand()%25;
        }
    }
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<S; j++)
        {
            B[i][j]= rand()%25;
        }
    }
}

void printmatrix(int **M,int R,int S)
{
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<S; j++)
        {
            printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mrproper(int **A,int **B,int **C,int **T,int R,int S)
{
    for(int i=0; i<1; i++)
    {
        free(A[i]);
    }
    free(A);
    for(int i=0; i<S; i++)
    {
        free(B[i]);
        free(C[i]);
        free(T[i]);
    }
    free(B);
    free(C);
    free(T);
}

int max(int **A,int R,int S)
{
    int maximal= 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<R; j++)
        {
            if (A[i][j] > maximal)
            {
                maximal = A[i][j];
            }
        }
    }
    printf("\nМаксимальне значення матрицi А: %d\n",maximal);
}

int transpon(int **B,int **T,int R,int S)
{
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<S; j++)
        {
            T[j][i] = B[i][j];
        }
    }
    printf("\n Транспонована матриця B :  \n");
    printmatrix(T,S,R);
}

int dobutok(int **A,int **B,int **C,int R,int S)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<S; j++)
        {
            C[i][j]=0;
            for(int p=0; p<R; p++)
            {
                C[i][j] += A[i][p] * B[p][j];
            }
        }
    }
}

int sortin(int **A,int sort,int R,int S)
{
    int temp;
    for(int k=1; k<R; k++)
    {
        for(int j=0; j<R-k; j++)
        {

            if(A[sort][j]>A[sort][j+1])
            {
                temp = A[sort][j];
                A[sort][j] = A[sort][j+1];
                A[sort][j+1] = temp;
            }
        }
    }
    for(int j=0; j<R; j++)
    {
        printf("%3d ",A[sort][j]);
    }
}

int summ(int **A,int **B,int sum,int R,int S)
{
    for(int i=0; i<R; i++)
    {
        sum=0;
        for(int j=0; j<R; j++)
        {
            sum = sum + A[i][j];
        }
        printf("\n%d Сумма eлементiв рядкiв матрицi А =%d",i,sum);
    }
    for(int j=0; j<S; j++)
    {
        sum=0;
        for(int i=0; i<R; i++)
        {
            sum = sum + B[i][j];
        }
        printf("\n%d Сумма eлементiв стовбцiв матрицi В =%d",j,sum);
    }
}
