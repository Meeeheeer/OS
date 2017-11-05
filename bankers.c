#include<stdio.h>
#define P 5
#define R 3
int Need[P][R];

int NeedMatrix(int allot[][R],int maxm[][R])
{
	for (int i = 0; i < P; i++)
		for(int j = 0; j < R; j++)
			Need[i][j] = maxm[i][j] - allot[i][j];
}

void Bankers(int processes[],int avail[],int maxm[][R],int allot[][R])
{	
	int work[R],i,j,sq[P],count = 0,k;
	int flag[P] = {0};
	NeedMatrix(allot,maxm);

	for (i = 0; i < R; i++)
		work[i] = avail[i];
	/*for (int i = 0; i < P; i++)
		{
			for(int j = 0; j < R; j++)
				printf("%d",Need[i][j]);
			printf("\n");
		}
	*/
	while(count < P)
	{
		for (i = 0; i < P; i++)
		{
			if(flag[i] == 0)
			{
				for (j = 0; j < R; j++)	
				{	
					//printf("%d\t",j);
					if(Need[i][j] > work[j])
						break;
				}
				if(j == R)
				{
					//printf("in %d\n",i );
					for(k = 0;k < R; k++ )
						work[k] += allot[i][k];
					//printf("%d\n",work[i] );
					sq[count++] = i;
					flag[i] = 1;
				}
			}
		}
	}
	for(i =0 ;i < P ; i++)
		printf("%d\n",sq[i]);

}

int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {3, 3, 2};
    int maxm[][R] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
    int allot[][R] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1},
                      {0, 0, 2}};
 
    Bankers(processes, avail, maxm, allot);
    return 0;
}