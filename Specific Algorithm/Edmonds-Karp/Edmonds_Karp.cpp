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
		vector<vector<int> > resGraph;
		vector<int> indegree;
		vector<int> outdegree;
		vector<int> maxCapOut;
		vector<int> maxCapIn;
		int* parent;
		int source;
		int sink;
		
	public:
		Graph(int n){
			g_size = n;
			graph.resize(g_size+2, vector<pair<int, int> >(g_size+2)); // must know this skill!!!!! --> when make 2d array with pair, vector could be better solution then just array.
															 // for example, pair<int, int> arr[502][502] doesnt work, make some error. but vector<vector<pair<int, int> > > arr , then arr.resize(502, vector<pair<int, int> >(502) ) make sense.
			resGraph.resize(g_size+2, vector<int>(g_size+2));
			indegree.resize(g_size+2,0);
			outdegree.resize(g_size+2,0);
			maxCapOut.resize(g_size+2,0);
			maxCapIn.resize(g_size+2,0);
			parent = new int[g_size+2];
			fill_n(parent, g_size+2,-1);
		}
		void insert(int u, int v, int cap){
			graph[u][v]   = make_pair(0, cap);
			resGraph[u][v] = cap;
			maxCapOut[u] += cap;
			maxCapIn[v]  += cap;
			indegree[v]  += 1;
			outdegree[u] += 1;
		}
	
		void findSourceNSink(){
			vector<int> sources;
			vector<int> sinks;
			for(int i = 1 ; i <= g_size ; i++){
				if(indegree[i] == 0)
					sources.push_back(i);
				if(outdegree[i] == 0)
					sinks.push_back(i);
			}
			if(sources.size() == 1){
				if(debug >0)
					cout << "source node is " << sources[0]<<endl;
				source = sources[0];
			}else{
				if(debug>0)
					cout << "source nodes are ";
				for(vector<int>::size_type i = 0 ; i < sources.size() ; i++){
					if(debug>0){
						cout << sources[i] << " ";
						cout << "MaxCapOut: "<<maxCapOut[sources[i]]<<" ";
					}
					
					graph[0][sources[i]].second = maxCapOut[sources[i]];
					resGraph[0][sources[i]]=maxCapOut[sources[i]];
				}
				if(debug>0)
					cout << endl << "new source node is 0";
				source = 0;
			}
			if(debug>0)
				cout << endl;
			if(sinks.size()==1){
				if(debug>0)
					cout << "sink node is " << sinks[0] << endl;
				sink = sinks[0];
			}else{
				g_size++;
				sink = g_size;
				if(debug>0)
					cout << "sink nodes are ";
				for(vector<int>::size_type i = 0 ; i < sinks.size() ; i++){
					if(debug>0){
						cout << sinks[i] <<" ";
						cout << "maxCapIn: "<<maxCapIn[sinks[i]] << endl;
					}
					graph[sinks[i]][g_size].second = maxCapIn[sinks[i]];
					resGraph[sinks[i]][g_size] = maxCapIn[sinks[i]];
				}
				if(debug>0)
					cout << endl << "new sink node is "<< sink<<endl;
			}
		}
		
		int find_path_BFS(){
			
			parent[source] = -2;
			queue<pair<int, int> > q;
			q.push(make_pair(source, INT_MAX));
			if(debug>0)
				cout << "source: " << source<<endl;
			while(!q.empty()){
				if(debug>0)
					cout << "queue in"<<endl;
				
				int u = q.front().first;
				int flow = q.front().second;
				if(debug>0)
					cout << "curr max flow: "<<flow<<endl;
				q.pop();
				for(int v = 0 ; v <= g_size ; v++){
					if(debug>0)
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
					
					graph[prev][curr].first += new_flow;
					curr = prev;
				}
				
				if (debug>0){
					for(int i = 0 ; i <= g_size ; i++){
						for(int j = 0 ; j <= g_size ; j++){
							cout << graph[i][j].first<<"/"<<graph[i][j].second<< " ";
						}
						cout<<endl;
					}
					cout << endl;	
				}
				fill_n(parent, g_size+2,-1);
			}
		}
		
};

int main() {
	cin >> V >> E;
	Graph g = Graph(V);
	for(int i = 0 ; i < E ; i++){
		int u,v,c;
		cin >> u >> v >> c;
		g.insert(u,v,c);
	}
	g.findSourceNSink();
	cout << g.Edmonds_Karp();

}
