#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int T;
    double x_1, y_1, r_1, x_2, y_2, r_2;
    cin>>T;
    for(int i = 0 ; i < T ; i++){
        cin>>x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        //한점에서 접할때
        double dist = sqrt(pow(x_1-x_2,2)+pow(y_1-y_2,2));
        if(((x_1 == x_2) && (y_1 == y_2))){
        	if(r_1 == r_2){
        		cout<<-1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
        else if((r_1+r_2) == dist || abs(r_1-r_2) == dist ){
            cout<<1<<endl;
        }
        else if(abs(r_1-r_2) < dist &&dist < (r_1+r_2)){
            cout<<2<<endl;
        }

    }
}
