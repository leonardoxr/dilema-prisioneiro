#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

//Tamanho da população da matriz n x n
#define n_ 50

double sum_matrix(int matrix[][n_],int n);
double fermi_dirac(double p1, double p2, double k);
double PD_DILEMMA(double b, double c, double k, int n, int gen_num, double freq_coop,double ratio);


void main()
{
    double b,c,k,freq_coop;
    int n,gen_num;

    FILE *arq;
    arq = fopen("results.txt","w+");

    k = 0.1;
    n = n_;

    //Beneficio em cooperar
    b = 2;

    //Custo em cooperar
    c = 1;

    //Numero de geracoes
    gen_num = 1000;

    //Frequencia de cooperadores inicialmente
    freq_coop = 0.5;

    double ratio = c / (b-c);
    printf("%lf\n", ratio);
    double media = PD_DILEMMA(b,c,k,n,gen_num,freq_coop,ratio);
    printf("%lf\n",media);


}
double PD_DILEMMA(double b, double c, double k, int n, int gen_num, double freq_coop,double ratio)
{
    srand( (unsigned) time(NULL));

    char filename1[64],filename2[64],filename3[64];
    sprintf(filename1, "COOP_FREQ_B_%.2lf__C_%.2lf.txt", b,c);
    sprintf(filename2, "INITIAL_MATRIX_B_%.2lf__C_%.2lf.txt", b,c);
    sprintf(filename3, "FINAL_MATRIX_B_%.2lf__C_%.2lf.txt", b,c);


    FILE *arq,*arq2,*arq3;
    arq = fopen(filename1,"w+");
    arq2 = fopen(filename2,"w+");
    arq3 = fopen(filename3,"w+");

    double R,T,S,P,num_compet;
    double payoff_matrix[2][2];
    int i,j;
    double w,p1,p2;
    int pop[n][n];
    double sum = 0,sum2=0;

    num_compet = gen_num * n;

    //reward
    R = b-c;

    //temptation
    T = b;

    //sucker's payoff
    S = -c;

    //punishment
    P = 0;

    payoff_matrix[0][0] = P;

    payoff_matrix[0][1] = T;

    payoff_matrix[1][0] = S;

    payoff_matrix[1][1] = R;



    // 0  for defectors
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            double temp = rand() / (RAND_MAX + 1.0);

            if(temp < freq_coop)
                pop[i][j] = 1;
            else
                pop[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            fprintf(arq2,"%d ",pop[i][j]);

        }
        fprintf(arq2,"\n");
    }

    fclose(arq2);



    sum = sum_matrix(pop,n)/(double)n;

    fprintf(arq,"%d %lf\n",0,sum);



    for(i = 1; i <= num_compet; i++)
    {
        int x[2],y[2];
        x[0] = (n) * rand() / (RAND_MAX + 1.0) ;
        x[1] = (n) * rand() / (RAND_MAX + 1.0) ;

        int vizin[4][2];

        if(x[0] == 0)
        {
            vizin[0][0] = n-1;
            vizin[1][0] = x[0]+1;
            vizin[2][0] = x[0];
            vizin[3][0] = x[0];
        }
        else if(x[0] == n-1)
        {
            vizin[0][0] = x[0]-1;
            vizin[1][0] = 0;
            vizin[2][0] = x[0];
            vizin[3][0] = x[0];
        }
        else
        {
            vizin[0][0] = x[0]-1;
            vizin[1][0] = x[0]+1;
            vizin[2][0] = x[0];
            vizin[3][0] = x[0];
        }
        ////////
        if(x[1] == 0)
        {
            vizin[0][1] = x[1];
            vizin[1][1] = x[1];
            vizin[2][1] = n-1;
            vizin[3][1] = x[1]+1;
        }
        else if(x[1] == n-1)
        {
            vizin[0][1] = x[1];
            vizin[1][1] = x[1];
            vizin[2][1] = x[1]-1;
            vizin[3][1] = 0;

        }
        else
        {

            vizin[0][1] = x[1];
            vizin[1][1] = x[1];
            vizin[2][1] = x[1]-1;
            vizin[3][1] = x[1]+1;
        }

        p1=0;
        for(int l = 0; l < 4; l++)
        {
            p1 += payoff_matrix[pop[x[0]][x[1]]][pop[vizin[l][0]][vizin[l][1]]];
        }



        int temp = 4 * rand() / (RAND_MAX + 1.0);

        y[0] = vizin[temp][0];
        y[1] = vizin[temp][1];

        if(y[0] == 0)
        {
            vizin[0][0] = n-1;
            vizin[1][0] = y[0]+1;
            vizin[2][0] = y[0];
            vizin[3][0] = y[0];
        }
        else if(y[0] == n-1)
        {
            vizin[0][0] = y[0]-1;
            vizin[1][0] = 0;
            vizin[2][0] = y[0];
            vizin[3][0] = y[0];
        }
        else
        {
            vizin[0][0] = y[0]-1;
            vizin[1][0] = y[0]+1;
            vizin[2][0] = y[0];
            vizin[3][0] = y[0];
        }
        ////////
        if(y[1] == 0)
        {
            vizin[0][1] = y[1];
            vizin[1][1] = y[1];
            vizin[2][1] = n-1;
            vizin[3][1] = y[1]+1;
        }
        else if(y[0] == n-1)
        {
            vizin[0][1] = y[1];
            vizin[1][1] = y[1];
            vizin[2][1] = y[1]-1;
            vizin[3][1] = 0;

        }
        else
        {

            vizin[0][1] = y[1];
            vizin[1][1] = y[1];
            vizin[2][1] = y[1]-1;
            vizin[3][1] = y[1]+1;
        }


        p2=0;
        for(int l = 0; l < 4; l++)
        {
            p2 += payoff_matrix[pop[y[0]][y[1]]][pop[vizin[l][0]][vizin[l][1]]];
        }

        //Competir para ver se p1 assume a estrategia de p2
        w = fermi_dirac(p1, p2, k);

        if(w >= (rand() / (RAND_MAX + 1.0) ))
        {
            pop[x[0]][x[1]] = pop[y[0]][y[1]];
        }

        sum = sum_matrix(pop,n)/(double)n;
        fprintf(arq,"%d %lf\n",i,sum);
        sum2+=sum;
    }

    fclose(arq);


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            fprintf(arq3,"%d ",pop[i][j]);

        }
        fprintf(arq3,"\n");
    }

    fclose(arq3);


    return (sum2/100.);


}

double sum_matrix(int matrix[][n_],int n)
{
    double sum = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            sum += matrix[i][j];

        }
    }
    return sum;


}

double fermi_dirac(double p1, double p2, double k)
{
    double f;
    f = 1.0 / (1.0 + exp((p1 - p2) / k));
    return f;
}
