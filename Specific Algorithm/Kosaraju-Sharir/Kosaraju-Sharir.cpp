#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int m;
class Graph{
	private:
	int g_size;
	vector<int>* graph;
	vector<int>* inv_graph;
	stack<int> s_sink;
	int* pre;
	int* post;
	bool* visited;
	int curr_time = 1;
	public:
	
	Graph(int n){
		g_size = n;
		graph = new vector<int>[g_size];
		inv_graph = new vector<int>[g_size];
		visited = new bool[g_size] {false,};
		pre = new int[g_size];
		post = new int[g_size];
		for(int i = 0 ; i < g_size ; i++){
			pre[i] = -1;
			post[i] = -1;
		}
	};
	void sortAll(){
		for(int i = 0 ; i < g_size ; i++){
			sort(graph[i].begin(), graph[i].end());
			sort(inv_graph[i].begin(), inv_graph[i].end());
		}
	}
	void insert(int u, int v){
		graph[u].push_back(v);
		inv_graph[v].push_back(u);
	}
	void DFS(int node){
		visited[node] = true;
		for(int i = 0 ; i < graph[node].size() ; i++){
			if(!visited[graph[node][i]])
				DFS(graph[node][i]);
		}
	}
	void invDFS(int node){
		// cout <<"in to invDFS"<<endl<<"node: "<<node<<" visited "<<visited[node]<<endl;
		visited[node] = true;
		pre[node] = curr_time++;
		
		for(int i = 0 ; i < inv_graph[node].size() ; i++){
			// cout << "next node: "<<inv_graph[node][i] << ", visited: "<<visited[inv_graph[node][i]]<<endl; 
		
			if(!visited[inv_graph[node][i]])
				invDFS(inv_graph[node][i]);
		}
		// cout << "off the loop time: "<<curr_time<<endl;
		
		post[node] = curr_time++;
		s_sink.push(node);
		// toprint();
	}
	void fillStack(){
		for(int i = 0 ; i < g_size ; i++){
			if(!visited[i]){
				// cout << "visit "<<i<<endl;
				invDFS(i);
			}
		}
		visited = new bool[g_size];
	}
	
	int SCC(){
		int count = 0;
		while(!s_sink.empty()){
			int node = s_sink.top();
			s_sink.pop();
			if (!visited[node]){
				DFS(node);
				count++;
			}	
		}
		return count;
	}
	
	// only use for checking func
	void toprint(){
	
	}
};

int main() {
	cin >> n >> m;
	Graph graph = Graph(n);

	cout << endl;
	bool visited[n] = {false,};
	
	for(int i = 0 ; i < m ; i++){
		int u, v;
		cin >> u >> v;
		graph.insert(u, v);
	}
	graph.sortAll();
	graph.fillStack();
	// graph.toprint();
	cout << graph.SCC();
	return 0;
}
