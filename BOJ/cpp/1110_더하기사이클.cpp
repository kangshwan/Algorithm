#include <iostream>

using namespace std;

int main(){
    int origin;
    cin >> origin;
    int sum_num, first, second;
    if(origin < 10){
        first=0;
        second = origin;
        sum_num = first+second;
    }else{
        first = origin/10;
        second = origin%10;
        sum_num = first + second;
    }
    if(sum_num >= 10){
        sum_num%=10;
    }
    int new_num = second*10+sum_num;
    int count = 1;
    while(new_num != origin){
    	cout << new_num<<endl;
        if(new_num < 10){
            first = 0;
            second = new_num;
            sum_num = first + second;
        }else{
            first = new_num/10;
            second = new_num%10;
            sum_num = first + second;
        }
        if(sum_num>=10){
            sum_num%=10;
        }
        new_num = second*10+sum_num;
        count++;
    }
    cout << count;
}
