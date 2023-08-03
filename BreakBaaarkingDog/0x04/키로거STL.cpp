#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        string cmd;
        cin >> cmd;
        list<char> pw;
        auto cursor = pw.begin();
        
        for(auto k: cmd){
            // cout << k << '\n';
            if (k == '<'){
                if(cursor != pw.begin()){
                    // cout<<"input < \n";
                    cursor--;
                }
            }
            else if(k == '>'){
                if(cursor != pw.end()){
                    // cout<<"input > \n";
                    cursor++;
                }
            }
            else if(k == '-'){
                if(cursor != pw.begin()){
                    // cout<<"input - \n";
                    cursor--;
                    cursor=pw.erase(cursor);
                }
            }
            else{
                // cout<<"input World \n";
                pw.insert(cursor, k);
                
            }
            // cout << "cursor: " << *cursor << '\n';
            
        }
        for(auto k:pw) cout<<k;
        cout<<'\n';
    } 
}