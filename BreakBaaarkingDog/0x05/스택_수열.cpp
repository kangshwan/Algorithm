#include <bits/stdc++.h>
using namespace std;
char answer[200002];
int idx = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, num = 1;
    stack<int> S;
    
    cin >> N;
    while (N--){
        int i;
        cin >> i;

        if(S.empty()){
            S.push(num++);
            answer[idx++] = '+';
        }

        while (S.top() < i){
            S.push(num++);
            answer[idx++] = '+';
        }

        if (S.top() == i){
            S.pop();
            answer[idx++] = '-';
        } else{
            cout <<"NO";
            return 0;
        }
    }
    for(int i = 0 ; i < idx ; i++){
        cout<<answer[i]<<"\n";
    }
}