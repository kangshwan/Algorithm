#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        bool bal = true;
        string str;
        stack<char> S;
        getline(cin, str);
        if(str == ".") break;
        for(char a: str){
            if(a == '.'){
                break;
            }
            if(a == '(' || a == '[') S.push(a);
            else if(a == ')'){
                if(S.empty() || S.top() != '('){
                    bal = false;
                    break;
                }
                S.pop();
            }else if(a == ']'){
                if(S.empty() || S.top() != '['){
                    bal = false;
                    break;
                }
                S.pop();
            }
        }
        if(!S.empty()) bal = false;
        if(bal) cout << "yes\n";
        else cout << "no\n";
    }
}