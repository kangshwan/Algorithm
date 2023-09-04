#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stack<char> S;
    int ans = 0;
    int tmp = 1;
    cin >> str;
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '('){
            tmp *= 2; // 곱할 값 2배 증가
            S.push(str[i]);
        }
        else if(str[i] == '['){
            tmp *= 3;
            S.push(str[i]);
        }
        /*
        직전 괄호가 여는 괄호라면~
        수식의 꼭대기 까지 왔다는 뜻이기 때문에
        tmp를 ans에 더한다.
        */
        else if(str[i] == ')'){
            if(S.empty() || S.top() != '('){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') ans += tmp;
            S.pop();
            tmp /= 2;
        }
        else if(str[i] == ']'){
            if(S.empty() || S.top() != '['){
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') ans += tmp;
            S.pop();
            tmp /= 3;
        }
    }
    if(S.empty()) cout << ans;
    else cout << 0;
}