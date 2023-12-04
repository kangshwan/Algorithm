#include<bits/stdc++.h>
using namespace std;
string board[32][32];
int dist[32][32][32];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int L,R,C;
queue<tuple<int, int, int>> Q;
int main(){
    while(true){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> L >> R >> C;
        if(L == 0) break;
        for(int l = 0 ; l < L ; l++){
            for(int r = 0 ; r < R ; r++){
                cin >> board[l][r];
                for(int c = 0 ; c < C ; c++){
                    dist[l][r][c] = -1;
                    if(board[l][r][c] == 'S') {
                        dist[l][r][c] = 0;
                        Q.push({l,r,c});
                    }
                    if(board[l][r][c] == '#') dist[l][r][c] = 0;
                }
            }
        }
        int trapped = true;
        while(!Q.empty()){
            int z, x, y;
            tie(z,x,y) = Q.front(); Q.pop();
            if(board[z][x][y] == 'E'){
                trapped = false;
                cout << "Escaped in " << dist[z][x][y] << " minute(s).\n";
            }
            for(int dir = 0 ; dir < 6 ; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
                if(dist[nz][nx][ny] != -1) continue;
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                Q.push({nz,nx,ny});
            }
        }
        if(trapped) cout << "Trapped!" << '\n';
    }
}
/*
3 10 10
S.........
#########.
#########.
#########.
#########.
#########.
#########.
#########.
#########.
#########.

##########
.........#
.........#
.#########
.#########
.#########
.#########
.#########
.........#
..........

##########
#######.##
#######.##
#######.##
#######.##
#######.##
#######.##
#######.##
######E.##
##########

0 0 0
*/