#include<bits/stdc++.h>
using namespace std;
int T, n;
int arr[100005];
int state[100005];
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while(true){
        state[cur] = x;
        cur = arr[cur];
        if(state[cur] == x){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        else if(state[cur] != 0) return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(int i = 1 ; i <= n ; i++) cin >> arr[i];
        for(int i = 1 ; i <= n ; i++){
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
/*
O(N^2)
#include<bits/stdc++.h>
using namespace std;
int T, n;
int arr[100005];

bool iscycle(int idx){
    int cur = idx;
    for(int i = 0 ; i < n ; i++){
        cur = arr[cur];
        if(cur == idx) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
            cin >> arr[i];
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
            if(!iscycle(i)) ans++;
        cout << ans << '\n';
    }
}
*/
/*
나의 풀이.
BFS 문제라고 BFS에 집착하지 말자. 문제를 읽고, 어떤것을 어떻게 사용할 지 생각하자.
#include<bits/stdc++.h>
using namespace std;
int T, n;
int stu[100001];
bool vis[100001];
bool able[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        fill(able, able + n, false);
        cin >> n;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> stu[i];
        }
        
        for(int sp = 1 ; sp <= n ; sp++){
            fill(vis+1, vis+n+1, false);
            queue<int> Q;
            bool teamup = false;
            vis[sp] = true;
            Q.push(sp);
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                int nxt = stu[cur];
                if(nxt == sp){
                    teamup = true;
                    break;
                }
                if(vis[nxt])continue;
                vis[nxt] = true;
                Q.push(nxt);
            }
            if(teamup) able[sp] = true;
            else able[sp] = false;
        }
        int cnt=0;
        for(int i = 1 ; i <= n ; i++){
            if(!able[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}
*/
