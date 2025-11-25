/**
 * Non-Spatial Prisoner's Dilemma Simulation
 *
 * This program simulates the evolution of cooperation in a well-mixed population
 * using the Prisoner's Dilemma game. Agents are randomly selected to compete,
 * and strategies spread based on payoff differences.
 *
 * Key features:
 * - Well-mixed population (no spatial structure)
 * - Random pair selection
 * - Strategy adoption based on payoff difference
 * - Outputs cooperation frequency over generations
 *
 * Output: FreqCoop.txt - contains [generation] [cooperation_frequency] data
 *
 * College project - for educational purposes
 */

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

    // Prisoner's Dilemma Payoff Matrix
    // ( R,  T,  S,  P ) = ( b-c,  b,  -c,  0 )
    //
    // Rows/Cols: [0] = Defect, [1] = Cooperate
    //
    //           | Defect | Cooperate
    // ---------------------------------
    // Defect    |   P    |     T
    // Cooperate |   S    |     R

    R = b-c;    // Reward for mutual cooperation
    T = b;      // Temptation to defect
    S = -c;     // Sucker's payoff (cooperate while opponent defects)
    P = 0;      // Punishment for mutual defection

    payoff_matrix[0][0] = P;

    payoff_matrix[0][1] = T;

    payoff_matrix[1][0] = S;

    payoff_matrix[1][1] = R;

//α = max(R, T, S, P) − min(R, T, S, P), e
    alpha = T-S;

    // Initialize population: 0 = defector, 1 = cooperator
    // Randomly assign strategies based on initial cooperation frequency
    for(i = 0; i < n; i++)
    {
        double temp = rand() / (RAND_MAX + 1.0);

        if(temp < freq_coop)
            pop[i] = 1;    // Cooperator
        else
            pop[i] = 0;    // Defector
    }






    sum = sum_array(pop,n)/(double)n;

    fprintf(arq,"%d %lf\n",0,sum);


    // Evolution loop: agents compete and update strategies
    for(i = 1; i < num_compet; i++)
    {
        // Randomly select 4 agents: two pairs for competition
        samples[0] = n * rand() / (RAND_MAX + 1.0);  // Agent 1 (focal)
        samples[1] = n * rand() / (RAND_MAX + 1.0);  // Agent 1's opponent
        samples[2] = n * rand() / (RAND_MAX + 1.0);  // Agent 2 (model)
        samples[3] = n * rand() / (RAND_MAX + 1.0);  // Agent 2's opponent

        // Calculate payoffs for each pair
        p1 = payoff_matrix[pop[samples[0]]][pop[samples[1]]];
        p2 = payoff_matrix[pop[samples[2]]][pop[samples[3]]];

        // Calculate probability of strategy adoption
        // If p2 > p1, agent 1 may adopt agent 2's strategy
        w = (p2-p1) / alpha;
        if(w <= 0)
            w = 0;

        // Agent 1 adopts agent 2's strategy with probability w
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
