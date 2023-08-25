#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
stack<pair<int, int>> S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    S.push({100000001, 0});
    for(int i = 1 ; i <= N ; i++){
        int height;
        cin >> height;
        while(S.top().X < height)
            S.pop();
        cout << S.top().Y << " ";
        S.push({height, i});
    }
}