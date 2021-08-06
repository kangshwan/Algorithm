#include <iostream>

using namespace std;

int main (void){
    int N, K;
    cin >> N >> K;
    int coins[N];
    for(int i = N-1 ; i > -1 ; i--){
        cin>>coins[i];
    }
    int answer = 0;
    int idx = 0;
    while(K != 0){
        answer += K/coins[idx];
        K=K%coins[idx];
        idx++;
    }
    cout << answer;
}