### Input:
첫 번째 줄에는 노드(정점) 개수 n 이 주어진다.  
First line given n which is # of nodes(vertices)

두 번째 줄에는 에지개수 m이 주어진다.  
Second line given m which is # of edges

세 번째 줄부터 방향이 있는 에지 정보(세 정수 u v w)가 한줄에 하나씩 주어진다
* u v w는 가중치(cost) w를 갖는 에지(u, v)임을 나타낸다. (즉, 노드 u에서 v로의 방향성 에지를 나타낸다)
* u와 v는 [0,  .., n-1] 사이의 수로 노드의 번호를 나타낸다.
* w는 에지 가중치로 양의 정수이다.

After third line, directed edge information(integer u v w) is given in each lines.
* u v w is edge(u, v) which has cost w. (direct edge from u to v)
* u and v represented as [0, .., n-1] as node number.
* w is cost of edge which is positive integer.

### Output:
* 소스 노드를 0번 노드라고 할때, 0번 노드에서 다른 모든 노드까지의 최단 경로의 길이를 차례대로 출력한다. 리스트 ```dist```에 최단 경로 길이가 저장된다면, dist[0], dist[1], dist[2], ..., dist[n-1]순서로 차례대로 한 줄에 모두 출력하면 된다.  
  * dist[0] = 0임에 주의하자
  * 만약, 소스 노드에서 어떤 노드까지 경로 자체가 존재하지 않는다면 ```inf```를 출력한다.


* As source node is 0, print shortest paths from node 0 to the other nodes. If shortest paths saved in list ```dist```, print dist[0], dist[1], dist[2], ..., dist[n-1] in order.
  * becareful dist[0] = 0
  * if there is no path from source node to other node, print ```inf```.
