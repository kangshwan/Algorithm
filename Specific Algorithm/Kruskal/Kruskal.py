from sys import stdin
n=int(stdin.readline())
m=int(stdin.readline())

class Node:
	def __init__(self, key):
		self.key = key
		self.parent = self
		self.rank = 0
		
def make_set(x):
	return Node(x)

def find(x):
	while x.parent.key != x.key:
		x = x.parent
	return x

def union(x,y):
	v,w = find(x),find(y)
	if v.rank > w.rank:
		v,w = w,v
	v.parent = w
	if v.rank == w.rank:
		w.rank += 1

# def make_set(vertice):
# 	parent[vertice] = vertice
# 	rank[vertice] = 0

graph={
	'vertices': [i for i in range(n)],
	'edges':[]
}

for _ in range(m):
	u,v,w=map(int,stdin.readline().split())
	graph['edges'].append((w,u,v))
	
def Kruskal(G):
	T=[]
	node = [None for i in range(n)]
	for i in graph['vertices']:
		node[i] = make_set(i)
	edges = graph['edges']
	edges.sort(key=lambda x:x[0])
	for edge in edges:
		w,u,v = edge
		if find(node[u]) != find(node[v]):
			T.append(edge)
			union(node[u],node[v])
	return T
min_cost = 0
for edges in Kruskal(graph):
    min_cost+=edges[0]
print(min_cost)