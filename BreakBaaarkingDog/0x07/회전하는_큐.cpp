#include<bits/stdc++.h>
using namespace std;
int N, M;
deque<int> DQ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        DQ.push_back(i);
    }
    
    int moved = 0;
    int ans = 0;
    int mov = 0;
    while(M--){
        int num, idx;
        cin >> num;
        for (int i = 0 ; i < DQ.size() ; i++){
            if(DQ[i] == num) {
                idx = i;
                break;
            }
        }
        if(idx <= DQ.size()/2){
            while(DQ.front() != num){
                DQ.push_back(DQ.front());
                DQ.pop_front();
                ans++;
            }
            DQ.pop_front();
        }else{
            while(DQ.front() != num){
                DQ.push_front(DQ.back());
                DQ.pop_back();
                ans++;
            }
            DQ.pop_front();
        }
    }
    cout << ans;
}
// tlqkf 너무 어렵게 생각했다.... index를 왔다갔다 하면서 계산해야되는줄 알았는데, 그냥 Deque에서 index찾는게 더 빨랐다..