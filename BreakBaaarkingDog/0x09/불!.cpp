#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[1000];
int visT[1000][1000]; //visited Time
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int R, C;
queue<pair<int, int>> Fq;
queue<pair<int, int>> Jq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        cin >> board[i];
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] == 'J'){
                Jq.push({i,j});
            }
            if(board[i][j] == 'F'){
                Fq.push({i,j});
                visT[i][j]=1;
            }
        }
    }
    while(!Fq.empty()){
        auto cur = Fq.front(); Fq.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == '#' || visT[nx][ny]) continue;
            Fq.push({nx,ny});
            visT[nx][ny] = visT[cur.X][cur.Y] + 1;
        }
    }

    auto cur = Jq.front();
    visT[cur.X][cur.Y] = 1;
    while(!Jq.empty()){
        cur = Jq.front(); Jq.pop();
        if(cur.X == 0 || cur.X == R-1 || cur.Y == 0 || cur.Y == C-1){
            cout << visT[cur.X][cur.Y];
            return 0;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == '#') continue;
            if(visT[nx][ny] && visT[cur.X][cur.Y] + 1 >= visT[nx][ny]) continue;
            Jq.push({nx,ny});
            visT[nx][ny] = visT[cur.X][cur.Y] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}