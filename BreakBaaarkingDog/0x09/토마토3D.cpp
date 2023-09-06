#include<bits/stdc++.h>
using namespace std;
int dx[6] = {0,0,1,0,-1,0};
int dy[6] = {0,0,0,-1,0,1};
int dz[6] = {1,-1,0,0,0,0};
int board[100][100][100];
int dist[100][100][100];
int M, N, H;
//          z, x, y
queue<tuple<int,int,int>> Q;
int main(){
    cin >> M >> N >> H;
    for(int z = 0 ; z < H ; z++){
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                cin >> board[z][x][y];
                if(board[z][x][y] == 1) {
                    Q.push({z,x,y});
                }
                if(board[z][x][y] == 0){
                    dist[z][x][y] = -1;
                }
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur;
        for(int dir = 0 ; dir < 6 ; dir++){
            int nz = curZ + dz[dir];
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nz][nx][ny] >= 0) continue;
            dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
            Q.push({nz, nx, ny});
        }
    }
    int ans = -1;
    for(int z = 0 ; z < H ; z++){
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(dist[z][x][y] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[z][x][y]);
            }
        }
    }
    cout << ans;
}