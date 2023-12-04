#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        string p;
        string data;
        int n;
        deque<int> DQ;
        cin >> p;
        cin >> n;
        cin >> data;
        int cnt = 0;
        for(int i = 1 ; i+1 < data.size() ; i++){
            if(data[i] == ','){
                DQ.push_back(cnt);
                cnt=0;
            }else{
                cnt = 10 * cnt + (data[i]-'0');
            }
        }
        if(cnt != 0) DQ.push_back(cnt);

        int rev = 0;
        bool err = false;
        for(char k: p){
            if(k == 'D'){
                if(DQ.empty()){
                    err = true;
                    break;
                }
                if(rev) DQ.pop_back();
                else DQ.pop_front();
            }else if(k == 'R') rev = 1-rev;
        }
        if(err) cout << "error\n";
        else{
            if(rev) reverse(DQ.begin(), DQ.end());
            cout<<'[';
            for(int i = 0 ; i < DQ.size() ; i++){
                cout << DQ[i];
                if(i+1 != DQ.size()) cout << ',';
            }
            cout << "]\n";
        }
    }
}