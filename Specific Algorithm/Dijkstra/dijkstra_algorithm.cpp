#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

int n;
int m;

class MinHeap{
	private:
		//pair < 현재 노드 , 노드까지 0번에서부터 최단거리>
		pair<int, int> *heap;
		
		int heap_count = 0;
	public:
		MinHeap(int n){
			heap = new pair<int, int>[35000000];
		};
		void swap(pair<int, int>* a, pair<int, int>*b ){
			pair<int, int> tmp = *a; *a = *b ; *b = tmp;
		};
	
		void push(pair<int, int> data){
				//힙의 끝에 데이터 추가 
			heap[++heap_count] = data;
			
			//child와 parent 비교하면서 올라가기.
			int child = heap_count;
			int parent = child/2;
			while ( child > 1 && heap[parent].second > heap[child].second){
				swap(&heap[parent], &heap[child]);
				child = parent;
				parent = child/2;
			}
		};
		
		int pop(){
			//힙의 첫번째 원소를 반환, 기존에서는 pair<int, int>를 반환하는게 맞지만, 중요한것은 node기 때문에 node번호만을 반환. 
			int result = heap[1].first;
			
			//가장 첫번째 원소를 마지막 원소와 교체
			//가장 끝 원소는 더이상 사용하지 않기 때문에 heap_count 내리기
			swap(&heap[1], &heap[heap_count--]);
			
			int parent = 1;
			int child = parent*2;
			if(child+1<=heap_count){
				child = (heap[child].second < heap[child+1].second) ? child : child+1;
			}
			while(child <= heap_count && heap[parent].second > heap[child].second){
				swap(&heap[parent], &heap[child]);
				
				parent = child;
				child = child*2;
				if(child+1<=heap_count){
					child = (heap[child].second < heap[child+1].second) ? child : child+1;
				}
			}
			return result;
		}
		int size(){
			return heap_count;
		}
	
};

int main() {
	cin >> n >> m;
	vector<pair<int, int> > graph[n];
	cout << endl;
	bool visited[n] = {false,};
	int shortest[n];
	for(int i = 0 ; i < n ; i ++){
		shortest[i] = INT_MAX;
	}
	shortest[0] = 0;
	
	MinHeap minHeap = MinHeap(n);
	
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,m));
	}
	
	minHeap.push(make_pair(0,0));
	// for(int i = 0 ; i < n ; i++){
	// 	for(unsigned long j = 0 ; j < graph[i].size() ; j++){
	// 		cout << "u: "<< i << " v: "<<graph[i][j].first << " w: " << graph[i][j].second << endl;
	// 	}
	// }
	
	while(minHeap.size() != 0){
		int node = minHeap.pop();
		if(visited[node])
			continue;
		visited[node] = true;
		// cout << "node "<<node<<" visited."<<endl;
		for(unsigned long i = 0 ; i < graph[node].size() ; i++){
			int v = graph[node][i].first;
			int w = graph[node][i].second;
			// cout << "shortest[" <<v<<"]: "<< shortest[v] << " shortest["<<node<<"]: "<<shortest[node]<<endl;
			shortest[v] = (shortest[v] < shortest[node]+w) ? shortest[v] : shortest[node]+w;
			// cout << "u: "<< node << " v: "<<graph[node][i].first << " shortest: " << shortest[v] << endl;
			if(!visited[v]){
				// cout << "push v: "<< v << endl;
				minHeap.push(make_pair(v, shortest[v]));
			}
		}
		// cout << "out of for loop"<<endl;
		
	}
	for(int i = 0 ; i < n ; i++){
		if(shortest[i] == INT_MAX){
			cout << "inf ";
		}
		else{
			cout << shortest[i] << " ";
		}
	}
	return 0;
}