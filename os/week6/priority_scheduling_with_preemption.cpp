// n is HP and 0 is LP
#include <iostream>

using namespace std;

struct Process
{
	int id;
	int at,bt,priority;
	int ct,tat,wt,rt;
};

int main(int argc, char const *argv[])
{
	int size,i,time = 0;
	printf("How many processes?\n");
	scanf("%d",&size);
	int *flag;
	flag=(int *)malloc((size + 1) * sizeof(int));
	for (int i = 0; i < size; ++i)
		flag[i] = 0;
	Process p[size+1];
	for (i = 0; i < size; ++i)
	{
		p[i].id = i;
		printf("Enter AT for P%d: ",p[i].id );
		scanf("%d", &p[i].at);
		printf("Now enter BT for P%d: ",p[i].id );
		scanf("%d", &p[i].bt);
		printf("Now enter priority for P%d: ",p[i].id );
		scanf("%d", &p[i].priority);
		printf("\n");
		p[i].rt = p[i].bt;
	}
	
	int id, current_p, count = 0;
	p[size].priority = INT8_MAX;
	p[size].rt = INT8_MAX;

	for(time = 0; count != size; time++){
		current_p = INT8_MIN;
		id = size;
		for (int i = 0; i < size; ++i)
			if(p[i].at < time && p[i].priority > current_p && p[i].rt > 0)
				current_p = p[i].priority, id = p[i].id;
		
		p[id].rt--;
		if(p[id].rt == 0){
			p[id].ct = time;
			p[id].tat = time - p[id].at;
			p[id].wt = p[id].tat - p[id].bt;
			count++;
		}
	}
	printf("******************************************\nUsing priority scheduling(preemption) processes will have:\n------------------------------------------------------------\nID\tPriority\tAT\tBT\tCT\tTAT\tWT\n------------------------------------------------------------\n"); 
	for(int i = 0; i< size; i++)
		printf("P%d\t %d\t\t %d\t %d\t %d\t %d\t %d\t\n", p[i].id,p[i].priority,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

	return 0;
}
