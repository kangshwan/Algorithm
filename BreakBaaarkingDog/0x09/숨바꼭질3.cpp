#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
int dist[MAX];
int N, K;
queue<int> Q;
int main(){
    cin >> N >> K;
    fill(dist, dist+MAX, -1);
    dist[N] = 0;
    Q.push(N);
    while(!Q.empty()){
        int cur = Q.front();Q.pop();
        if(cur*2 <= MAX){
            if(dist[cur*2] == -1 || dist[cur*2] > dist[cur]){
                dist[cur*2] = dist[cur];
                Q.push(cur*2);
            }
        }
        if(cur+1 <= MAX){
            if(dist[cur+1] == -1 || dist[cur+1] > dist[cur] + 1){
                dist[cur+1] = dist[cur] + 1;
                Q.push(cur+1);
            }
        }
        if(cur-1 >= 0){
            if(dist[cur-1] == -1 || dist[cur-1] > dist[cur] + 1){
                dist[cur-1] = dist[cur] + 1;
                Q.push(cur-1);
            }
        }
    }
    cout << dist[K];
}
/*
1 3
ans: 1
*/