#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, answer;
stack<pair<int, int>> S;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int h;
    while (N--){
        cin >> h;
        if(S.empty()) S.push({h,0});
        else{
            if (S.top().X <= h) S.push({h, S.top().Y+1});
            else S.top().Y++;
        }
    }
    while(!S.empty()){
        answer += S.top().Y;
        S.pop();
    }
    cout << answer;
}