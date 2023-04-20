#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int alpha[26];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
 
    // fill(alpha, alpha+26,0);
    cin >> s;
    for(auto c : s){
        alpha[c-'a']++;
    }
    for(int n : alpha){
        cout << n << ' '; 
    }
}