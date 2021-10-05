#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int start_vtx;
vector<int> *graph;
bool *dfs_visited;
bool *bfs_visited;

void DFS(int start){
    dfs_visited[start] = true;
    cout << start << " ";
    for(int i = 0 ; i < graph[start].size(); i++){
        int next = graph[start][i];
        if(!dfs_visited[next])
            DFS(next);
    }
    return;
}

void BFS(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(bfs_visited[now])
			continue;
		
		bfs_visited[now] = true;
		cout << now << " ";
		for(int i = 0 ; i < graph[now].size() ; i++){
			int next = graph[now][i];
			if(!bfs_visited[next])
				q.push(next);
		}
	}
}
int main(){
    cin >> n >> m >> start_vtx;
    n++;
    graph = new vector<int>[n];
    dfs_visited = new bool[n];
    bfs_visited = new bool[n];
    for (int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0 ; i < n ; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    for(int i = 0 ; i < n ; i++){
    	
	}
    DFS(start_vtx);
    cout << endl;
    BFS(start_vtx);
    
    
    
}
