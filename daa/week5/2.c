// dijkstra
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include <limits.h>

//Vertices
#define V 6
void dijkstra(int graph[V][V], int src);
int min_distance_index(int distance[],bool sptSet[]);
void print(int* distance);
//-------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	int graph[V][V] = {
		{0,5,3,0,0,0},
		{5,0,1,1,4,0},
		{3,1,0,2,7,0},
		{0,1,2,0,1,3},
		{0,4,7,1,0,3},
		{0,0,0,3,3,0}
	};
	dijkstra(graph,0);
	// print(distance);
	return 0;
}
//-------------------------------------------------------------------------------------------------
void dijkstra(int graph[V][V], int src){
	int distance[V];
	bool sptSet[V];

	for (int i = 0; i < V; i++){ 
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
     distance[src] = 0;
     
     for (int i = 0; i < V; ++i)
         {
         	int u = min_distance_index(distance,sptSet);
         	sptSet[u] = true;
         	for (int v = 0; v < V; v++){
         		if (!sptSet[v] /*&& distance[u] != INT_MAX*/ && graph[u][v] && distance[u] + graph[u][v] < distance[v])
         		  	distance[v] = distance[u] + graph[u][v];  
         	}
         }
    print(distance);     
}
int min_distance_index(int distance[],bool sptSet[]){
	int min_index, min = INT_MAX;
	for (int i = 0; i < V; ++i)
		if(sptSet[i] == false && min >= distance[i])
			min_index = i, min = distance[i];
	return min_index;	
}
void print(int* distance){
	printf("Vertex\t\tDistance from source\n");
	for (int i = 0; i < V; ++i)
		printf("%d\t\t%d\n", i, distance[i]);
}