#include<bits/stdc++.h>
using namespace std;

int N;
queue<int> Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        string com;
        cin >> com;
        if (com == "push"){
            int num;
            cin >> num;
            Q.push(num);
        }
        else if(com == "pop"){
            if(!Q.empty()){
                cout << Q.front() << '\n';
                Q.pop();
            }else cout << -1 << '\n';
        }
        else if(com == "size"){
            cout << Q.size() <<'\n';
        }
        else if(com == "empty"){
            cout << Q.empty() << '\n';
        }
        else if(com == "front"){
            if(!Q.empty()) cout << Q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(com == "back"){
            if(!Q.empty()) cout << Q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}