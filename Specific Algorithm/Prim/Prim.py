import heapq
from collections import defaultdict
import math
import copy


n=int(input())
m=int(input())

graph=[[] for _ in range(n)]
E = [None for _ in range(n)]
F = [False for _ in range(n)]
cost = [[math.inf, i] for i in range(n)]

for _ in range(m):
	u,v,w=map(int,input().split())
	graph[u].append([w,v])
	graph[v].append([w,u])
T=[]
min_cost = 0
heapq.heapify(cost)
Q=copy.deepcopy(cost)
while Q:
		c,node = heapq.heappop(Q)
		if F[node]:
			continue
		F[node]=True
		if E[node] != None:
				T.append((E[node],c))
				min_cost += c
		for edge in graph[node]:
				w,v = edge #weight, adjacent vertex
				# print(edge)
				if not F[v] and w < cost[v][0]:
						cost[v][0] = w
						Q=copy.deepcopy(cost)
						heapq.heapify(Q)
						E[v] = w
print(min_cost)   