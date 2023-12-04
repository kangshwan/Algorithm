#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string board[1002];
// 불
int dist1[1002][1002];
// 상근이
int dist2[1002][1002];
int T, w, h;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        queue<pair<int, int>> Q1;
        queue<pair<int, int>> Q2;
        bool impossible = true;
        cin >> w >> h;
        for(int i = 0 ; i < h ; i++){
            cin >> board[i];
            for(int j = 0 ; j < w ; j++){
                dist1[i][j] = -1;
                dist2[i][j] = -1;
                if(board[i][j] == '*'){
                    dist1[i][j] = 0;
                    Q1.push({i, j});
                }
                if(board[i][j] == '@'){
                    dist2[i][j] = 0;
                    Q2.push({i, j});
                }
            }   
        }
        // cout << "FIRE" << '\n';
        while(!Q1.empty()){
            auto cur = Q1.front(); Q1.pop();
            // cout << cur.X << ' ' << cur.Y<<'\n';
            for(int dir = 0 ; dir < 4 ; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist1[nx][ny] != -1 || board[nx][ny] != '.') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx, ny});
            }
        }
        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            // cout << cur.X << ' ' << cur.Y<<'\n';
            if(cur.X == 0 || cur.X == h-1 || cur.Y == 0 || cur.Y == w-1){
                cout << dist2[cur.X][cur.Y] + 1 << '\n';
                impossible = false;
                break;
            }
            for(int dir = 0 ; dir < 4 ; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist2[nx][ny] != -1 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] != -1 && dist2[cur.X][cur.Y]+1 >= dist1[nx][ny]) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx,ny});
            }
        }
        if(impossible) cout << "IMPOSSIBLE" << '\n';
    }
}