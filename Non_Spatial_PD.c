#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

double sum_array(int array[],int n);

void main()
{

    srand( (unsigned) time(NULL));
    FILE *arq;
    arq = fopen("FreqCoop.txt","w+");

    double b,c,R,T,S,P,gen_num,freq_coop,num_compet;
    double payoff_matrix[2][2],alpha;
    int i,n,j;
    n = 1000;
    double w,p1,p2;
    int pop[n],samples[4];
    double sum = 0;


    b = 2;
    c = 1;
    gen_num = 50;
    freq_coop = 0.5 ;

    num_compet = gen_num * n;

    double ratio = c / (b-c);
    // Prisoner's dilemma (PD): 	( R,  T,  S,  P ) = ( b-c,    b,  -c,   0 )

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

//α = max(R, T, S, P) − min(R, T, S, P), e
    alpha = T-S;

    // 0  for defectors
    for(i = 0; i < n; i++)
    {
        double temp = rand() / (RAND_MAX + 1.0);

        if(temp < freq_coop)
            pop[i] = 1;
        else
            pop[i] = 0;
    }






    sum = sum_array(pop,n)/(double)n;

    fprintf(arq,"%d %lf\n",0,sum);


    for(i = 1; i < num_compet; i++)
    {

        samples[0] = n * rand() / (RAND_MAX + 1.0);
        samples[1] = n * rand() / (RAND_MAX + 1.0);
        samples[2] = n * rand() / (RAND_MAX + 1.0);
        samples[3] = n * rand() / (RAND_MAX + 1.0);


        p1 = payoff_matrix[pop[samples[0]]][pop[samples[1]]];
        p2 = payoff_matrix[pop[samples[2]]][pop[samples[3]]];


        w = (p2-p1) / alpha;
        if(w <= 0)
            w = 0;

        if(w > (rand() / (RAND_MAX + 1.0) ))
        {
            pop[samples[0]] = pop[samples[2]];
        }



        sum = sum_array(pop,n)/(double)n;


        fprintf(arq,"%d %lf\n",i,sum);

    }


}

double sum_array(int array[],int n)
{
    double sum = 0;
    for(int j = 0; j < n; j++)
    {

        sum += array[j];

    }

    return sum;


}
