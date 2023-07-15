#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
	string init;
    cin >> init;
	list<char> L;
	for(auto k: init) L.push_back(k);
	auto cursor = L.end();
	int N;
    cin >> N;
    
	while (N--){
//		cout << "current cursor: "<<*cursor<<"\ncurrent List State\n";
//		for(auto k : L) cout<< k;
//		cout<<'\n';		
		char op;
		cin >> op;
		if (op == 'L' && cursor != L.begin()){
			cursor--;
		}
		else if(op == 'D' && cursor != L.end()){
			cursor++;
		}
		else if(op == 'B' && cursor != L.begin()){
			cursor--;
			cursor=L.erase(cursor);
		}
		else if(op == 'P'){
			char letter;
			cin >> letter;
			L.insert(cursor, letter);			
		}
	}
	for(auto k: L) cout<<k;
}
