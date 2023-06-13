//재배열 하여 만들어 질 수 있는지?
//즉, word count하여 개수가 동일한지를 확인하면 된다.(네이버 면접에서 물어봤었던 Edit distance랑은 다르다)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        int a[26] = {};
        string s1, s2;
        cin >> s1 >> s2;
        
        for (auto c: s1) a[c-'a']++;
        for (auto c: s2) a[c-'a']--;
        bool isPossible = true;

        for (int i: a){
            if (i != 0) isPossible = false;
        }
        if ( isPossible ) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}