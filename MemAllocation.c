#include<stdio.h>

void worstfit(int blockSize[],int m,int processSize[],int n)
{
	int i,j,allocate[n],idx;

	for (i = 0; i < n; i++)
	{
		allocate[i] = -1;
	}
	for(i = 0 ; i < n ; i++)
	{
		idx = -1;
		for (j = 0; j < m; j++)
		{
			if(blockSize[j] >= processSize[i])
			{
				if(idx == -1)
					idx = j;
				else if(blockSize[idx] < blockSize[j])
					idx = j;
			}
		}
		if(idx != -1)
		{
			allocate[i]=idx;
			blockSize[idx]=blockSize[idx] - processSize[i];
		}
	}

	printf("process no\t\tprocess size\t\tblock no\n");
	for(i = 0;i < n; i++)
	{
		printf("\t%d\t\t\t%d\t\t",i+1,processSize[i]);
;		if (allocate[i] != -1)
		{
			printf("%d\n",allocate[i]+1);
		}
		else
		{
			printf("not allocated\n");
		}
	}
	printf("\n");
}


void bestfit(int blockSize[],int m,int processSize[],int n)
{
	int i,j,allocate[n],idx;

	printf("bestfit\n");
	for (i = 0; i < n; i++)
	{
		allocate[i] = -1;
	}
	for(i = 0 ; i < n ; i++)
	{
		idx = -1;
		for (j = 0; j < m; j++)
		{
			if(blockSize[j] >= processSize[i])
			{
				if(idx == -1)
					idx = j;
				else if(blockSize[idx] > blockSize[j])
					idx = j;
			}
		}
		if(idx != -1)
		{
			allocate[i]=idx;
			blockSize[idx]=blockSize[idx] - processSize[i];
		}
	}

	printf("process no\t\tprocess size\t\tblock no\n");
	for(i = 0;i < n; i++)
	{
		printf("\t%d\t\t\t%d\t\t",i+1,processSize[i]);
		if (allocate[i] != -1)
		{
			printf("%d\n",allocate[i]+1);
		}
		else
		{
			printf("not allocated\n");
		}
	}
	printf("\n");
}

void firstfit(int blockSize[],int m,int processSize[],int n)
{
	int i,j,allocate[n];

	printf("firstfit\n");
	for (i = 0; i < n; i++)
	{
		allocate[i] = -1;
	}
	for(i = 0 ; i < n ; i++)
	{
		for (j = 0; j < m; j++)
		{
			if(blockSize[j] >= processSize[i])
			{
				allocate[i] = j;
				blockSize[j] = blockSize[j] - processSize[i];
				break;
			}
		}
	}

	printf("process no\t\tprocess size\t\tblock no\n");
	for(i = 0;i < n; i++)
	{
		printf("%d\t\t%d\t\t",i+1,processSize[i]);
		if (allocate[i] != -1)
		{
			printf("%d\n",allocate[i]+1);
		}
		else
		{
			printf("not allocated\n");
		}
	}
	printf("\n");
}


int main()
{	
	/*int blockSize[10];
    int processSize[10];
    int m,n,i;

    printf("Enter the block Size and process Size");
    scanf("%d%d",&m,&n);
    printf("Enter block Size ");
    for (i = 0; i < n; i++)
	{
		scanf("%d",&blockSize[i]);
	}
	printf("Enter process Size");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&processSize[i]);
	}*/

	int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

	firstfit(blockSize,m,processSize,n); 
	for (int i = 0; i < m; ++i)
	{
		printf("%d\n",blockSize[i] );
	}
   bestfit(blockSize, m, processSize, n);
   // worstfit(blockSize,m,processSize,n);
}