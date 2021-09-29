#include <iostream>
#include <climits>
using namespace std;

int main(){
    int nums[5];
    int start = INT_MAX;
    for(int i = 0 ; i < 5 ; i++){
        cin >> nums[i];
        if(start > nums[i]){
            start = nums[i];
        }
    }
    
    while(true){
        int count = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(start%nums[i] == 0){
                count++;
            }
            if(count == 3){
                cout << start;
                return 0;
            }
        }
        start++;
    }
}