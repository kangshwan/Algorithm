#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    int sum = 0;
    stack<int> S;

    while(K--){
        int i;
        cin >> i;
        if (i == 0){
            sum -= S.top();
            S.pop();
        }
        else{
            sum += i;
            S.push(i);
        }
    }
    cout<<sum;
}