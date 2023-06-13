#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int boy[7] = {};
int girl[7] = {};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    for(int i = 0 ; i < N ; i++){
        int sex, grade;
        cin >> sex >> grade;
        if( sex == 0 ){
            girl[grade]++;
        }
        else boy[grade]++;
    }

    int answer = 0;
    for (int i = 1 ; i < 7 ; i++){
        if ( boy[i] % K == 0 ) answer += boy[i] / K;
        else answer += boy[i]/K + 1;
        if ( girl[i] % K == 0 ) answer += girl[i] / K;
        else answer += girl[i]/K + 1;
    }
    cout << answer;
}