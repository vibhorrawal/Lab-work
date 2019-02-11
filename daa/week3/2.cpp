// implementing BFS in graph
#include<iostream>
#include<queue>
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

	struct node * temp, *root = &List[0].Node;
	queue <struct node *> myq;
	//cout<<" -> "<<root->data;
	myq.push(root);
	visited[1] = true;
	while(!myq.empty())
	{
		
		temp = &List[myq.front()->data-1].Node;
		myq.pop();
		cout<<" -> "<<temp->data;
		while(temp->next != NULL)
		{
			if(!visited[temp->data])
			{
				visited[temp->data] = true;
				myq.push(temp);
			}
			temp = temp->next;
		}
	  
	}
	cout<<endl;
	return 0;  
}