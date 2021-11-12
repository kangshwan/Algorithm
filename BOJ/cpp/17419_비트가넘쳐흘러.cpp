#include <iostream>
#include <string>

using namespace std;

int size;

int k[1000000]={0,};
int tmp[1000000]={0,};

bool is_zero(){
	for(int i = 0 ; i < size ; i++){
		if(k[i]==1)
			return false;
	}
	return true;
}

void notoperator(){
	for(int i = 0 ; i < size ; i++){
		if(tmp[i]==0){
			tmp[i]=1;
		}
		else{
			tmp[i]=0;
		}
	}
}

void plusone(){
	for(int i = 0 ; i < size ; i++){
		tmp[i]+=1;
		if(tmp[i]<2)
			return;
		tmp[i]=0;
	}
}

void andoperator(){
	for(int i = 0 ; i < size ; i++){
		tmp[i] = k[i]&tmp[i];
	}
}

void minusk(){
	for(int i = 0 ; i < size ; i++){
		int minused = k[i]-tmp[i];
		if(minused>=0){
			tmp[i]=minused;
		}else{
			k[i+1]--;
			tmp[i]=2 + minused;
		}
	}
}

void copyk(){
	for(int i = 0 ; i < size ; i++){
		k[i] = tmp[i];
	}
}

void kreturn(){
	cout <<"K: ";
	for(int i = size-1 ; i >=0 ; i--){
		cout<<k[i];
	}
	cout<<endl;
}
void tmpreturn(){
	cout<<"tmp: ";
	for(int i = size-1 ; i >=0 ; i--){
		cout<<tmp[i];
	}
	cout<<endl;
}

int main(){
	
	int count = 0;
	cin >> size;
	for(int i = size-1 ; i >=0 ; i--){
		scanf("%1d",&k[i]);
		tmp[i]=k[i];
	}
	while(!is_zero()){
//		kreturn();
		notoperator();
//		tmpreturn();
		plusone();
//		tmpreturn();
		andoperator();
//		tmpreturn();
		minusk();
//		tmpreturn();
		copyk();
		
		count++;
		
	}
	cout << count;
	
	
}
