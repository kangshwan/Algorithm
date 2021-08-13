#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int N;
    cin >> N;
    vector<tuple<int, int>> work_list;
    int w_time, deadline;

    for(int i = 0 ; i < N ; i++){
        cin >> w_time >> deadline;
        work_list.push_back(make_tuple(w_time, deadline));
    }

    sort(work_list.begin(),work_list.end(), [](const tuple<int, int> &a, const tuple<int, int> &b){
        if(get<1>(a) != get<1>(b)){
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });
    
    int ans_time = get<1>(work_list[0]) - get<0>(work_list[0]);
    for(int i = 1 ; i < N ; i++){
        if(ans_time > get<1>(work_list[i])){
            ans_time = get<1>(work_list[i]);
        }
        ans_time -= get<0>(work_list[i]);
    }
    ans_time < 0 ? cout << -1 : cout << ans_time;
}
