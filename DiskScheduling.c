#include<stdio.h>
#include<stdlib.h>

void sort(int disk[],int n)
{
	int temp,i,j;
	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if(disk[j] > disk[j+1])
			{
				//printf("%d\n",j );
				temp = disk[j];
				disk[j] = disk[j+1];
				disk[j+1] = temp;
			}
		}
	}

	/*for (i = 0; i < n; i++)
	{
		printf("%d\n",disk[i] );
	}*/
}

int findPos(int disk[], int n,int val)
{	
	int i;

	for (i = 0; i < n; i++)
		if(disk[i] == val)
			break;
	return i;
}

void sstf(int disk[],int n,int head)
{
	int pos = findPos(disk,n,head);
	float tseek;
	int l = pos - 1;
	int r = pos + 1;
	//printf("%d\n", pos);
	while(r < n || l > -1)
	{
		if(abs(disk[pos] - disk[l]) < abs(disk[pos] - disk[r]))
		{
			tseek += abs(disk[pos] - disk[l]);
			printf("%f\n",tseek );
			pos = l;
			l--;
		}
		else if (abs(disk[pos] - disk[l]) >= abs(disk[pos] - disk[r]))
		{
			tseek += abs(disk[pos] - disk[r]);
			printf("%f\n",tseek);
			pos = r;
			r++;
		}
	}
	/*while(r < n)
	{
		tseek += abs(disk[pos] - disk[r]);
		pos = r;
		r++; 
	}
	while(l > -1)
	{
		tseek += abs(disk[pos] - disk[l]);
		pos = l;
		l--;
	}*/

	printf("%f\n",tseek/n);
}

void scan(int disk[],int n,int head)
{
	int pos = findPos(disk,n,head);
	float tseek;
	int l = pos - 1;
	int r = pos + 1;
	printf("%d\n", pos);
	while(l > -1)
	{
			tseek += abs(disk[pos] - disk[l]);
			//printf("%f\n",tseek );
			pos = l;
			l--;
	}
	tseek += abs(disk[0] - 0);
	while(r < n)
	{
		tseek += abs(disk[pos] - disk[r]);
		pos = r;
		r++; 
	}

	printf("%f\n",tseek);
}


void look(int disk[],int n,int head)
{
	int pos = findPos(disk,n,head);
	float tseek;
	int l = pos - 1;
	int r = pos + 1;
	printf("%d\n", pos);
	while(r < n && l > -1)
	{
			tseek += abs(disk[pos] - disk[l]);
			//printf("%f\n",tseek );
			pos = l;
			l--;
	}
	while(r < n)
	{
		tseek += abs(disk[pos] - disk[r]);
		pos = r;
		r++; 
	}

	printf("%f\n",tseek);
}

void fcfs(int disk[],int n,int head)
{
	float tseek;

	for (int i = 0; i < n; i++)
	{
		tseek += abs(head - disk[i]);
		head = disk[i];		
	}

	printf("%f\n",tseek);
}

int main()
{
	int head = 100;
	int disk[10] = {27, 129, 110, 186, 147, 41, 10, 64, 120,0};
	int n = 10;
	disk[n-1] = head;
	//printf("%d\n",disk[n-1]);
	//int n = sizeof(disk)/sizeof(disk[0]);
	/*for (int i = 0; i < n; i++)
	{
		printf("%d\n",disk[i] );
	}*/
	sort(disk,n);
	//scan(disk,n,head);
	//look(disk,n,head);
	sstf(disk,n,head);
	//fcfs(disk, n, head);
	return 0;
}