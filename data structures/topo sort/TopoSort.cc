/*
	this is a tutorial from geekforgeek
	video ::https://www.youtube.com/watch?v=Q9PIxaNGnig
	author :: Aloy Sen
	date:: 2/10/2017
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V; // no of vertices
	list<int> *adj; //pointer to adj-list

	void topologicalSortUtil(int v,bool visited[], stack<int> &Stack);
public:
	Graph(int v);
	void addEdge(int v,int w);
	void topologicalSort();
	
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// =====------ the core logic of the program -----=====

void Graph::topologicalSortUtil(int v,bool visited[], stack<int> &Stack){
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); ++i){
		if (!visited[*i])
		{
			topologicalSortUtil(*i,visited,Stack);
		}
	}
	Stack.push(v);
}
void Graph::topologicalSort(){
	stack<int> Stack;
	bool *visited=new bool[V];
	for (int i = 0; i < V; i++)
        visited[i] = false;
	for (int i = 0; i < V; i++)
	{
		if (visited[i]=false)
		{
			topologicalSortUtil(i,visited, Stack);
		}
	}
	while(Stack.empty()==false){
		cout << Stack.top() << " ";
		Stack.pop(); 
	}
}
// =====------ the core logic of the program -----=====

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph n";
    g.topologicalSort();
 
    return 0;
}