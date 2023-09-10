#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string board[1002];
int dist[2][1002][1002];
int N, M;
queue<tuple<int,int,int>> Q;
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    int desX = N-1, desY = M-1;
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        int wreck, x, y;
        tie(wreck, x, y) = Q.front(); Q.pop();
        if(x == N-1 && y == M-1){
            cout << dist[wreck][x][y];
            return 0;
        }
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[wreck][nx][ny] != 0) continue;
            if(board[nx][ny] == '1'){
                if(wreck) continue;
                dist[1][nx][ny] = dist[wreck][x][y] + 1;
                Q.push({1,nx,ny});
            }else{
                dist[wreck][nx][ny] = dist[wreck][x][y] + 1;
                Q.push({wreck,nx,ny});
            }
        }
    }
    cout << -1;
    return 0;
}