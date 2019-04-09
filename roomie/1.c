// 1-16 Banker's Algorithm
// 17-27 Implementing Semaphores
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int res,p;
	printf("Banker's Algorithm\n");
	printf("Enter No of Resources: ");
	scanf("%d",&res);
	printf("Enter No of Processes: ");
	scanf("%d",&p);

	int tot[res],curr[res];
	int max[p][res],alloc[p][res],need[p][res];
	
	printf("Enter Info about Resources\n");
	for (int i = 0; i < res; ++i)
	{
		int a=0;
		printf("Resource %d\n",i+1);
		printf("Total: ");
		scanf("%d",&tot[i]);

		for (int j = 0; j < p; ++j)
		{
			printf("Max for Process %d: ",j+1);
			scanf("%d",&max[j][i]);
			printf("Allocated to Process %d: ",j+1);
			scanf("%d",&alloc[j][i]);
			
			need[j][i]=max[j][i]-alloc[j][i];
			a+=alloc[j][i];
		}

		curr[i]=tot[i]-a;
		printf("\n");
	}

	int l=0;
	int seq[p];

	while(l<p)
	{
		for (int i = 0; i < p; ++i)
		{
			int ch=0;
			for (int j = 0; j < res; ++j)
			{
				int it;
				it=curr[j]-need[i][j];
				if(it<0)
				{
					ch=1;
					break;
				}
			}

			if(ch==0)
			{
				seq[l]=i;
				for (int j = 0; j < res; ++j)
				{
					curr[j]+=alloc[i][j];
					need[i][j]=1000;
				}
				l++;
				printf("%d\t",i);
				break;
			}
		}
	}

	printf("\n");

}