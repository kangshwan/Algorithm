#include <iostream>
#define INF 10000

using namespace std;

int main (void){
    int N ;
    cin >> N;

    int graph[N][N], temp;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            if(temp == 0 && i!=j){
                graph[i][j] = INF;
            }
            else
                graph[i][j] = temp;
        }
    }
    for(int bypass = 0 ; bypass < N ; bypass++){
        for(int start = 0 ; start < N ; start++){
            for(int end = 0 ; end < N ; end++){
                graph[start][end] = min(graph[start][end], graph[start][bypass]+graph[bypass][end]);
            }
        }
    }
	printf("\nFloyd-Warshall solution:\n");
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(graph[i][j] != INF){
                cout << graph[i][j] << " ";
            }else
                cout << "INF" << " ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Example 1
4
0 3 0 7
8 0 2 0
5 0 0 1
2 0 0 0

Answer 1
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0

Example 2
4
0 4 0 6
3 0 7 0
5 0 0 4
0 0 2 0

Answer 2
0 4 8 6
3 0 7 9
5 9 0 4
7 11 2 0

Example 3
5
0 5 7 2 1
5 0 3 6 0
7 3 0 10 0
2 6 10 0 4
1 0 0 4 0

Answer 3
0 5 7 2 1
5 0 3 6 6
7 3 0 9 8
2 6 9 0 3
1 6 8 3 0
*/

