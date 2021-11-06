#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int V,E;

int debug = 0;
class Graph{
	private:
		int g_size;
		vector<vector<pair<int, int> > > graph;
		vector<vector<int> >resGraph;
		int* parent;
		vector<int> sources={0};
		vector<int> sinks;
		int source;
		int sink;
		
	public:
		Graph(int n){
			g_size = n;
			graph.resize(g_size+2, vector<pair<int, int> >(g_size+2));
			resGraph.resize(g_size+2, vector<int>(g_size+2));
			parent = new int[g_size+2];
			fill_n(parent, g_size+2,-1);
			source = 0;
			sink = ++g_size;
			sinks.push_back(sink);
		}
		void insert(int u, int v, int cap = 1){
			graph[u][v]   = make_pair(0, cap);
			resGraph[u][v] = cap;
			if(find(sources.begin(), sources.end(), u) == sources.end())
				sources.push_back(u);
			if(find(sinks.begin(), sinks.end() , v) == sinks.end())
				sinks.push_back(v);
		}
	
		void findSourceNSink(){
			if(debug>10)
				cout << "source nodes are ";
			for(vector<int>::size_type i = 0 ; i < sources.size() ; i++){
				if(debug>10){
					cout << sources[i] << " ";
				}
				
				graph[0][sources[i]].second = 1;
				resGraph[0][sources[i]]=1;
			}
			if(debug>10)
				cout << endl << "new source node is 0";
			source = 0;
			if(debug>10)
				cout << endl;

			if(debug>10)
				cout << "sink nodes are ";
			for(vector<int>::size_type i = 0 ; i < sinks.size() ; i++){
				if(debug>10){
					cout << sinks[i] <<" ";
				}
				graph[sinks[i]][g_size].second = 1;
				resGraph[sinks[i]][g_size] = 1;
			}
			if(debug>10)
				cout << endl << "new sink node is "<< sink<<endl;
		}
		
		int find_path_BFS(){
			
			parent[source] = -2;
			queue<pair<int, int> > q;
			q.push(make_pair(source, INT_MAX));
			if(debug>0)
				cout << "source: " << source<<endl;
			while(!q.empty()){
				
				int u = q.front().first;
				int flow = q.front().second;
				
				q.pop();
				for(int v = 0 ; v <= g_size ; v++){
					if(debug>100)
						cout << u << "->" << v <<": "<<resGraph[u][v]<<endl;
					
					if(resGraph[u][v]==0) // no edge (u, v) in residual Graph
						continue;

					if(parent[v] == -1 && resGraph[u][v]){
						parent[v] = u;
						int new_flow = min(flow, resGraph[u][v]);
						if(v == sink)
							return new_flow;
						q.push(make_pair(v, new_flow));
					}
				}
			}
			return 0;
		}
		
		int Edmonds_Karp(){
			int counter = 0;
			int flow = 0;
			while (true){
				if(debug>0)
					cout<< "==============time: " <<counter++<<"==============="<<endl;
				int new_flow = find_path_BFS();
				if(new_flow == 0)
					return flow;
				flow += new_flow;
				int curr = sink;
				while (curr != source){
					int prev = parent[curr];
					
						resGraph[prev][curr] -= new_flow;
						resGraph[curr][prev] += new_flow;
						
						if(graph[prev][curr].second != 0)
							graph[prev][curr].first += new_flow;
						else
							graph[curr][prev].first -= new_flow;
						curr = prev;
					
				}
				
				if (debug>10){
					for(int i = 0 ; i <= g_size ; i++){
						for(int j = 0 ; j <= g_size ; j++){
							cout << graph[i][j].first<<"/"<<graph[i][j].second<< " ";
						}
						cout<<endl;
					}
					cout << endl;	
				}
				
				
				fill_n(parent, g_size+1,-1);
			}
			int r_val=0;
			for(int i = 0 ; i < g_size ; i++){
				r_val += graph[0][i].first;
			}
			return r_val;
		}
		void printBipartiteMatching(){
			for(int i = 1 ; i < g_size;i++){
				for(int j = 1 ; j < g_size ; j++){
					if(graph[i][j].first == 1){
						cout << i << " " << j <<endl;
					}
				}
			}
		}
};

int main() {
	cin >> V >> E;
	Graph g = Graph(V);
	for(int i = 0 ; i < E ; i++){
		int u,v;
		cin >> u >> v;
		g.insert(u,v);
	}
	g.findSourceNSink();
	cout << g.Edmonds_Karp()<<endl;
	g.printBipartiteMatching();
}
