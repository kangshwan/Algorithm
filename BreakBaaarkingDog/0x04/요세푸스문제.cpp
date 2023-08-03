#include<bits/stdc++.h>
using namespace std;
const int MX = 5001;
int pre[MX], nxt[MX];
int dat[MX];
int unused = 1;
int N, K, len = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    len = N;
    for(int i = 1; i<=N;i++){
        pre[i] = (i == 1) ? N : i-1;
        nxt[i] = (i == N) ? 1 : i+1;
        dat[i] = i;
    }
    int i = 1;
    cout << "<";
    for(int cur = 1 ; len > 0 ; cur = nxt[cur]){
        if(i == K){
            cout<<dat[cur];
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            --len;
            if (len != 0){
                cout<<", ";
            }
            i=1;
        }else i++;
    }
    cout<<'>';
    
}