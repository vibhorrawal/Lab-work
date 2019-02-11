// implementing FCFS
#include<stdio.h>

struct process{
int id;
int at,bt;
int ct,tat,wt;
};

void sort(struct process p[],int size);
int main(int argc, char const *argv[])
{
	int size,i,time = 0;
	printf("How many processes?\n");
	scanf("%d",&size);
	struct process p[size];
	// int sorted[size];
	for (i = 0; i < size; ++i)
	{
		p[i].id = i;
		printf("Enter AT for P%d: ",p[i].id );
		scanf("%d", &p[i].at);
		printf("Now enter BT for P%d: ",p[i].id );
		scanf("%d", &p[i].bt);
		printf("\n");
	}
	printf("\nUsing FCFS processes will have:\nID\tAT\tBT\tCT\tTAT\tWT\n"); 
	// sort acc to AT
	sort(p,size);

	// for (int i = 0; i < size; ++i)
	// {
	// 	printf("%d\n", p[i].id);
	// }

	// CT = time
	
	for (int i = 0; i < size; ++i)
	{
		time+= p[i].bt;

		p[i].ct = time;
	}
	// TAT = CT - AT
	// WT = TAT - BT
	for (int i = 0; i < size; ++i)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
	
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t %d\t %d\t %d\t %d\t %d\t\n", p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}

	return 0;
}

void sort(struct process p[],int size){
	int temp_at,temp_bt,temp_id;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (p[j].at > p[i].at)
			{
				temp_at = p[i].at;
				temp_bt = p[i].bt;
				temp_id = p[i].id;

				p[i].at = p[j].at;
				p[i].bt = p[j].bt;
				p[i].id = p[j].id;

				p[j].at = temp_at;
				p[j].bt = temp_bt;
				p[j].id = temp_id;
			}
		}
	}
}