#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string comm;
    cin >> comm;
    stack<pair<char, int>> S;
    int idx = 0, ans = 0;
    for(auto k: comm){
        if(k=='('){
            S.push({k,idx});
        }
        else{
            if(idx - S.top().Y == 1){
                S.pop();
                ans+=S.size();
            }else{
                S.pop();
                ans++;
            }
        }
        idx++;
    }
    cout << ans;
}