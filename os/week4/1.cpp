// implementing SJF
#include<iostream>
using namespace std;
struct process{
int id;
int at,bt;
int ct,tat,wt;
};

void sortAT(struct process p[],int size);
void sortBT(struct process p[],int size);
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
	printf("******************************************\nUsing SJF processes will have:\n------------------------------------------\nID\tAT\tBT\tCT\tTAT\tWT\n------------------------------------------\n"); 
	// sort acc to BT
	sortAT(p,size);
	//
	// CT = time
	p[0].ct = time = p[0].at + p[0].bt;
	int id = p[0].id;

	int flag[size] = {0};
	int countflag = 0;
	for (int i = 0; i < size; ++i)
	{
		if(time>p[i].at){
			flag[i] = 1;
			countflag++;
		}
	}
	struct newP[countflag];
	int c=0;
	for (int i = 0; i < size; ++i)
	{
		if (flag[i])
		{
			newP[c].id = p[i].id;
			newP[c].bt = p[i].bt;
			newP[c].at = p[i].at;
			c++;
		}
	}
	sortBT(newP,size,flag);
	for (int i = 0; i < countflag; ++i)
	{
		
		if(time<newP[i].at)
			time = newP[i].at;
		time+= newP[i].bt;
		newP[i].ct = time;
	}
	// TAT = CT - AT
	// WT = TAT - BT
	for (int i = 0; i < countflag; ++i)
	{
		newP[i].tat = newP[i].ct - newP[i].at;
		newP[i].wt = newP[i].tat - newP[i].bt;
	}
	
	printf("%d\t %d\t %d\t %d\t %d\t %d\t\n", p[0].id+1,p[0].at,p[0].bt,p[0].ct,p[0].tat,p[0].wt);
	for (int i = 0; i < countflag; ++i)
	{
		printf("%d\t %d\t %d\t %d\t %d\t %d\t\n", newP[i].id+1,newP[i].at,newP[i].bt,newP[i].ct,newP[i].tat,newP[i].wt);
	}
	int newflag = size-countflag;
	struct rP[newflag];
	c=0;
	for (int i = 0; i < size; ++i)
	{
		if (!flag[i])
		{
			rP[c].id = p[i].id;
			rP[c].bt = p[i].bt;
			rP[c].at = p[i].at;
			c++;
		}
	}
	
	for (int i = 0; i < newflag; ++i)
	{
		
		if(time<rP[i].at)
			time = rP[i].at;
		time+= rP[i].bt;
		rP[i].ct = time;
	}
	// TAT = CT - AT
	// WT = TAT - BT
	for (int i = 0; i < newflag; ++i)
	{
		rP[i].tat = rP[i].ct - rP[i].at;
		rP[i].wt = rP[i].tat - rP[i].bt;
	}
	for (int i = 0; i < newflag; ++i)
	{
		printf("%d\t %d\t %d\t %d\t %d\t %d\t\n", rP[i].id+1,rP[i].at,rP[i].bt,rP[i].ct,rP[i].tat,rP[i].wt);
	}

	return 0;
}

void sortAT(struct process p[],int size){
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
void sortBT(struct process p[],int size){
	int temp_at,temp_bt,temp_id,time=0;
	for (int i = 0; i < size; ++i)
	{
		//time+=p[i].at;
		for (int j = 0; j < i; ++j)
		{
			// if(time>=p[j].at){
			// 	time+=p[j].at;
				if (p[j].bt > p[i].bt)
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
			// }	

		}
	}
}