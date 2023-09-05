#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[500][500];
bool visited[500][500];
queue<pair<int, int>> Q;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m;

bool inRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}
int BFS(int x, int y){
    int size=1;
    visited[x][y] = true;
    Q.push({x,y});
    while(!Q.empty()){
        int cX = Q.front().X;
        int cY = Q.front().Y;
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nX= cX + dx[i], nY = cY + dy[i];
            if(inRange(nX, nY) && board[nX][nY] && !visited[nX][nY]){
                visited[nX][nY] = true;
                Q.push({nX,nY});
                ++size;
            }
        }
    }
    return size;
}
int main(){
    int numPic = 0;
    int maxPic = 0;
    cin >> n >> m;
    string info;
    cin.ignore();
    for(int i = 0 ; i < n ; i++){
        getline(cin, info);
        int j = 0;
        for(auto k: info){
            if(k != ' '){
                board[i][j++] = k-'0';
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] && !visited[i][j]){
                maxPic = max(maxPic, BFS(i,j));
                ++numPic;
            }
        }
    }
    cout<<numPic<<'\n'<<maxPic;
}