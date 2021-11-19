#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int n;

/* 
checkCompatible returns classroom number
if not compatible, then return -1
*/ 
int checkCompatible(pair<int, int> lecture, vector<vector<pair<int, int> > > classrooms){
	int n_room = -1;
	int ls, lf; // lecture start, lecture end;
	tie(ls, lf) = lecture;
	// check every classrooms to find compatible classroom
	for(int i = 0 ; i < classrooms.size() ; i++){
		bool compatible = true;
		vector<pair<int, int> > classroom = classrooms[i];
		
		for(int j = 0 ; j < classroom.size() ; j++){
			int s, f;
			tie(s,f) = classroom[j];
			if( (s < ls && ls < f) || (s < lf && ls < f))
				compatible = false;
		}
		if(compatible)
			return i;
	}
	return n_room;
}
int main(){
	//input: # of lectures.
	cin >> n;
	vector<pair<int, int> > lectures;
	vector<vector<pair<int, int> > > classrooms;
	
	for(int i = 0 ; i < n ; i++){
		int s, f;
		cin >> s >> f;
		lectures.push_back(make_pair(s,f));
	}
	sort(lectures.begin(), lectures.end());
	int n_class = 0;
	
	for(int j = 0 ; j < n ; j++){
		
		pair<int, int> lecture = lectures[j];
		
		// check every classrooms the lecture is compatible
		int compatible = checkCompatible(lecture, classrooms);
		
		if(compatible < 0){
			// if lecture is not compatible
			vector<pair<int, int> > classroom;
			classroom.push_back(lecture);
			classrooms.push_back(classroom);
			n_class++;
		}
		else{
			classrooms[compatible].push_back(lecture);
		}
	}
	
	for(int i = 0 ; i < n_class ; i++){
		cout << "Classroom "<< i <<": ";
		vector<pair<int, int> > classroom = classrooms[i];
		
		for(int j = 0 ; j < classroom.size() ; j++){
			int s, f;
			tie(s,f) = classroom[j];
			printf("[%d, %d] ", s, f);
		}
		cout << endl;
	}
}
/*
Example
10
0 3
0 3
0 7
4 7
4 10
8 11
8 11
10 15
12 15
12 15
*/
