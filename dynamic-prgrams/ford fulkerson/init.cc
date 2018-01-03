#include <iostream>
#include <string.h>
#include <queue>

using namespace std ;
// number of vertices in the given graph

#ifndef v
#define v 6
#endif

bool bfs(int rGraph[v][v],int s, int parent[]){
	bool visited [v];
	memset(visited, 0, sizeof(visited));

	queue <int> q ;
	q.push(s);
	visited[s] = true ;
	parent[s]= -1;

	//standard bfs loop 
	while(! q.empty()){
		int u = q.front();
		q.pop();
		for(int v=0; v<V ;v++){
			if(visited [v] == false && rGraph[u][v] >0 ){
				q.push(v);
				parent[v] =u ;
				visited[v] = true;

			}
		}
	}


	//if we reached sink in bfs starting from source and return true
	return (visited [t] ==true );

}

int fordFulkerson(int graph[v][v],int s,int t){
	int u,v;

	for (u= 0;u <V;u++){
		
		for (v=0;v<V; v++){
			rGraph[u][v]= graph[u][v];
		}
	}
	int parent[V];

	int max_flow= 0;

	while (bfs(rGraph, s,t, parent)){
		// Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.

		int path_flow= INT_MAX;
		for (v = t; v!=s ; v= parent[v]){
			u=parent[v];
			rGraph[u][v]-= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow= path_flow;
	}
		return max_flow;
}

int main(int argc, char const *argv[])
{
	//create a graph shown 

	int graph[v][v] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "the maximum possible flow is " << fordFulkerson(graph, 0, 5);
    return 0;
	return 0;
}