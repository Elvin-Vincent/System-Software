#include<stdio.h>
int main()
{
	int i,j,temp,n,pr[100],p[100],bt[100],tat[100],wt[100],tottat=0,totwt=0;
	float avgtat,avgwt;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	printf("Enter the priority time\n");
	for(i=0;i<n;i++)
	
		scanf("%d",&pr[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(pr[j]>pr[j+1])
			{
				temp=pr[j];
				pr[j]=bt[j+1];
				pr[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
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
	printf("Process\tBt\tpr\tTAT\tWT\n");
	for(i=0;i<n;i++)
	printf("%d\t%d\t%d\t%d\t%d\t\n",p[i],bt[i],pr[i],tat[i],wt[i]);
	printf("Average TAT= %f\n",avgtat);
	printf("Average WT= %f",avgwt);
	return 0;
}
