#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define SIZE 3
struct Node{
	int d;
	struct Node* next;
};
struct List{
	struct Node* head;
};
struct Graph{
	int V;
	struct List* array;
};
struct Edge{
	int e1,e2,weight;
};
struct Graph* create_graph(int V);
void add_edge(struct Graph* graph, int src, int d);
void remove_edge(struct Graph* graph, int src, int d);
void print_graph(struct Graph* graph);
bool check_edge(struct Graph* graph, int src, int d);
bool is_graph_cyclic(struct Graph* graph);
bool is_graph_cyclic_util(struct Graph* graph, int i, /*bool visited[],*/ bool recursive_stack[]);
bool is_graph_cyclic_undirected(struct Graph* graph);
bool is_graph_cyclic_util_undirected(struct Graph* graph, int i, bool visited[], int parent);
void kruskal_MST(int V, int adjacency_matrix[][SIZE]);
struct Edge minimum_weight(int V, int adjacency_matrix[][SIZE]);
void DFS(struct Graph* graph, int v);
void DFS_util(struct Graph* graph, int v, bool visited[]);
//-----------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]){
	int V = 3;
	int adjacency_matrix[3][3] = {INT_MAX, 4,3,
								  4,INT_MAX,2,
								  3,2,INT_MAX};

	kruskal_MST(V,adjacency_matrix);
	// int V;
	// char c;
	// int e1,e2,w;
	// printf("Enter size of Graph: ");
	// scanf("%d",&V);
	// struct Graph* graph = create_graph(V);

	// printf("Enter Edges in the form: edge-1 edge-2 weight \n");
	// while(true){
	// 	printf("Do you want to add edges?(y/n) ");
	// 	scanf("%c",&c);
	// 	if(c == 'n')
	// 		break;
	// 	scanf("%d %d %d", &e1,&e2,&w);
	// 	add_edge(graph,e1,e2,w);
	// }
 //    print_graph(graph);
	// kruskal_MST(graph);
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
struct Graph* create_graph(int V){
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->array = (struct List*) malloc( V * sizeof(struct List) );
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
}
void add_edge(struct Graph* graph, int src, int d){
	struct Node* new_node = (struct Node*) malloc( sizeof(struct Node) );
	new_node -> d = d;
	// new_node -> weight = weight;
	new_node -> next = graph->array[src].head;
	graph->array[src].head = new_node;
}
void remove_edge(struct Graph* graph, int src, int d){
	struct Node * new_node = graph->array[src].head;
	struct Node * new_node_next = new_node->next;
	if(new_node->d != d){
		while(new_node_next->d != d){
			new_node = new_node->next;
			new_node_next = new_node_next->next;
		}
	new_node->next = new_node->next->next;
	graph->array[src].head = new_node;
	}
	else graph->array[src].head = graph->array[src].head->next;
}
void print_graph(struct Graph* graph){
	int V;
	for (V = 0; V < graph->V; V++)
	{
		struct Node* crawl = graph->array[V].head;
		printf("\n Adjacency list of vertex %d\n head", V); 
		while(crawl){
			printf(" -> %d", crawl->d);
			crawl = crawl->next;
		}
		printf("\n");
	}
}
bool check_edge(struct Graph* graph, int src, int d){
	struct Node* node = graph->array[src].head;
	while(node){
		if(node->d == d)
			return true;
		node = node->next;
	}
	return false;
}
bool is_graph_cyclic(struct Graph* graph){
	int V = graph->V;
	// bool* visited =  malloc(V * sizeof(bool));
	bool* recursive_stack =  malloc(V * sizeof(bool));

	for (int i = 0; i < V; ++i)
		if(is_graph_cyclic_util(graph,i,/*visited,*/recursive_stack))
			return true;
	return false;	
}
bool is_graph_cyclic_util(struct Graph* graph, int i,/* bool visited[],*/ bool recursive_stack[]){
	if(recursive_stack[i])
		return true;
	// if(visited[i])
	// 	return false;
	// visited[i] = true;
	recursive_stack[i] = true;
	struct Node* node = graph->array[i].head;
	while(node){
		if(is_graph_cyclic_util(graph,node->d,/*visited,*/recursive_stack))	
			return true;
		node = node->next;
	}
	recursive_stack[i] = false;
	return false;
}
void kruskal_MST(int V, int adjacency_matrix[][SIZE]){
	int temp;
	struct Edge min;
	struct Graph* graph = create_graph(V);
	printf("Kruskal's MST\n");

	for (int i = 0; i < V; ++i)
	{
		min = minimum_weight(V,adjacency_matrix);
		if(i == 0)
			temp = min.e2;
		if(min.e1 == min.e2)
			continue;

		printf("Added Edge: %d and %d with weight %d\n", min.e1, min.e2, min.weight);
		add_edge(graph,min.e1,min.e2);
		add_edge(graph,min.e2,min.e1);
		if(is_graph_cyclic_undirected(graph)){

			remove_edge(graph, min.e1, min.e2);
			remove_edge(graph, min.e2, min.e1);
			printf("Removed Edge: %d and %d with weight %d\n", min.e1, min.e2, min.weight);
		}


		// if(is_graph_cyclic_undirected(graph)){
		// 	if(check_edge(graph, min.e2, min.e1))
		// 		remove_edge(graph, min.e2, min.e1);
		// 	printf("Removed Edge: %d and %d with weight %d\n", min.e2, min.e1, min.weight);
		// 	// if(check_edge(graph, min.e1, min.e2))
		// 	// 	remove_edge(graph, min.e1, min.e2);
		// 	// printf("Removed Edge: %d and %d with weight %d\n", min.e2, min.e1, min.weight);
		// }
	}
	// add_edge(graph,0,1);
	print_graph(graph);
	DFS(graph,temp);
}
struct Edge minimum_weight(int V, int adjacency_matrix[][SIZE]){
	struct Edge min;
	min.e1 = 0;	min.e2 = 0;	min.weight = adjacency_matrix[0][0];
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < i; ++j)
			if(min.weight>adjacency_matrix[i][j])
			{
				min.e1 = i;	min.e2 = j;	min.weight = adjacency_matrix[i][j];
			}

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < i; ++j)
			if(min.weight == adjacency_matrix[i][j] && (min.e1 == i && min.e2 == j) || (min.e1 == j && min.e2 == i)){
				adjacency_matrix[i][j] = INT_MAX;
			}

	return min;
}
// bool is_graph_cyclic_undirected(struct Graph* graph){
// 	int V = graph->V;
// 	bool* visited =  malloc(V * sizeof(bool));

