#include <iostream>
#include <climits>

using namespace std;

int main (){
    int user, M;
    cin >> user >> M;
    int cabin[user][user];
    for(int i = 0 ; i < user ; i++){
        for(int j = 0 ; j < user ; j++){
            if (i == j){
                cabin[i][j] = 0;
            }
            else
                cabin[i][j] = 1000;
        }
    }
    
    int a, b;
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        cabin[a-1][b-1] = 1;
        cabin[b-1][a-1] = 1;
    }
    
    for(int mid = 0 ; mid < user ; mid++){
        for(int from = 0 ; from < user ; from++){
            for(int to = 0 ; to < user ; to++){
                if (from == to) continue;
                cabin[from][to] = min(cabin[from][to],(cabin[from][mid]+cabin[mid][to]));
            }
        }
    }
    pair<int, int> min = make_pair(INT_MAX,INT_MAX);
    
    for(int i = 0 ; i < user ; i++){
        int temp = 0;
        for(int j = 0 ; j < user ; j++){
            temp += cabin[i][j];
        }
        if(min.second > temp){
            min.first = i+1;
            min.second = temp;
        }        
    }
    cout<<min.first;
}