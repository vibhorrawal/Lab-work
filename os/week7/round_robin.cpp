#include <iostream>
#include <queue>
using namespace std;
struct Process
{
	int id;
	int at,bt,rt,in_gant_chart = 0;
	int ct,tat,wt;
};

int main(int argc, char const *argv[])
{
	int size,tq,count,time,pid = 0;
	cin>>size>>tq;
	Process process[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>process[i].at>>process[i].bt;
		process[i].id = i+1;
		process[i].rt = process[i].bt;
	}
	queue <int> gant_chart;
	cout<<"\nGant Chart: ";

	pid = 0;
	process[pid].in_gant_chart = 1;
	for (count = 0, time = 0; count < size;)
	{

		cout<<"P"<<pid+1<<" | ";
		if(process[pid].rt < tq){
			time += process[pid].rt;
			process[pid].rt = 0;
		}
		else{
			time += tq;
			process[pid].rt -= tq;
		}

		for (int i = 0; i < size; ++i)
			if(process[i].at <= time && process[i].in_gant_chart == 0){
				gant_chart.push(i);
				process[i].in_gant_chart = 1;
			}

		if(process[pid].rt > 0){
			gant_chart.push(pid);
		}
		else{
			process[pid].ct = time;
			count++;
			process[pid].tat = time - process[pid].at;
			process[pid].wt = process[pid].tat - process[pid].bt;
		}
		pid = gant_chart.front();
		gant_chart.pop();
	}
	cout<<endl<<endl;
	printf("******************************************\nUsing Round Robin processes will have:\n----------------------------------------------\nID\tAT\tBT\tCT\tTAT\tWT\n----------------------------------------------\n");
	for (int pid = 0; pid < size; ++pid)
		printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", process[pid].id,process[pid].at,process[pid].bt,process[pid].ct,process[pid].tat,process[pid].wt);

	return 0;
}