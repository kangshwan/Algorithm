#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N, L;
deque<pair<int, int>> DQ;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    int idx = 0;
    while(N--){
        int A;
        cin >> A;
        while(!DQ.empty() && DQ.back().X > A){
            DQ.pop_back();
        }
        DQ.push_back({A, idx});
        if(DQ.front().Y <= idx-L){
            DQ.pop_front();
        }
        cout << DQ.front().X << " ";
        idx++;
    }
}