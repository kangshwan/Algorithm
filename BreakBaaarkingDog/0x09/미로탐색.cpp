#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int, int>> Q;
int N, M;

int main(){
    cin >> N >> M;
    string line;
    for(int i = 0 ; i < N ; i++){
        cin >> line;
        for(int j = 0 ; j < M ; j++){
            board[i][j] = line[j]-'0';
        }
    }
    Q.push({0,0});
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == 1){
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    cout<<board[N-1][M-1];
}