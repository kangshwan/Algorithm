#include<iostream>

using namespace std;
int exT, incP, redP; //exerciseTime, increasePulse, reducePulse
int minP, maxP; //minPulse, maxPulse
int main(){
	cin >> exT >> minP >> maxP >> incP >> redP ;
	int time = 0;
	int curP = minP; // currentPulse
	if(minP+incP > maxP){
		cout << -1;
		return 0;
	}
	
	while(exT>0){
		if(curP+incP <= maxP){
			exT--;
			curP+=incP;
		}
		else{
			curP -= redP;
			if(curP < minP)
				curP=minP;
		}
		time++;
	}
	cout << time;
	return 0;
}
