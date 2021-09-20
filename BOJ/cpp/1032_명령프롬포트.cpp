#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
    cin >> n;
    string file_name;
    cin >> file_name;
    string answer = file_name;
    for(int i = 1 ; i < n ; i++){
        string next_file_name;
        cin >> next_file_name;
        for(int idx = 0 ; idx < file_name.size() ; idx++){
            if(file_name[idx] != next_file_name[idx]){
                answer[idx]='?';
            }
        }
        
    }
    cout << answer;
}