#include <stdio.h>
#define v 4 //no of vertices in the graph

#ifndef INF
#define INF 99999 
#endif
//this function prints the solution
int printSolution (int dist[][v]);

//solves all pair shortest path problem
//using floyd warshall algo
// -----------------------------

bool negCyclefloydWarshall (int dist [v][v]){
	
	int i ;
	for(i=0;i<v;i++){
		if (dist [i][i] <0 )
		{
			return true;
		}
	}
	return false;

}

void floydWarshall(int graph[][v])
{
	int dist[v][v], i, j, k ;

	//initialize the sol matrix equal to the graph

	for (i=0; i<v; i++)
		for( j=0;j<v; j++)
			dist[i][j]= graph [i][j];


	for (k=0; k<v; k++){
		//pick all the source one by one

		for(i=0;i<v;i++){
			//pick all the vertices as destination from the source

			for ( j= 0 ;j< v; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

			}
		}
	}
	// print the shortest distance matrix
	printSolution(dist);

	if(negCyclefloydWarshall(dist)){
		printf("the graph has negative cycle \n ");
	}else{
		printf("the graph has no negative cycle \n ");

	}

}

int  printSolution(int dist[][v]){
	printf("shortest distance matrix \n");

	for (int i=0 ; i< v ; i++){
		for (int j = 0; j < v ; j++){
			if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);

		}
		printf("\n");

	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int graph [v][v]= { { 0,5,INF,10},
						{INF, 0, 3, INF},
						{INF,INF, 0,1},
						{INF,INF, INF, 0} 
					  };

floydWarshall(graph);
	return 0;
}





/*
the time complexity of the algoritm is



0(V^3)


*/
