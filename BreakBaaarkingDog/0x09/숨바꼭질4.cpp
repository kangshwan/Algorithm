#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int dist[MAX];
int prv[MAX];
int N, K;
vector<int> ans;
queue<int> Q;
int main(){
    fill(dist, dist+MAX, -1);
    fill(prv, prv+MAX, -1);
    cin >> N >> K;
    dist[N] = 0;
    Q.push(N);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == K){
            cout << dist[K] << '\n';
            ans.push_back(cur);
            while(cur != N){
                cur = prv[cur];
                ans.push_back(cur);
            }
            reverse(ans.begin(), ans.end());
            for(auto k: ans)
                cout << k << ' ';
            return 0;
        }
        if(cur*2 < MAX && dist[cur*2] == -1){
            dist[cur*2] = dist[cur]+1;
            prv[cur*2] = cur;
            Q.push(cur*2);
        }
        if(cur+1 < MAX && dist[cur+1] == -1){
            dist[cur+1] = dist[cur]+1;
            prv[cur+1] = cur;
            Q.push(cur+1);
        }
        if(cur-1 >= 0 && dist[cur-1] == -1){
            dist[cur-1] = dist[cur]+1;
            prv[cur-1] = cur;
            Q.push(cur-1);
        }
    }
}