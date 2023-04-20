#include<iostream>
#include<string>
using namespace std;

int nums[10];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    string rlt = to_string(a*b*c);

    for(auto c : rlt){
        nums[c-'0']++;
    }
    for(auto c : nums){
        cout << c << '\n';
    }
}