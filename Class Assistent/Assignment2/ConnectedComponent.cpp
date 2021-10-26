#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int m;
class Graph{
	private:
		int g_size;
		int component = 1;
		vector<int>* graph;
		bool* visited;
	public:
		
		Graph(int n){
			g_size = n;
			graph = new vector<int>[g_size];
			visited = new bool[g_size] {false,};
		};
		
		void sortAll(){
			for(int i = 0 ; i < g_size ; i++){
				sort(graph[i].begin(), graph[i].end());
			}
		}
		
		void insert(int u, int v){
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		void BFS(int node){
			queue<int> q;
			q.push(node);
			cout << "Component " << component++ << ": ";
			while(!q.empty()){
				int curNode = q.front();
				q.pop();
				if(visited[curNode])
					continue;
				visited[curNode] = true;
				cout << curNode << " " ;
				for(int i = 0 ; i < graph[curNode].size() ; i++){
					int nextNode = graph[curNode][i];
					if(!visited[nextNode])
						q.push(nextNode);
				}
			}
			cout << endl;
		}
		
		void BFS_All(){
			for(int i = 0 ; i < g_size ; i++){
				if(!visited[i])
					BFS(i);
			}
		}
		
};

int main() {
	cin >> n >> m;
	Graph graph = Graph(n);
	bool visited[n] = {false,};
	
	for(int i = 0 ; i < m ; i++){
		int u, v;
		cin >> u >> v;
		graph.insert(u, v);
	}
	graph.sortAll();
	
	graph.BFS_All();
	return 0;
}
