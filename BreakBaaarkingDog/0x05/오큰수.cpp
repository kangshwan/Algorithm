#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N;
stack<pair<int, int>> S;
int answer[1000001] = {-1, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        answer[i]=-1;
    }
    int num;
    for(int idx = 0 ; idx < N ; idx++){
        cin >> num;
        while(!S.empty() && S.top().X < num){
            answer[S.top().Y] = num;
            S.pop();
        }
        S.push({num, idx});
    }
    for (int i = 0 ; i < N ; i++){
        cout << answer[i] <<' ';
    }
}