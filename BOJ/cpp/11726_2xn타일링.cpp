#include <iostream>
int main(void){
    int N=0;
    std::cin>>N;
    int answer=1;
    int before_ans=1;
    int temp=0;
    for(int i = 1;i<N;i++){
    	temp=answer%10007;
    	answer+=before_ans;
    	before_ans=temp;
	}
	std::cout<<answer%10007;
}
