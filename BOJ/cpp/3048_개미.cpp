#include<iostream>

using namespace std;

int n1,n2;
char ants[100];

int main(){
	cin>>n1>>n2;
	char ant1[n1];

	for(int i = n1-1; i >= 0 ; i--){
		scanf(" %1c",&ants[i]);
		ant1[i]=ants[i];
	}
	for(int i = n1 ; i < n1+n2;i++){
		scanf(" %1c",&ants[i]);
	}
	int group1[n1];
	for(int i = 0 ; i < n1 ; i++){
		group1[i]=n1-1-i;
	}
	
	cout<<endl;
	int T;
	cin >> T;
	int timer = 0;
	while(T--){
		int i = 0;
		while(i < n1+n2+1){
			bool swap = true;
			for(int j = 0 ; j < n1 ; j++){
				if(ants[i+1] == ant1[j]){
					swap = false;
					break;
				}
			}
			if(swap){
				
			}
			i+=1
		}
		timer++;
	}
	for(int i = 0 ; i <n1+n2;i++){
		cout<<ants[i];
	}
}
