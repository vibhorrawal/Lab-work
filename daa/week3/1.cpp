// Detecting cycle in directed graph
#include <iostream>
using namespace std;

struct node{
	int data;
	struct node * next = NULL;
};
struct list{
	struct node Node;
};

void addNode(struct node * item, int data){
	if(item->next == NULL)
	{
		struct node * temp = (struct node *) malloc(sizeof(struct node));
		temp -> data = data;
		item -> next = temp;
	}
	else
		addNode(item -> next, data);

}

void dfs(struct node * item, struct list * List,bool visited[],int size){
	printf("-> %d ",item->data );
	visited[(item->data)] = true;
	

	while(item->next != NULL){
		
		item = item->next;
		struct node * ptr = &List[(item -> data)-1].Node; 
		if(visited[(item->data)] == false)
			dfs(ptr, List,visited,size);

	}	

	// if(item->next != NULL)
	// {
	// 	item = item->next;
	// 	dfs(&List[(item -> data)-1].Node, List,visited,size);
	// }
	// else{
	// 	if(visited[(item->data)+1] == false)
	// 	{
	// 		printf("-> %d ",item->data );
	// 		visited[(item->data)+1] = true;
	// 	}
	// }
}

int main()
{
	cout<<"Enter number of elements: ";
	int x,size;
	cin>>size;
	struct list List[size];
	bool visited[size+1] = {0};
	//cout<<"Enter elements:\n";
	for (int i = 0; i < size; ++i)
	 {
		//cin>>x;
		List[i].Node.data = i+1;
	 }
	for (int i = 0; i < size; ++i)
	  {
	  	cout<<"For "<<List[i].Node.data<<" enter next data(-1) to stop:\n";
	  	while(x!= -1)
	  	{
	  		cin>>x;
	  		addNode(&List[i].Node,x);
	  	}
	  	x = 0;
}

	dfs(&List[0].Node,List,visited,size);
	return 0;
}