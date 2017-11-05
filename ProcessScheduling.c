#include<stdio.h>
void fcfs(int [],int ,int []);
void print(int [],int ,int [],int [],int [],int,int);

void priority(int processes[],int n,int bt[], int order[])
{
	int temp,j;

	for(int i =0;i < n; i++)
	{
		for (j = i; j < n-i ; j++)
		{
			if (order[i] < order[i+1])
			{
				temp = order[i];
				order[i] = order[i+1];
				order[i+1] = temp;

				temp = bt[i];
				bt[i] = bt[i+1];
				bt[i+1] = temp;
				
				temp = processes[i];
				processes[i] = processes[i+1];
				processes[i+1] = temp;
			}
		}
	}
    fcfs(processes,n,bt);
}

void RounRobin(int processes[],int n,int bt[],int quant)
{
	int i,cbt[n],flag = 1,wt[n],tat[n],awt,atat,t = 0;
	wt[n]  =0;
	tat[n] = 0;

	for (i = 0; i < n; i++)
	{
		cbt[i] = bt[i];	
	}

	while(flag)
	{
		flag = 0;
		for (i = 0; i < n; i++)
		{
			printf("in\n");
			if(cbt[i] > 0)
			{	
				flag = 1;
				printf("in\n");
				flag = 1;
				if(cbt[i] > quant)
				{
					t += quant;
					cbt[i] -= quant;
					printf("waiting time of %d:%d\n",i,t);
				}
				else
				{
					t = t + cbt[i];
					wt[i] = t - bt[i];
					cbt[i] = 0;
					tat[i] = wt[i] + bt[i];
					awt += wt[i];
					atat += tat[i];
					printf("final waiting time of %d:%d\n",i,wt[i]);
				}
			}
		}
	}
	awt = awt/n;
	atat = atat/n;
	print(processes,n,bt,wt,tat,awt,atat);
}
void sjf(int processes[],int n,int bt[])
{
	int temp;

	for(int i =0;i < n; i++)
	{
		for (int j = 0; j <n-i ; j++)
		{
			if (bt[i] > bt[i+1])
			{
				temp = bt[i];
				bt[i] = bt[i+1];
				bt[i+1] = temp;
				
				temp = processes[i];
				processes[i] = processes[i+1];
				processes[i+1] = temp;
			}
		}
	}
    fcfs(processes,n,bt);
}

void print(int processes[],int n,int bt[],int wt[],int tat[],int awt,int atat)
{
	printf("processe no\t\tburst time\t\twait time\t\t turn around time\n");
	for (int i = 0; i < n; ++i)
	{
		printf("\t%d\t\t%d\t\t\t\t%d\t\t%d\t\t\n",processes[i],bt[i],wt[i],tat[i]);


	}
	printf("\n");
}

void fcfs(int processes[],int n,int bt[])
{
	int wt[n],tat[10],awt=0,atat=0;

	wt[0] = 0;
	for (int i = 0; i < n; i++)
	{
		wt[i+1]  = wt[i] + bt[i];
		awt += wt[i];
		tat[i] = wt[i] + bt[i];
		atat += tat[i];
	}
	awt = awt/n;
	atat = atat/n;

	print(processes,n,bt,wt,tat,awt,atat);
}

int main()

{    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
	int  burst_time[] = {10, 5, 8};
	int order[] = {3 , 1, 2};
	priority(processes, n,  burst_time, order);
 	 //RounRobin(processes, n,  burst_time,2);
    //sjf(processes, n,  burst_time);
    return 0;
}
