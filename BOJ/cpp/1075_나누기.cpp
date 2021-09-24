#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    int F;
    cin >> N >> F;
    int divide = N-N%100;
    int min = 2000000000;
    for(int i = 0 ; i < 100 ; i++){
        if((divide+i)%F==0){
            if(min > i){
                min = i;
            }
        }
    }
    if(min < 10){
        cout << 0 << min;
    }
    else{
        cout << min;
    }
}
