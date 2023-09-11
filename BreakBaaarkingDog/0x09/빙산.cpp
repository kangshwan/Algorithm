#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int sea[305][305];
int melt[305][305];
bool vis[305][305];
int N, M;
queue<pair<int, int>> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int x = 0 ; x < N ; x++)
        for(int y = 0 ; y < M ; y++)
            cin >> sea[x][y];
    int year = 1;
    while(true){
        // melt first
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                vis[x][y] = false;
                if(sea[x][y] == 0) continue;
                int cnt=0;
                for(int dir = 0 ; dir < 4 ; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(sea[nx][ny]) continue;
                    cnt++;
                }
                melt[x][y] = cnt;
            }
        }
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                sea[x][y] = max(0, sea[x][y]-melt[x][y]);
                melt[x][y] = 0;
            }
        }
        //check
        int part = 0;
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(!sea[x][y] || vis[x][y]) continue;
                vis[x][y] = true;
                Q.push({x,y});
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
                        if(!sea[nx][ny] || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
                part++;
            }
        }
        if(part >= 2){
            cout << year;
            return 0;
        }
        else if(part == 0){
            cout << 0;
            return 0;
        }
        year++;
    }
}