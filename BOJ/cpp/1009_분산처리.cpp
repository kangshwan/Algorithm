#include <iostream>

using namespace std;

int main(void){
    int T;
    cin >> T;
    int a, b;
    for(int i = 0 ; i < T ; i++){
        cin >> a >> b;
        int c = 1;
        for(int j = 0 ; j < b; j++){
            c = (c*a)%10;
        }
        if (c == 0){
            c = 10;
        }
        cout << c << endl;
    }
}