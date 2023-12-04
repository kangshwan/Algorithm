#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

int main(){    
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int n;
        cin >> n;
        if (n == 0) break;
        stack<pair<ll, ll>> S;
        long long ans = 0;

        for(int w = 0 ; w < n ; w++){
            int h;
            cin >> h;
            int idx = w;
            while(!S.empty() && S.top().X >= h){
                ans = max(ans, S.top().X * (w - S.top().Y));
                idx = S.top().Y;
                S.pop();
            }
            S.push({h, idx});
        }
        while(!S.empty()){
            ans = max(ans, S.top().X * (n-S.top().Y));
            S.pop();
        }
        cout << ans << '\n';
    }
}
/*
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
7 2 1 4 5 4 3 3
0
*/