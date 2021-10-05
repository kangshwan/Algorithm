from collections import deque
n, m, start_vtx = [int(x) for x in input().split()]
n+=1
G = [[] for _ in range(n)]
dfs_visited = [False for _ in range(n)];
bfs_visited = [False for _ in range(n)];
def DFS(G, v):
    dfs_visited[v] = True
    print(v, end=" ")
    for next_node in G[v]:
        if not dfs_visited[next_node]:
            DFS(G, next_node)

def BFS(G, start_vtx):
    queue = deque()
    queue.append(start_vtx)
    while(queue):
        now = queue.popleft()
        
        if(bfs_visited[now]):
            continue
        bfs_visited[now] = True
        print(now,end=" ")
        for next_node in G[now]:
            if(not bfs_visited[next_node]):
                queue.append(next_node)
                
for _ in range(m):
	x,y = [int(x) for x in input().split()]
	G[x].append(y)
	G[y].append(x)
for i in range(n):
	G[i].sort()

DFS(G,start_vtx)
print()
BFS(G,start_vtx)
