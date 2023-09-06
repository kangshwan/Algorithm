#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int T,M, N, K;
int board[50][50];
bool vis[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int, int>> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        int ans = 0;
        for(int i = 0 ; i < M ; i++){
            fill(board[i], board[i] + N, 0);
            fill(vis[i], vis[i] + N, false);
        }
        int x,y;
        while(K--){
            cin >> x >> y;
            board[x][y] = 1;
        }
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(board[i][j] && !vis[i][j]){
                    vis[i][j] = true;
                    Q.push({i,j});
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0 ; dir < 4 ; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                            if(!board[nx][ny] || vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            Q.push({nx,ny});
                        }
                    }
                    ans++;
                }
            }
        }
        cout << ans<<'\n';
    }
}