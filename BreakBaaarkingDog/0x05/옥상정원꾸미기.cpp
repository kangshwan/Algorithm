#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
stack<int> S;
ll answer;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ll h;
    // pop 되기 전까지 stack에는 모두 내림차순으로 정렬되어 있음.
    // >> 새로 들어온 건물이 stack의 top보다 작다면, stack에 들어있는
    // 모든 건물은 새로운 건물을 볼 수 있음. << 핵심
    // 하지만 새로 들어온 건물이 top보다 클 경우, stack안에서 새 건물보다
    // 큰 건물이 있는지 확인해야함.
    while(N--){
        cin >> h;
        while(!S.empty() && S.top() <= h) S.pop();
        answer += S.size();
        S.push(h);
    }
    cout << answer;
    return 0;
}