# Edmonds_Karp

### Input:
First line:  
* ```n m```  # n = number of vertices, m = number of edges of a directed graph  

* next ```m``` lines:  
  * ```u``` ```v``` ```c```  #directed edge from ```u``` to ```v``` with capacity ```c```
  * 1 <= u != v <= n (주의!)

### Output:
* ```F``` # value of maximum flow of the input graph



# Bipartite Matching
### Input:  
* First line:  
  * ```n```  # number of vertices of a bipartite graph G = (L,R,E) , i.e., |L|+|R|  
* Second line:
  * ```m``` # number of edges of G, i.e., |E|
* m lines:
  * ```u``` ```v``` # edge connecting u of L and v of R (vertex id starts from 1 and ends at n)

### Output:
* First line:
  * ```M``` # the maximum number of matched edges of G
* M lines
  * ```u``` ```v``` # a matched edge (u,v) where u in L and v in R; note that u should be sorted in increasing order
