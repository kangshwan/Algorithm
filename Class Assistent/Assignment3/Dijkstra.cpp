#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

int n;
int m;

int main() {
	cin >> n >> m;
	vector<pair<int, int> > graph[n];
	vector<int> Q;
	int dist[n];
	int prev[n];
	for(int v = 0 ; v < n ; v ++){
		dist[v] = INT_MAX;
		prev[v] = NULL;
		Q.push_back(v);
	}
		
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
	}
	cout << "choose vertex to start: ";
	int start;
	cin >> start;
	dist[start] = 0;
	prev[start] = start;
	
	/* Run Dijkstra */
	while(!Q.empty()){
		
		/* find vertex u in Q with min dist[u] */
		int u;
		int minDist = INT_MAX;
		int idx_for_remove;
		for(int i = 0 ; i < Q.size() ; i++){
			int tmp = Q[i];
			if( minDist > dist[tmp] ){
				u = tmp;
				minDist = dist[tmp];
				idx_for_remove = i;
			}
		}
		/* find vertex u END */
		
		cout <<"Choosen u: " << u <<" minDist[u]: "<<minDist<<endl;
		
		Q.erase(Q.begin()+idx_for_remove,Q.begin()+idx_for_remove+1);
		
		for(int i = 0 ; i < graph[u].size() ; i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			cout << "v, w: "<<v <<", "<<w<<endl;
			int alt = dist[u] + w;
			if( alt < dist[v] ){
				dist[v] = alt;
				prev[v] = u;
			}			
		}
	}
	
	/* Dijkstra End */
	
	cout << "shortest distances: ";
	for(int i = 0 ; i < n ; i++){
		if(dist[i] == INT_MAX){
			cout << "inf ";
		}
		else{
			cout << dist[i] << " ";
		}
	}
	cout << endl;
	
	cout << "prev nodes: "<<endl;
	for(int i = 0 ; i < n ; i++){
		cout << i <<" ";
	}
	cout <<endl;
	for(int i = 0 ; i < n ; i++){
		cout << prev[i] <<" ";
	}
	return 0;
}

/*
Example
7 22
0 1 7
0 3 5
1 0 7
1 2 8
1 3 9
1 4 7
2 1 8
2 4 5
3 0 5
3 1 9
3 4 7
3 5 6
4 1 7
4 2 5
4 3 7
4 5 8
4 6 9
5 3 6
5 4 8
5 6 11
6 4 9
6 5 11
*/
