#include <iostream>
#include <queue>
#include <set>

#define MAX 1000000

using namespace std;

int main (void){
    int start, target;
    queue<pair<int,int>> q;
    cin >> start >> target;

    int visited[MAX]={0,};
    pair<int, int> root = make_pair(start, 0);

    q.push(root);
    visited[start]=1;
    int data, level;
    while(!q.empty()){

        data=q.front().first;
        level=q.front().second;

        q.pop();
        

        if (data == target){
            cout << level;
            return 0;
        }
        if((data*2) <= MAX && !visited[data*2]){
            visited[data*2] = 1;
            q.push(make_pair(data*2,level+1));
        }
        
        if((data+1) <= MAX && !visited[data+1]){
            visited[data+1] = 1;
            q.push(make_pair(data+1,level+1));
        }
        if((data-1)>=0 && !visited[data-1]){
            visited[data-1]=1;
            q.push(make_pair(data-1,level+1));
        }

    }
}