#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N;
int board[105][105];

//name에 맞는 섬에서 다른 섬까지의 모든 bridge 거리를 계산하기
int makeBridge(int name){
    int dist[105][105];
    queue<pair<int, int>> Q;
    for(int i = 0 ; i < N ; i++){
        fill(dist[i], dist[i]+N, -1);
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] != name) continue;
            dist[i][j] = 0;
            Q.push({i,j});
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
            if(dist[nx][ny] != -1) continue;
            if(board[nx][ny] != 0 && board[nx][ny] != name)
                return dist[cur.X][cur.Y];
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
}

//먼저 모든 섬을 찾는다!
//dfs||bfs로 섬을 나눈다!
//어떤 섬에 대해서, 다른 섬까지 최소가 되는 다리 길이를 찾는다!
//모든 섬에 대해서 반복한다!
//최소를 출력한다!!!

int main(){
    queue<pair<int, int>> Q;
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> board[i][j];
    int cnt = 2;
    // 모든 섬을 찾아서 번호 남겨주기!
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] != 1) continue;
            board[i][j] = cnt;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
                    if(board[nx][ny] != 1) continue;
                    board[nx][ny] = cnt;
                    Q.push({nx,ny});
                }
            }
            cnt++;
        }
    }
    int answer = 200;
    // 각 섬에서 최소가 되는 다리길이 찾기
    for(int island = 2; island < cnt; island++){
        answer = min(answer, makeBridge(island));
    }
    cout << answer;
}