// 	for (int i = 0; i < V; ++i)
// 		if(!visited[i])
// 			if(is_graph_cyclic_util_undirected(graph,i,visited,-1))
// 				return true;
// 	return false;	
// }
// bool is_graph_cyclic_util_undirected(struct Graph* graph, int i, bool visited[], int parent){
// 	visited[i] = true;
// 	struct Node* node = graph->array[i].head;
// 	while(node){
// 		if(!visited[node->d]){
// 			if(is_graph_cyclic_util_undirected(graph,node->d,visited,i))
// 				return true;
// 		}
// 		else if(node->d != parent) 
// 			return true;
// 		node = node->next;

// 	}
// 	return false;
// }		
bool is_graph_cyclic_undirected(struct Graph* graph){
	int V = graph->V;
	bool* visited =  malloc(V * sizeof(bool));

	for (int i = 0; i < V; ++i)
		if(!visited[i])
			if(is_graph_cyclic_util_undirected(graph,i,visited,-1))
				return true;
	return false;	
}
bool is_graph_cyclic_util_undirected(struct Graph* graph, int v, bool visited[], int parent){
	visited[v] = true;
	struct Node* node = graph->array[v].head;
	// if(node != NULL && node->next != NULL )
		// struct Node* i;
	while(node){
		// i = node -> next;
		if(node->d == parent) 
			return false ;
		if(!visited[node->d]){
			if(is_graph_cyclic_util_undirected(graph,node->d,visited,v)){
				printf("************************************************************%d\n",node->d );
				return true;
			}

		}
		else if(node->d != parent)
			return true;	
		node = node->next;
	}
	return false;
}
void DFS(struct Graph* graph, int v){
	bool* visited =  malloc(graph->V * sizeof(bool));
	for (int i = 0; i < graph->V; ++i)
		visited[i] = false;
	DFS_util(graph,v,visited);
}
void DFS_util(struct Graph* graph, int v, bool visited[]){
	visited[v] = true;
	printf(" ->%d", v);
	struct Node* node = graph->array[v].head;
	while(node){
		if(!visited[node->d])
			DFS_util(graph,node->d,visited);
		node = node->next;
	}
}