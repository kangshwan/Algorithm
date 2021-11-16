#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> ReachSet = {0};
vector<int> UnReachSet;
vector<tuple<int, int, int> > SpanningTree;

int n, m;

int main(){
	cin >> n >> m;
	vector<tuple<int, int, int> > edges;
	for(int i = 1 ; i < n ; i++){
		UnReachSet.push_back(i);
	}
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(make_tuple(w,u,v));
		edges.push_back(make_tuple(w,v,u));
	}
	
	while( !UnReachSet.empty() ){
		cout<<"ReachSet: [";
		for(int i = 0 ; i < ReachSet.size();i++){
			cout << ReachSet[i] <<" ";
		}
		cout << "]\nUnReachSet: [";
		for(int i = 0 ; i < UnReachSet.size() ; i++){
			cout << UnReachSet[i] << " ";
		}
		cout << "]\n";
		tuple<int, int, int> spanningEdge;
		int minCost=INT_MAX;
		for(int i = 0 ; i < edges.size(); i++){
			int u,v,w;
			tie(w,u,v) = edges[i];
			// if u in ReachSet and v in UnReachSet
			if( find(ReachSet.begin(), ReachSet.end(), u) != ReachSet.end() &&
				find(UnReachSet.begin(), UnReachSet.end(), v) != UnReachSet.end()){
					// check the cost is smallest
					if(minCost > w){
						printf("w: %d u: %d v: %d\n", w,u,v);
						spanningEdge = make_tuple(w,u,v);
						minCost = w;
					}
			}
		}
		int w, u, v;
		tie(w,u,v) = spanningEdge;
		printf("(w: %d, u: %d, v: %d)\n", w,u,v);
		SpanningTree.push_back(spanningEdge);
		v = get<2>(spanningEdge);
		ReachSet.push_back(v);
		
		UnReachSet.erase(find(UnReachSet.begin(), UnReachSet.end(), v),find(UnReachSet.begin(), UnReachSet.end(), v)+1);
	}
	int MST_cost=0;
	cout << "Minimum Spanning Tree" << endl << "{";
	for(int i = 0 ; i < SpanningTree.size() ; i++){
		int w, u, v;
		tie(w,u,v) = SpanningTree[i];
		printf("(w: %d, u: %d, v: %d),", w,u,v);
		MST_cost += w;
	}
	cout << "}" << endl << "Total Cost of MST: " << MST_cost;
	
}

/*
Example
# 7 vertices, 11 edges
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 7
3 5 6
4 5 8
4 6 9	
5 6 11
*/
