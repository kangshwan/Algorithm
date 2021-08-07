#include <iostream>
#include <cmath>

double getDist(int x, int y, int t_x, int t_y){
	return sqrt(pow((x-t_x),2)+pow((y-t_y),2));
}
int main(){
	int T=0;
	std::cin>>T;
	// initialize answer array
	int answer[T]={0,};
	for(int i=0 ; i<T ; i++){
		// loop for test case
		int count = 0; 
		int startx, starty, endx, endy;
		std::cin>>startx>>starty>>endx>>endy;
		//std::cout<<"start_x: "<<startx<<" start_y: "<<starty<<" end_x: "<<endx<<" end_y: "<<endy;
		int N;
		std::cin>>N;
		int c_x, c_y, r;
		for(int j=0 ; j<N ; j++){
			std::cin>>c_x>>c_y>>r;
			double s_dist = getDist(startx, starty, c_x, c_y);
			double e_dist = getDist(endx, endy, c_x, c_y);
			if (s_dist<r && e_dist <r)
				;
			else if(s_dist<r)
				count++;
			else if(e_dist<r)
				count++;
		}
		answer[i]=count;

	}
	for(int elem: answer)
		std::cout<<elem<<std::endl;
	return 0;
}
