#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int main(){
	int N;
	printf("Enter # of lectures: ");
	cin >> N;
	vector<tuple<int, int, int> > lectures(N+1);
	for(int i = 1 ; i <= N ; i++){
		int s,f,w;
		cin >> s >> f >> w;
		lectures[i]=make_tuple(s,f,w);
	}
	sort(lectures.begin(), lectures.end(), [](tuple<int,int,int> &left, tuple<int,int,int> & right){
											return get<1>(left) < get<1>(right);});
	
	printf("====sorted lectures====\ns\tf\tw\n");
	for(int i = 1 ; i <= N ; i++){
		int s,f,w; 
		tie(s,f,w) = lectures[i];
		printf("%d\t%d\t%d\n",s,f,w);
	}
	vector<int> p(N+1); 
	/* 
	p is previous lecture in time i
	ex) 
   	p[0]: previous lecture in time 0 
   		-->lectures[0]'s previous lecture is available? No -->> 0 (nothing)
   	p[1] : previous lecture in time 1 
   		--> lectures[1]'s previous lecture is available? No -->> 0 (nothing)
   	p[2] : previous lecture in time 2 
   		--> lectures[1]'s previous lecture is available? No -->> 0 (nothing)
  	p[3] : previous lecture in time 3 
  		--> lectures[2]'s previous lecture is available? Yes -->> 1 (lecture 1 is available)
   	p[4] : previous lecture in time 4 
   		--> lectures[3]'s previous lecture is available? Yes -->> 3 (lecture 3 is available)
   	p[5] : previous lecture in time 5 
 	  	--> lectures[4]'s previous lecture is available? Yes -->> 3 (lecture 3 is available)
	*/
	p[0] = 0;
	for(int i = 1 ; i <= N ; i++){
		bool found = false;
		int curS, curF, curW; // choosen lecture's start, finish, weight values
		tie(curS, curF, curW) = lectures[i];
		//find prev lectures
		for(int j = i ; j >= 0 ; j--){
			int prevS, prevF, prevW; // previous lecture's start, finish, weight values
			tie(prevS, prevF, prevW) = lectures[j];
			if(prevF < curS){
				p[i] = j;
				found = true;
				break;
			}
		}
		if(!found)
			p[i]=0;
	}
	printf("====================p====================\n");
	for(int i = 0 ; i <= N ; i++){
		printf("p[%d]\t",i);
	}
	printf("\n");
	for(int i = 0 ; i <= N ; i++){
		printf("%d\t",p[i]);
	}
	vector<int> T(N+1);
	/*
	T[i] means max Weight in time i
	T[0] = 0
	T[1] = max Weight in time 1(when time in fin(1) ) , fin(1) : lectures[1]'s finish time
	T[1] = max(T[0], T[p[1]]+w(1)) = max(0, 0+5) = 5 , w(1) : lectures[1]'s weight
	*/
	T[0] = 0;
	for(int i = 1 ; i <= N ; i++){
		T[i] = max(T[i-1], T[p[i]]+get<2>(lectures[i]));
	}
	printf("\n====================T====================\n");
	for(int i = 0 ; i <= N ; i++){
		printf("T[%d]\t",i);
	}
	printf("\n");
	for(int i = 0 ; i <= N ; i++){
		printf("%d\t",T[i]);
	}
	printf("\nMaximum weight: %d",T[N]);
}

/*
Example 0
5
1 3 5
2 5 15
4 8 20
12 13 3
10 15 1

//unsorted version of example 0
Example 1
5
1 3 5
12 13 3
4 8 20
2 5 15
10 15 1

Example 2
8
1 3 1
2 6 2
5 8 3
7 10 4
11 12 5
9 13 6
4 14 7
5 15 8

//unsorted version of example 2
Example 3
8
7 10 4
1 3 1
2 6 2
5 15 8
11 12 5
9 13 6
4 14 7
5 8 3


*/
