#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool vis[102][102];
queue<pair<int, int>> Q;
vector<int> answer;
int M, N, K;
int main(){
    cin >> M >> N >> K;
    while(K--){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        //여기 그냥 찍어보고 했는데, 왜 이렇게 됐을까?
        for(int i = sx ; i < ex ; i++){
            for(int j = sy ; j < ey ; j++){
                vis[j][i] = true;
            }
        }
    }
    
    for(int x = 0 ; x < M ; x++){
        for(int y = 0 ; y < N ; y++){
            if(vis[x][y]) continue;
            int count = 1;
            vis[x][y] = true;
            Q.push({x,y});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny]) continue;
                    count++;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
            answer.push_back(count);
        }
    }
    cout<<answer.size()<<'\n';
    sort(answer.begin(), answer.end());
    for(auto k: answer){
        cout << k << ' ';
    }
}