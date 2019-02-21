//krushkal algo
#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
    int V;   
    list<int> *adj;   
    bool isCyclicUtil(int v, bool visited[], int parent); 
public: 
    Graph(int V);   
    void addEdge(int v, int w);   
    bool isCyclic();   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);
} 
  
int * sort(int cost[][]);
int countVertices(int cost[][],int size);
void mimimumEdges(int sorted[],int i,int edges[]); 

int main(int argc, char const *argv[])
{
	int cost[][5] = { 
        { 0, 2, 0, 6, 0 }, 
        { 2, 0, 3, 8, 5 }, 
        { 0, 3, 0, 0, 7 }, 
        { 6, 8, 0, 0, 9 }, 
        { 0, 5, 7, 9, 0 }, 
    }; 
    
    int size = countVertices(cost);
    int sorted[size-1] = sort(cost,size);
    
    int edges[2];
    List <int> tempEdges;

    Graph krushkal(size),temp(size);

    for (int i = 0; i < size-1; ++i)
    {
    	mimimumEdges(sorted,i,edges); 
    	temp.addEdge(edges[0],edges[1]);

    	if(temp.isCyclic())
    	{
    			free(temp);
    			Graph temp(size);
    			
    			list<int>::iterator j; 
    			for (j = tempEdges.begin(); j != tempEdges.end(); ++j)
    			{
    				temp.addEdge(j,++j);
    			}
    			 
    		
    	}
    	else{
    		krushkal.addEdge(edges[0],edges[1]);
    		tempEdges.push_back(edges[0]);
    		tempEdges.push_back(edges[1]);

    	}


    }
        	list<int>::iterator i; 
    	for (i = tempEdges.begin(); i != tempEdges.end(); ++i)
    		{
    			cout<<i<<"->";
    		}
    		

	return 0;
}

int * sort(int * cost, int size)
{
	int sorted[size-1];
	int k = 0;
	for (int i = 0; i < 25; ++i)
	{
		if(cost[i] == 0)
			continue;

		sorted[k] = cost[i];
		k++;
	}
	int temp ;
	for (int i = 0; i < k; ++i)
	{
		for (int it = 0; it < i; ++it)
		{
			if(sorted[it]>sorted[i])
			{
				temp = sorted[i];
				sorted[i] = sorted[it];
				sorted[it] = temp;
			}
		}
	}
	return sorted[];
}


int countVertices(int cost[][],int size)
{
	int count=0;
	for (int i = 0; i < 25; ++i)
	{
		if(cost[i] == 0)
			continue;
		count++;
	}
	return count;
}

void mimimumEdges(int sorted[],int i,int edges[])
{
	
}







bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
       
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        /
        // then there is a cycle. 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 
  
bool Graph::isCyclic() 
{ 

    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  

    for (int u = 0; u < V; u++) 
        if (!visited[u]) 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
} 
