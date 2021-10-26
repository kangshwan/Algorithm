n,m = 8,5

g_size=n

graph = [list() for _ in range(n)]

def insert(u, v):
    graph[u].append(v)
    graph[v].append(u)

insert(0,1)
insert(0,2)
insert(3,4)
insert(4,5)
insert(6,7)

visited=[False for _ in range(g_size)]

component_num = 0

for nodes in graph:
    nodes.sort

def BFS(node):
    global component_num
    queue = []
    queue.append(node)
    print(f"Component {component_num}: ", end="")
    component_num +=1
    while(queue):
        curNode = queue.pop()
        if visited[curNode]:
            continue
        visited[curNode] = True
        print(f"{curNode} ", end="")
        for nextNode in graph[curNode]:
            if not visited[nextNode]:
                queue.append(nextNode)
    print()
    

def BFS_All():
    for i in range(g_size):
        if not visited[i]:
            BFS(i)

BFS_All()