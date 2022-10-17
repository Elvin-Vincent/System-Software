#include<stdio.h>
int main()
{
    int n, i, cpyn, ts, gtime= 0;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], tat[n], wt[n], remain[n], tottat= 0, totwt= 0; 
    float avgtat, avgwt;

    printf("Enter the Timeslice: ");
    scanf("%d", &ts);
    cpyn= n;

    printf("Burst times:\n");
    for(i= 0; i< n; i++)
    {
        scanf("%d", &bt[i]);
        p[i]= i;
        remain[i]= bt[i];
    }

    for(i= 0; cpyn != 0; i= (i+ 1)% n)
    {
        if((remain[i] <= ts) && (remain[i]> 0))
        {
            gtime += remain[i];
            remain[i]= 0;
            cpyn--;


            tat[i]= gtime; 
            wt[i]= tat[i]- bt[i]; 

            tottat += tat[i];
            totwt += wt[i];
        }
        else if(remain[i]> 0)
        {
            gtime += ts;
            remain[i] -= ts; 
        }
    }
    avgtat= (float)tottat/ n;
    avgwt= (float)totwt/ n;

    printf("Process\tBT\tTAT\tWT\n");
    for(i= 0; i< n; i++)
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], tat[i], wt[i]);
    printf("\nAvg TAT: %f", avgtat);
    printf("\nAvg WT: %f\n", avgwt);
}
