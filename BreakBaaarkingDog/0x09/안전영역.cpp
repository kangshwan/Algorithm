#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N;
int board[102][102];
bool vis[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int, int>> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int maxRain=-1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
            maxRain = max(maxRain, board[i][j]);
        }
    }
    int ans=1;
    for(int rain = 1 ; rain <= maxRain ; rain++){
        for(int i = 0 ; i < N ; i++){
            fill(vis[i], vis[i]+N, false);
        }
        int cnt = 0;
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < N ; y++){
                if(board[x][y] <= rain) continue;
                if(vis[x][y]) continue;
                vis[x][y] = true;
                Q.push({x,y});
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(board[nx][ny] <= rain) continue;
                        if(vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}