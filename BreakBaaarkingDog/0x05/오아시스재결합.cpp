#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
long long answer;
stack<pair<int, int>> S;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int h;
    while (N--){
        cin >> h;
        int cnt = 1;
        while(!S.empty() && S.top().X <= h){
            answer += S.top().Y;
            if(S.top().X == h) cnt += S.top().Y;
            S.pop();
        }
        if(!S.empty()) answer++;
        S.push({h, cnt});
    }
    cout << answer;
}