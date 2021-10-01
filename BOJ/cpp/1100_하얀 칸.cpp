#include <iostream>
using namespace std;
int board[8][8] = {{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};
char chess_piece[8][8];
int main (){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            cin >> chess_piece[i][j];
        }
    }
    int count = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if (board[i][j] && chess_piece[i][j] == 'F')
                count++;
        }
    }
    cout << count;
}