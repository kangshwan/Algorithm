#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int nums[10];
int main(void){
    string s;
    cin >> s;
    for (auto c : s){
        nums[c-'0']++;
    }

    nums[6] = (nums[6]+nums[9]+1)/2;
    nums[9] = nums[6];
    // if ((nums[6]+nums[9])%2){
    //     nums[6] = (nums[6]+nums[9])/2+1;
    //     nums[9] = nums[6];
    // }else{
    //     nums[6] = (nums[6]+nums[9])/2;
    //     nums[9] = nums[6];
    // }
    int max = -1;
    for(auto n : nums){
        if (n > max) max = n;
    }
    cout << max;
}