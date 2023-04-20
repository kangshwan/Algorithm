#include<iostream>
#include<string>
using namespace std;

int a[1000001]={};
bool nums[2000001] = {};
int main(void){
    int n, x;
    int answer = 0;

    cin >> n;
    for (int i = 0 ; i < n ; i++)cin >> a[i];
    cin >> x;
    for(int i = 0 ; i < n ; i++){
        if(x-a[i] > 0 && nums[x-a[i]]) answer++;
        nums[a[i]]=true;
    }
    cout << answer;
}