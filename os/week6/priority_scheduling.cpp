// n is HP and 0 is LP
#include <iostream>

using namespace std;

struct Process
{
	int id;
	int at,bt,priority;
	int ct,tat,wt;
};

int main(int argc, char const *argv[])
{
	int size,i,time = 0;
	printf("How many processes?\n");
	scanf("%d",&size);

	Process p[size];
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
	}
	printf("******************************************\nUsing priority scheduling processes will have:\n------------------------------------------------------------\nID\tPriority\tAT\tBT\tCT\tTAT\tWT\n------------------------------------------------------------\n"); 
	
	int id, count = 0, current_p = INT8_MAX;
	for(time = 0; count != size; ){
		current_p = INT8_MAX;
		int f = 0;
		for (int i = 0; i < size; ++i)
			if(p[i].at < time && p[i].priority < current_p)
				current_p = p[i].priority, id = p[i].id, f = 1;
		if(!f)
		{
			time++;
			continue;
		}
		time += p[id].bt; 
		p[id].ct = time;
		p[id].tat = time - p[id].at;
		p[id].wt = p[id].tat - p[id].bt;
		printf("P%d\t %d\t\t %d\t %d\t %d\t %d\t %d\t\n", p[id].id,p[id].priority,p[id].at,p[id].bt,p[id].ct,p[id].tat,p[id].wt);
		p[id].priority = INT8_MAX;
		count++;

	}
	return 0;
}
