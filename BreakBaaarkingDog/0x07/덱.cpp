#include<bits/stdc++.h>
using namespace std;
int N;
deque<int> DQ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        string com;
        cin >> com;
        if (com == "push_front"){
            int num;
            cin >> num;
            DQ.push_front(num);
        }
        else if(com == "push_back"){
            int num;
            cin >> num;
            DQ.push_back(num);
        }
        else if(com == "pop_front"){
            if(!DQ.empty()){
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }else cout << -1 << '\n';
        }
        else if(com == "pop_back"){
            if(!DQ.empty()){
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }else cout << -1 << '\n';
        }
        else if(com == "size"){
            cout << DQ.size() << '\n';
        }
        else if(com == "empty"){
            cout << DQ.empty() << '\n';
        }
        else if(com == "front"){
            if(!DQ.empty()) cout << DQ.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(com == "back"){
            if(!DQ.empty()) cout << DQ.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}