the floyd warshall program is working properly in the first shot 

command 
=======
g++ -o init init.cc


output
========

shortest distance matrix 
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0
the graph has no negative cycle 


the changes required to be made 

find the transitive closure reachability matrix

find the widest path in the graph

clean s algo 
