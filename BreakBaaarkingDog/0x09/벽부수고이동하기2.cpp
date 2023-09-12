#include<bits/stdc++.h>
using namespace std;
string board[1001];
int dist[11][1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<tuple<int, int, int>> Q;
int N, M, K;
int main(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    dist[0][0][0]= 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        int k, x, y;
        tie(k, x, y) = Q.front(); Q.pop();
        if(x == N-1 && y == M-1){
            cout << dist[k][x][y];
            return 0;
        }
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >=M) continue;
            if(dist[k][nx][ny] != 0) continue;
            if(board[nx][ny] == '1'){
                if(k+1 > K) continue;
                if(dist[k+1][nx][ny] == 0 || dist[k+1][nx][ny] > dist[k][x][y] + 1){
                    dist[k+1][nx][ny] = dist[k][x][y] + 1;
                    Q.push({k+1, nx, ny});
                }
            }else{
                dist[k][nx][ny] = dist[k][x][y] + 1;
                Q.push({k,nx,ny});
            }
        }
    }
    cout << -1;
}