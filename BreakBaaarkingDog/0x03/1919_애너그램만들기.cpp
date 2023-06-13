#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    
    int a[26] = {0,};
    for(auto c: s1) a[c-'a']++;
    for(auto c: s2) a[c-'a']--;
    
    int answer = 0;
    for(auto n: a) answer += abs(n);
    cout << answer;
}