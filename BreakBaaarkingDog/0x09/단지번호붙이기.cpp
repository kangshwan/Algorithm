#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<pair<int, int>> Q;
string board[25];
bool vis[27][27];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N;
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin>>board[i];
    }
    int cnt=0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == '0') continue;
            if(vis[i][j]) continue;
            int house = 1;
            vis[i][j] = true;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny] || board[nx][ny] == '0') continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                    house++;
                }
            }
            cnt++;
            ans.push_back(house);
        }
    }
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for(auto k: ans){
        cout << k << '\n';
    }
}