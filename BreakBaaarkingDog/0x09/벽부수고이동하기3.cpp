#include<bits/stdc++.h>
using namespace std;
#define MAX 2500
int N, M, K;
string board[1005];
int dist[2][11][1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// time, broken_wall, x, y
queue<tuple<bool, int, int, int>> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    dist[1][0][0][0] = 1;
    Q.push({1,0,0,0});
    while(!Q.empty()){
        int day, k, x, y;
        tie(day,k,x,y) = Q.front(); Q.pop();
        if(x == N-1 && y == M-1){
            cout << dist[day][k][x][y]<<'\n';
            return 0;
        }
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == '0'){
                int nk = k;
                int nday = 1-day;
                if(dist[nday][nk][nx][ny]) continue;
                dist[nday][nk][nx][ny] = dist[day][k][x][y] + 1;
                Q.push({nday, nk, nx, ny});
            }
            else{
                if(k == K) continue;
                //낮이라면
                if(day){
                    int nk = k+1;
                    int nday = 1-day;
                    if(dist[nday][nk][nx][ny]) continue;
                    dist[nday][nk][nx][ny] = dist[day][k][x][y] + 1;
                    Q.push({nday, nk, nx, ny});
                }
                else{
                    int nday = 1-day;
                    if(dist[nday][k][x][y]) continue;
                    dist[nday][k][x][y] = dist[day][k][x][y] + 1;
                    Q.push({nday, k, x, y});
                }
            }
        }
    }
    cout<<-1;
}