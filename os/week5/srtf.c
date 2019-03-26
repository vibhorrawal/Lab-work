// implementing SRTF
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
time_t t;
clock_t start = 0; // t = time(NULL);start = clock();
void print_clock(){
	printf("------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	// printf("----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}

typedef struct _process{
int id;
int at,bt,rt; // arrival burst remaining time
int ct,tat,wt; // completion turnarount waiting time
} Process;

int main(int argc, char const *argv[])
{
	t = time(NULL);
	start = clock();

	int size,time;
	printf("How many processes?\n");
	scanf("%d",&size);
	Process p[size+1];
	for (int i = 0; i < size; ++i)
	{
		p[i].id = i+1;
		printf("Enter AT for P%d: ",p[i].id );
		scanf("%d", &p[i].at);
		printf("Now enter BT for P%d: ",p[i].id );
		scanf("%d", &p[i].bt);
		printf("\n");
		p[i].rt = p[i].bt;
	}

	int count = 0, smallest = size;
	p[smallest].rt = 999999;
	for(time = 0; count != size; time++){
		smallest = size;
		for (int i = 0; i < size; ++i)
			if(p[i].at < time && p[i].rt < p[smallest].rt && p[i].rt > 0)
				smallest = i;
		
		p[smallest].rt--;

		if(p[smallest].rt == 0){
			p[smallest].ct = time;
			p[smallest].wt = p[smallest].ct - p[smallest].at - p[smallest].bt;
			p[smallest].tat = p[smallest].ct - p[smallest].at;
			count++;
			}

		}

	printf("******************************************\nUsing SRTF processes will have:\n------------------------------------------\nID\tAT\tBT\tCT\tTAT\tWT\n------------------------------------------\n"); 
	for (int i = 0; i < size; ++i)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	print_clock();
	return 0;
}	