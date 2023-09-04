#include<bits/stdc++.h>
using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        stack<char> S;
        string str;
        bool cor = true;
        cin >> str;
        for(auto c: str){
            if(c==')'){
                if(S.empty()){
                    cor = false;
                    break;
                }else{
                    S.pop();
                }
            }
            else{
                S.push('(');
            }
        }
        if(S.empty() && cor) cout << "YES\n";
        else cout << "NO\n";
    }
}