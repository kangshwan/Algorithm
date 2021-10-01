#include<iostream>
#include<string>

using namespace std;

int main(){
    string sentence;
    getline(cin, sentence);
    int count = 0;
//    cout << sentence;
    for(int i = 0 ; i < sentence.length() ; i++){
        if(sentence[i] == ' ')
            count++;
    }
//    cout << sentence.length();
    if(sentence[0] == ' ' and sentence[sentence.length()-1] == ' '){
        cout << --count;
        return 0;
    }else if(sentence[0] == ' ' or sentence[sentence.length()-1] == ' '){
        cout << count;
        return 0;
    }else{
        cout << ++count;
        return 0;
    }
}
