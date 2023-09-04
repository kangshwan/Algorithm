#include<bits/stdc++.h>
using namespace std;
int N;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--){
        stack<char> S;
        string str;
        cin >> str;
        for(auto k : str){
            if(k=='A'){
                if(S.empty() || S.top() != 'A'){
                    S.push(k);
                }
                else S.pop();
            }
            if(k=='B'){
                if(S.empty() || S.top() != 'B'){
                    S.push(k);
                }
                else S.pop();
            }
        }
        if(S.empty()) ans++;
    }
    cout << ans;
}
/*
1
ABABABBABABA
*/