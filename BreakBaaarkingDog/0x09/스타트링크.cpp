#include<bits/stdc++.h>
using namespace std;
int dist[1000001];
queue<int> Q;
int F,S,G,U,D;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dist[0] = 0;
    cin >> F >> S >> G >> U >> D;
    if(G == S){
        cout << 0;
        return 0;
    }
    fill(dist, dist+F+1, -1);
    dist[S] = 0;
    Q.push(S);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int up = cur+U;
        if(up == G){
            cout << dist[cur] + 1;
            return 0;
        }
        if(0 < up && up <= F){
            if(dist[up] == -1){
                dist[up] = dist[cur] + 1;
                Q.push(up);
            }
        }
        int dn = cur-D;
        if(dn == G){
            cout << dist[cur] + 1;
            return 0;
        }
        if(0 < dn && dn <= F){
            if(dist[dn] == -1){
                dist[dn] = dist[cur] + 1;
                Q.push(dn);
            }
        }
    }
    cout << "use the stairs";
}