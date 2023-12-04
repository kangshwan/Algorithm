#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int M, N;
int board[1000][1000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans = -1;
queue<pair<int, int>> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny]) continue;
            board[nx][ny] = board[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(!board[i][j]){
                cout << -1;
                return 0;
            }
            ans = max(ans, board[i][j]);
        }
    }
    cout << ans-1;
}