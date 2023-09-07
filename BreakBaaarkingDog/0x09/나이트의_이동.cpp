#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool vis[310][310];
int dist[310][310];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int T, L;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        queue<pair<int, int>> Q;
        int x, y, desx, desy;
        cin >> L;
        for(int i = 0 ; i < L ; i++){
            fill(vis[i], vis[i]+L, false);
            fill(dist[i], dist[i]+L, 0);
        }
        cin >> x >> y;
        cin >> desx >> desy;
        vis[x][y] = true;
        Q.push({x,y});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(cur.X == desx && cur.Y == desy){
                cout << dist[cur.X][cur.Y] << '\n';
                break;
            }
            for(int dir = 0 ; dir < 8 ; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                // cout << nx << ' ' << ny << '\n';
                if(nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
                if(vis[nx][ny]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                vis[nx][ny] = true;
                Q.push({nx,ny});
            }
        }
    }
}