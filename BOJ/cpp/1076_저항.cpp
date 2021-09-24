#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, int > table;
    table.insert(make_pair("black", 0));
    table.insert(make_pair("brown", 1));
    table.insert(make_pair("red", 2));
    table.insert(make_pair("orange", 3));
    table.insert(make_pair("yellow", 4));
    table.insert(make_pair("green", 5));
    table.insert(make_pair("blue", 6));
    table.insert(make_pair("violet", 7));
    table.insert(make_pair("grey", 8));
    table.insert(make_pair("white", 9));
    
    string first, second, third;
    cin >> first >> second >> third;
    int answer = table[first]*10 + table[second];
    if (answer == 0){
    	cout << answer;
    	return 0;
	}
	cout << answer;
    for(int i = 0 ; i < table[third] ; i++){
        cout << 0;
    }
}
