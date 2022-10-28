#include<stdio.h>
int main()
{
	int i,n,p[100],bt[100],tat[100],wt[100],tottat=0,totwt=0;
	float avgtat,avgwt;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
	if(i==0)
	tat[i]=bt[i];
	else
	tat[i]=tat[i-1]+bt[i];
	tottat=tottat+tat[i];
	wt[i]=tat[i]-bt[i];
	totwt=totwt+wt[i];
	}
	avgtat=(float)tottat/n;
	avgwt=(float)totwt/n;
	printf("Process\tBt\tTAT\tWT\n");
	for(i=0;i<n;i++)
	printf("%d\t%d\t%d\t%d\t\n",p[i],bt[i],tat[i],wt[i]);
	printf("Average TAT= %f\n",avgtat);
	printf("Average WT= %f",avgwt);
	return 0;
}
	
	
	
