#include <iostream>
#include <cstdlib>

using namespace std;

int x, y, w, h;

int main(){
    cin >> x >> y >> w >> h;
    int answer;
    if(x < abs(w-x)){
        answer = x;
    }else{
        answer = abs(w-x);
    }
    if(y < answer) answer = y;
    if(abs(y-h) < answer) answer = abs(y-h);
    
    cout << answer;
    return 0;
}