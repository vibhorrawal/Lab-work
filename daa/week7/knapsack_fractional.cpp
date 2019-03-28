#include<iostream>
#include<string>
using namespace std;

struct pack{
	int item, value, weight;
	float vw;
};
void sortbyvw(pack* k, int n);
void sortbyweight(pack* k, int n);
float knapsack(pack* k, int n, int cost);

int main(int argc, char const *argv[])
{
	int n, cost;
	float max1, max2;
	scanf("%d", &n);
	pack k[n];
	printf("Enter \tValue\tWeight:\n");
	for (int i = 0; i < n; ++i)
	{
		k[i].item = i+1;
		scanf("%d %d", &k[i].value, &k[i].weight);
	}
	printf("Enter Cost: ");
	scanf("%d", &cost);
	sortbyvw(k,n);
	printf("\n\nValue/Weight ");
	max1 = knapsack(k, n, cost);
	sortbyweight(k,n);
	printf("\nWeight ");
	max2 = knapsack(k, n, cost);
	max2 > max1 ? printf("\n By Weight is better\n"): printf("\n By Value/Weight is better\n");
	return 0;
}

void sortbyvw(pack* k, int n){
	int tVw,tItem,tValue,tWeight = INT8_MIN;
	for (int i = 0; i < n; ++i)
		k[i].vw = (float) k[i].value / k[i].weight;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (k[j].vw < k[i].vw){
				tItem = k[j].item;
				tWeight = k[j].weight;
				tValue = k[j].value;
				tVw = k[j].vw;

				k[j].item = k[i].item;
				k[j].weight = k[i].weight;
				k[j].value = k[i].value;
				k[j].vw = k[i].vw;

				k[i].item = tItem;
				k[i].weight = tWeight;
				k[i].value = tValue;
				k[i].vw = tVw;
			}
}

void sortbyweight(pack* k, int n){
	int tVw,tItem,tValue,tWeight = INT8_MIN;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (k[j].weight < k[i].weight){
				tItem = k[j].item;
				tWeight = k[j].weight;
				tValue = k[j].value;
				tVw = k[j].vw;

				k[j].item = k[i].item;
				k[j].weight = k[i].weight;
				k[j].value = k[i].value;
				k[j].vw = k[i].vw;

				k[i].item = tItem;
				k[i].weight = tWeight;
				k[i].value = tValue;
				k[i].vw = tVw;
			}
}
float knapsack(pack* k, int n, int cost){
	printf("Knapsack:\n");
	float temp, capacity = 0, max = 0;
	for (int i = 0; i < n; ++i)
	{
		// printf("-%d\n", k[i].item);
		if(cost >= k[i].weight){
			cost = cost - k[i].weight;
			printf("%d ", k[i].item);
			max += k[i].weight;
			capacity += k[i].value; 
		}
		else if (cost == 0)
			break;
		else /*if(k[i].weight > cost)*/{
				
				printf("%d ", k[i].item);
				temp = (float) cost / k[i].weight;
				max = max + k[i].weight * temp;
				capacity += k[i].value * temp;
				cost = 0;
				
		}
		
	}
	printf("\nwith max weight = %.2f and capacity = %.2f\n", max, capacity);
	return capacity;
}