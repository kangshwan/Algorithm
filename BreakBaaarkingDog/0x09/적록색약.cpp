#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[100];
bool vis[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N;
queue<tuple<char, int, int>> Q;
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    //normal
    int ans = 0;
    string asdf;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(vis[i][j]) continue;
            vis[i][j] = true;
            Q.push({board[i][j], i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int nx = get<1>(cur) + dx[i];
                    int ny = get<2>(cur) + dy[i];\
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(get<0>(cur) != board[nx][ny]) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({board[nx][ny], nx, ny});
                }
                
            }
            ans++;
        }
    }
    cout << ans <<' ';
    for(int i = 0 ; i < N ; i++){
        fill(vis[i], vis[i]+N, false);
    }
    //blind
    ans = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(vis[i][j]) continue;
            vis[i][j] = true;
            Q.push({board[i][j], i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int nx = get<1>(cur) + dx[i];
                    int ny = get<2>(cur) + dy[i];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny]) continue;
                    if(get<0>(cur) == 'R'){
                        if(board[nx][ny] == 'R' || board[nx][ny] == 'G'){
                            vis[nx][ny] = true;
                            Q.push({board[nx][ny], nx, ny});
                        }
                    }
                    else if(get<0>(cur) == 'G'){
                        if(board[nx][ny] == 'R' || board[nx][ny] == 'G'){
                            vis[nx][ny] = true;
                            Q.push({board[nx][ny], nx, ny});
                        }
                    }
                    else if(get<0>(cur) == 'B'){
                        if(board[nx][ny] != 'B') continue;
                        vis[nx][ny] = true;
                        Q.push({board[nx][ny], nx, ny});
                    }
                }
            }
            ans++;
        }
    }
    cout<<ans;
}