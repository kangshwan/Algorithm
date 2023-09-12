#include<bits/stdc++.h>
using namespace std;
int dx[12] = {0,1,0,-1,1,1,2,2,-1,-1,-2,-2};
int dy[12] = {1,0,-1,0,2,-2,1,-1,2,-2,1,-1};
int dist[31][205][205];
int board[205][205];
queue<tuple<int, int, int>> Q;
int K, W, H;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> W >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> board[i][j];
        }
    }
    for(int k = 0 ; k <= K ; k++)
        for(int i = 0 ; i < H ; i++)
            fill(dist[k][i], dist[k][i]+W, -1);
    dist[0][0][0] = 0;
    Q.push({0,0,0});
    while(!Q.empty()){
        int k, x, y;
        tie(k,x,y) = Q.front(); Q.pop();
        if(x == H-1 && y == W-1){
            // showDist();
            cout << dist[k][x][y];
            return 0;
        }
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] == 1) continue;
            if(dist[k][nx][ny] != -1)continue;
            dist[k][nx][ny] = dist[k][x][y] + 1;
            Q.push({k,nx,ny});
        }
        if(k+1 <= K){
            for(int dir = 4 ; dir < 12 ; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == 1) continue;
                if(dist[k+1][nx][ny] != -1)continue;
                dist[k+1][nx][ny] = dist[k][x][y] + 1;
                Q.push({k+1,nx,ny});
            }
        }
    }
    cout << -1;
}