#include<bits/stdc++.h>
using namespace std;
int dist[200002];
bool vis[200002];
int N, K;
queue<int> Q;
int main(){
    cin >> N >> K;
    vis[N] = true;
    Q.push(N);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == K){
            cout << dist[cur];
            return 0;
        }
        if(cur-1 >= 0 && !vis[cur-1]){
            dist[cur-1] = dist[cur] + 1;
            vis[cur-1] = true;
            Q.push(cur-1);
        }
        if(cur+1 <= 100000 && !vis[cur+1]){
            dist[cur+1] = dist[cur] + 1;
            vis[cur+1] = true;
            Q.push(cur+1);
        }
        if(2*cur <= 100000 && !vis[2*cur]){
            dist[2*cur] = dist[cur] + 1;
            vis[2*cur] = true;
            Q.push(2*cur);
        }
    }
}