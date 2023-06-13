#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int nums[100]={};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }

    int v;
    cin >> v;
    
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        if( nums[i] == v) count++;
    }
    cout << count;
}