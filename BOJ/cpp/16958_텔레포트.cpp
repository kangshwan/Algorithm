#include <iostream>
#include <tuple>
#include <stdlib.h>

using namespace std;
int t_time;
int distance(int* a_special, int* b_special, pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
    int n_city;
    cin >> n_city >> t_time;
    int time_table[n_city][n_city];
    
    pair<int, int> coordinate[n_city];
    int special[n_city]={false,};

    for(int i = 0 ; i < n_city ; i++){
        cin >> special[i] >> coordinate[i].first >> coordinate[i].second;   
    }
    for(int i = 0; i < n_city; i++){
        for(int j = 0; j < n_city; j++){
            if(i == j){
                time_table[i][j]=0;
            }
            else{
                int dist = distance(&special[i], &special[j], coordinate[i], coordinate[j]);
                if(special[i]==1 && special[j]==1){
                    dist = dist > t_time ? t_time : dist;
                }
                time_table[i][j] = dist;
            }
        }
    }
    for(int k = 0 ; k < n_city ; k++){
        for(int i = 0; i < n_city; i++){
            for(int j = 0; j < n_city; j++){
                if(i==j) continue;
                time_table[i][j] = min(time_table[i][j], ( time_table[i][k] + time_table[k][j] ));
            }
        }
    }

    int M_to_print, a, b;
    cin >> M_to_print;
    int answer[M_to_print];
    for(int i = 0 ; i < M_to_print ; i++){
        cin >> a >> b;
        answer[i]=time_table[a-1][b-1];
    }
    for(int i = 0 ; i < M_to_print ; i++){
        cout << answer[i]<<endl;
    }
}