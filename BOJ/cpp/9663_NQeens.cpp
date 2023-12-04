#include <iostream>

using namespace std;

int N;
int board[15][15];
bool visited[15][15];
int answer = 0;

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool inRange(int x, int y){ 
    return (0 <= x && x < N && 0 <= y && y < N);
}
bool canPlace(int x, int y){
    for(int dir = 0 ; dir < 8 ; dir++){
        int nx = x, ny = y;
        for(int i = 0 ; i < N ; i++){
            nx += dx[dir];
            ny += dy[dir];
            if (inRange(nx, ny) && visited[nx][ny]){
                return false;
            }
        }
    }
    return true;
}
void backTrack(int x, int y, int counter){
    cout<<x<<y<<counter<<'\n';
    if (counter == N ){
        answer +=1;
        cout<<"answer:"<<answer<<'\n';
        return ;
    }
    visited[x][y] = true;
    for(int i = x + 1 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if ( !visited[i][j] && canPlace(i,j) ){
                cout<<"canPlace! x: "<<i<<" y: "<<j <<'\n';
                backTrack(i,j,counter+1);
            }
        }
    }
    visited[x][y] = false;
}

int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            backTrack(i,j,1);
        }
    }
    cout<<"Final Answer: "<<answer;    
}