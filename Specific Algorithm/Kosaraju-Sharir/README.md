### Input:
첫 번째 줄에는 노드(정점) 개수 n 이 주어진다.  
First line given n which is # of nodes(vertices)

두 번째 줄에는 에지개수 m이 주어진다.  
Second line given m which is # of edges

세 번째 줄부터 방향이 있는 에지 정보(두 정수 u v)가 한줄에 하나씩 주어진다
* u v 는 에지(u, v)임을 나타낸다. (즉, 노드 u에서 v로의 방향성 에지를 나타낸다)
* u와 v는 [0,  .., n-1] 사이의 수로 노드의 번호를 나타낸다.

After third line, directed edge information(integer u v) is given in each lines.
* u v  is edge(u, v). (direct edge from u to v)
* u and v represented as [0, .., n-1] as node number.

### Output:
* Strong Connected component의 개수를 출력한다

* print # of Strong Connected Component